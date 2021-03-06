//-- ******************************************* --//
//-- ****************** Params ***************** --//
//-- ******************************************* --//

#include <vcl.h>

//-- ����������� ������������� ����� --//
#include "Params.h"


#include "MainForm_Delta.h"

namespace HandlersNS
{



	//-- �������-���������� ��������� ���������� --//
	void getParams(TJSONObject *json_object_parse)
	{
		//-- ������ ��� ������ � JSON --//
		TJSONObject *json_object;

		if( json_object_parse->Get("param") )
		{
			json_object = dynamic_cast<TJSONObject*>( json_object_parse->Get("param")->JsonValue );

			if( json_object->Get("factor") )
			{
				MainForm->engine->Data()->params.factor = json_object->GetValue("factor")->Value();
			}

			if( json_object->Get("maxChainLen") )
			{
				MainForm->engine->Data()->params.maxChainLen = json_object->GetValue("maxChainLen")->Value();
			}

			//-- ���������� ���������� � ����� --//
			MainForm->UpdateParams();
		}
	}


	//-- �������-���������� ���������� ��������� ��������� --//
	void CheckEditParams(TJSONObject *json_object_parse)
	{

		//-- ������ ��� ������ � JSON --//
		TJSONObject *json_object;

		//-- ��������� ���������� ��������� ��������� --//
		json_object = dynamic_cast<TJSONObject*>( json_object_parse->Get("param")->JsonValue );

		//-- ���� ��������� ������ ������� --//
		if(json_object->GetValue("result")->Value().ToInt() == 0)
		{
			//ShowMessage("Settings updated successfully.");
		}
		else
		{
			if(json_object->GetValue("result")->Value().ToInt() == 1)
			{
				ShowMessage("Error changing parameters.");

                //-- ���������� ���������� � ����� --//
				MainForm->UpdateParams();
			}

		}
	}



	//-- �������-���������� ��������� ��������� --//
	void editParams(TJSONObject *json_object_parse)
	{
        //-- ������ ��� ������ � JSON --//
		TJSONObject *json_object;

		if( json_object_parse->Get("param") )
		{
			json_object = dynamic_cast<TJSONObject*>( json_object_parse->Get("param")->JsonValue );

			if( json_object->Get("factor") )
			{
				MainForm->engine->Data()->params.factor = json_object->GetValue("factor")->Value();
			}

			if( json_object->Get("maxChainLen") )
			{
				MainForm->engine->Data()->params.maxChainLen = json_object->GetValue("maxChainLen")->Value();
			}

			//-- ���������� ���������� � ����� --//
			MainForm->UpdateParams();
		}
	}

}



