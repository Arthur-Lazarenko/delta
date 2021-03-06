//--************************************************************************--//

#include <System.hpp>

#pragma hdrstop
#pragma package(smart_init)

#include "TTCPReadSocketThread.h"

#include <vcl.h>

//--************************************************************************--//

__fastcall TTCPReadSocketThread::TTCPReadSocketThread(TIdTCPClient *TCPClient, MHandlers *Handlers, UnicodeString Key, TStringList *Logs)
	: TThread(false),
	  tcp_client(TCPClient),
	  handlers(Handlers),
	  name_search(Key),
	  logs(Logs)
{
};

//--************************************************************************--//

void __fastcall TTCPReadSocketThread::Execute()
{
	//-- ��������� ������ ��� ��������� ��������� �� ������� --//
	for(;!Terminated;)
	{
		try
		{
			//-- ����������� ������ ���������� �� ������� --//
			UnicodeString message_from_server = tcp_client->Socket->ReadLn(message_from_server, tcp_client->ReadTimeout, 10000000);


			//-- �������� �� ��������� ��������� �� ������� --//
			if(!message_from_server.IsEmpty())
			{
				//-- ������� ������ �� ������� --//
				json_object_parse.reset( dynamic_cast<TJSONObject*>(TJSONObject::ParseJSONValue(message_from_server)) );


				//-- ������ � ��� ���� --//

                //-- ������� �����, ���� ��������� --//
				if(logs->Count >= 5000)
					logs->Clear();

				if(json_object_parse.get())
				{
					//-- ������ � ��� ���� --//
					logs->Add( "Server: " + json_object_parse.get()->ToJSON() );
					logs->Add("----------");
				}
				else
				{
					//-- ������ ������ �������� ������ --//
					logs->Add( "Server: Error JSON data." );
					logs->Add("----------");

                    return;
				}

				//-- ����������� ���� ��������� --//
				UnicodeString type_method;

				if(json_object_parse.get()->GetValue( name_search ))
				{
					type_method = json_object_parse.get()->GetValue( name_search )->Value();

					//-- ����� ����������� ������� --//
					//-- ����� �������� --//
					MHandlers::iterator handlers_it = handlers->find( type_method );

					//-- ����� ��������, ���� ����� ���� --//
					if (handlers_it != handlers->end())
					{
						//-- ��������� ����������� � ������������� ������� --//
						handler = handlers_it->second;
						json_object = json_object_parse.get();

						//-- ��������� ������������� --//
						Synchronize(CallHandler);
					}
					else
					{
						//-- ���� ����������� ���������� --//
						MHandlers::iterator handlers_it = handlers->find( "DefaultHandlerStapLIB" );

						//-- ���� �� ������ --//
						if (handlers_it != handlers->end())
						{
							//-- ��������� ������������ ����������� � ������������� ������� --//
							handler = handlers_it->second;
							json_object = json_object_parse.get();

							//-- ��������� ������������� --//
							Synchronize(CallHandler);
						}
					}
				}
			}
		}
		catch (...)
		{}
	}
};

//--************************************************************************--//

void __fastcall TTCPReadSocketThread::CallHandler()
{
     //-- ����� ����������� --//
	 handler( json_object );
};

//--************************************************************************--//
