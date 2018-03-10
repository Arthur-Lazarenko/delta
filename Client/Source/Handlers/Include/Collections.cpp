//-- ******************************************* --//
//-- *************** Collections *************** --//
//-- ******************************************* --//

#include <vcl.h>

//-- ����������� ������������� ����� --//
#include "Collections.h"



namespace HandlersNS
{



	//-- �������-���������� ������ ����� ������ --//
	void collect(TJSONObject *json_object_parse)
	{
        //-- ������� ������ ���������� � ��������� ������ --//
		MainForm->engine->Data()->map_collections.clear();

		//-- ������ ������� ������ ����� ������ --//
		MainForm->time_collect.StartCollectDD = FormatDateTime("dd", Now()).ToInt();
		MainForm->time_collect.StartCollectMM = FormatDateTime("mm", Now()).ToInt();
		MainForm->time_collect.StartCollectYY = FormatDateTime("yy", Now()).ToInt();
		MainForm->time_collect.StartCollectHH = FormatDateTime("hh", Now()).ToInt();
		MainForm->time_collect.StartCollectNN = FormatDateTime("nn", Now()).ToInt();
		MainForm->time_collect.StartCollectSS = FormatDateTime("ss", Now()).ToInt();
	}

	//-- �������-���������� ����� ����� ������ --//
	void collected(TJSONObject *json_object_parse)
	{
		//-- ������ ������� ����� ����� ������ --//
		MainForm->time_collect.EndCollectDD = FormatDateTime("dd", Now()).ToInt();
		MainForm->time_collect.EndCollectMM = FormatDateTime("mm", Now()).ToInt();
		MainForm->time_collect.EndCollectYY = FormatDateTime("yy", Now()).ToInt();
		MainForm->time_collect.EndCollectHH = FormatDateTime("hh", Now()).ToInt();
		MainForm->time_collect.EndCollectNN = FormatDateTime("nn", Now()).ToInt();
		MainForm->time_collect.EndCollectSS = FormatDateTime("ss", Now()).ToInt();

        //-- ���������� �������� ���������� ���������� ������ --//
		MainForm->UpdateLastCollected(true);

		//-- ���������� ������� --//
		MainForm->UpdateCollections(MainForm->Collections_StringGrid->Row, true);
	}

    //-- �������-���������� ����� ������ --//
	void processSource(TJSONObject *json_object_parse)
	{
        //-- ������ ��� ������ � JSON --//
		TJSONObject *json_object;

		//-- ��������� ������������ ��������� --//
		if(json_object_parse->Get("param"))
		{
			json_object = dynamic_cast<TJSONObject*>( json_object_parse->Get("param")->JsonValue );

            UnicodeString notes;

			//-- ����������� ���������� ����� --//
			if( json_object->GetValue("num") )
				notes = "Collected: " + json_object->GetValue("num")->Value();

			if( json_object->GetValue("error") )
				notes = MainForm->Decoder->DecodeString( json_object->GetValue("error")->Value(), IndyTextEncoding_UTF8() );



			//-- ����������� ������������� ��� ���������� ��������� --//
			if(MainForm->engine->Data()->map_collections.find( json_object->GetValue("id")->Value().ToInt() ) != MainForm->engine->Data()->map_collections.end())
			{
				//-- ��������� ������� --//
				MainForm->engine->Data()->map_collections.find( json_object->GetValue("id")->Value().ToInt() )->second = notes;
            }
			else
			{
				//-- ������ �������������� --//
				MainForm->engine->Data()->map_collections.insert( std::make_pair( json_object->GetValue("id")->Value().ToInt(), notes ));
			}
		}
    }

}


