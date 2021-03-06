//-- ******************************************* --//
//-- ****************** Lines ****************** --//
//-- ******************************************* --//

#ifndef LINESH
#define LINESH

//-- ����������� ��������������� ������ --//
#include <MapsID.h>


//-- ����������� JSON --//
#include <System.JSON.hpp>

#include "MainForm_Delta.h"


namespace HandlersNS
{


	//-- �������-���������� ��������� ����� --//
	void getLines(TJSONObject *json_object_parse);

	//-- �������-���������� ���������� ���������� ����� --//
	void CheckAddLine(TJSONObject *json_object_parse);

	//-- �������-���������� ���������� ��������� ����� --//
	void CheckEditLine(TJSONObject *json_object_parse);

	//-- �������-���������� ���������� �������� ����� --//
	void CheckDeleteLine(TJSONObject *json_object_parse);

	//-- �������-���������� ��������� ����� --//
	void editLine(TJSONObject *json_object_parse);

	//-- �������-���������� ���������� ����� --//
	void addLine(TJSONObject *json_object_parse);

	//-- �������-���������� �������� ����� --//
	void deleteLine(TJSONObject *json_object_parse);


}



#endif
