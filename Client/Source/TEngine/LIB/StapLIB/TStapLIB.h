//-----------------------------------------------------------//
//------------------------- StapLIB -------------------------//
//---------------------------(H)-----------------------------//

#ifndef TStapLIBH
#define TStapLIBH

//-- ����������� Indy TCP Client --//
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>

//-- ����������� ���������������� ���������� --//
#include <memory>

//-- ����������� MAP --//
#include <map>

//-- ����������� TCPSocketThread --//
#include "TTCPReadSocketThread.h"

//-- ����������� JSON --//
#include <System.JSON.hpp>


typedef void (*FHandler)(TJSONObject*);
typedef std::map< UnicodeString, FHandler > MHandlers;

namespace TStapLIBNS
{

	class TStapLIB
	{

	private:

		//-- map ������������ ������� --//
		MHandlers handlers;

		//-- ��� ����� ��� ������ ������ �� ������� --//
		UnicodeString name_search;

		//-- ���� �����--//
		std::shared_ptr< TStringList > logs;

		//-- �������� TCPClient-� --//
		std::shared_ptr< TIdTCPClient > tcp_client;

		//-- �������� ������ ��������� ������� �� ������� --//
		std::shared_ptr < TTCPReadSocketThread > tcp_read_client_thread;


	public:

		//-- ����������� ����������� --//
		TStapLIB();

		//-- ����������� ���������� --//
		~TStapLIB();

		//-- ������� ����������� � ������� --//
		void Connecting(const UnicodeString Host,const unsigned int Port );

		//-- ������� �������� ��������� ���������� --//
		bool ConnectState() const;

		//-- ������� ���������� �� ������� --//
		void Disconnect();

		//-- ������� ��������� ���������� ����� ������ --//
		void SetSearchKey(const UnicodeString Key);

		//-- ������� ��������� ����������� --//
		void SetHandler(const UnicodeString Name, FHandler Handler);

		//-- ������� ��������� ������������ ����������� --//
		void SetDefaultHandler(FHandler Handler);

		//-- ������� �������� ���� ������������ --//
		void DelHandler();

		//-- ������� �������� ����������� �� ����� --//
		void DelHandler(const UnicodeString Name);

		//-- ������� �������� ������������ ����������� --//
		void DelDefaultHandler();

		//-- ������� �������� ��������� �� ������ --//
		void Send(const UnicodeString Name, const UnicodeString CallBack);

		//-- ������� �������� ��������� �� ������ c ���������� --//
		void Send(const UnicodeString Name, const UnicodeString Param , const UnicodeString CallBack);

		//-- ������� �������� ����� --//
		UnicodeString GetLogs();

	};

};

#endif
