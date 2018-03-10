//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "TestForm_Delta.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTestForm *TestForm;
//---------------------------------------------------------------------------
__fastcall TTestForm::TTestForm(TComponent* Owner)
	: TForm(Owner)
{
}



//---------------------------------------------------------//
//------------ ����������� ����������� ������� ------------//
//---------------------------------------------------------//

//-- ���������� ������ ����� --//
void __fastcall TTestForm::FormShow(TObject *Sender)
{
	//-- ��������� ������������ ����������� �������� ����� --//
	MainForm->engine.get()->SetDefaultHandler(TestForm_HandlerTest);

	//-- ����� ���������� ������ � ����������� �� ����������� --//
	if(MainForm->engine->ConnectState())
		SetElementConnect();
	else
		SetElementDisconnect();
}

//-- ���������� �������� ����� --//
void __fastcall TTestForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	//-- �������� ������������ ����������� �������� ����� --//
	MainForm->engine.get()->DelDefaultHandler();
}




//---------------------------------------------------------//
//------------- ����������� ������� ��������� -------------//
//---------------------------------------------------------//

//-- ���������� �� ������� �� ������� "Send" --//
void __fastcall TTestForm::SendButton_OneClick(TObject *Sender)
{
	if(MethodEdit->Text.IsEmpty())
		ShowMessage("Line method is not filled.");
	else
	{
		//-- ���������� �������� ������ --//
		if(!ParamMemo->Text.IsEmpty())
			MainForm->engine.get()->Send(MethodEdit->Text, ParamMemo->Lines->Text, "Test");
		else
			MainForm->engine.get()->Send(MethodEdit->Text, "Test");
	}
}


//-- ���������� �� ������� �� ������� "ToBase64" --//
void __fastcall TTestForm::ToBase64Button_OneClick(TObject *Sender)
{
	FromBase64Edit->Clear();

	if(!ToBase64Edit->Text.IsEmpty())
	{
		FromBase64Edit->Text = MainForm->Encoder->EncodeString( ToBase64Edit->Text, IndyTextEncoding_UTF8() );
	}
}


//-- ���������� �� ������� �� ������� "FromBase64" --//
void __fastcall TTestForm::FromBase64Button_OneClick(TObject *Sender)
{
	ToBase64Edit->Clear();

	if(!FromBase64Edit->Text.IsEmpty())
	{
		ToBase64Edit->Text = MainForm->Decoder->DecodeString( FromBase64Edit->Text, IndyTextEncoding_UTF8() );
	}
}





//---------------------------------------------------------//
//------------- �������������� ������� ������ -------------//
//---------------------------------------------------------//

//-- ������� ��������� ��������� ����� � ������������ ������ --//
void TTestForm::SetElementConnect()
{
	SendButton->Enabled = true;
}

//-- ������� ��������� ��������� ����� � ����������� ������ --//
void TTestForm::SetElementDisconnect()
{
	SendButton->Enabled = false;
}




//---------------------------------------------------------//
//------------ ���������� ����������� ������� -------------//
//---------------------------------------------------------//

//-- ���������� �������� ����� --//
void TestForm_HandlerTest(TJSONObject *json_object_parse)
{
	TestForm->AnswerMemo->Lines->Add( json_object_parse->ToJSON() );
	TestForm->AnswerMemo->Lines->Add( "----------" );
}



