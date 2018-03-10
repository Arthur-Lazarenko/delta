//---------------------------------------------------------------------------

#ifndef EditForm_Lines_DeltaH
#define EditForm_Lines_DeltaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.CheckLst.hpp>

#include "MainForm_Delta.h"


//---------------------------------------------------------------------------
class TEditFormLines : public TForm
{
__published:
	TStaticText *NameStatic;
	TEdit *NameEdit;
	TCheckListBox *CurrencysCheckList;
	TStaticText *SourcesStatic;
	TStaticText *CurrencysStatic;
	TCheckListBox *SourcesCheckList;
	TButton *SaveButton;
	TStaticText *EnabledStatic;
	TCheckBox *EnabledCheck;
	TStaticText *NotesStatic;
	TMemo *NotesMemo;
	TCheckBox *AllSourcesCheck;
	TCheckBox *AllCurrencysCheck;
	TCheckListBox *BasesCheckList;
	TStaticText *BasesStatic;
	TCheckBox *AllBasesCheck;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall SaveButton_OneClick(TObject *Sender);
	void __fastcall AllSourcesCheck_OneClick(TObject *Sender);
	void __fastcall AllCurrencysCheck_OneClick(TObject *Sender);
	void __fastcall CurrencysCheckListClickCheck(TObject *Sender);
	void __fastcall AllBasesCheck_OneClick(TObject *Sender);

private:

    //-- ������� ���������� ������� ����� ��� ����������� �� ������ --//
    void UpdateBaseCurrencys();

public:

	__fastcall TEditFormLines(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TEditFormLines *EditFormLines;
//---------------------------------------------------------------------------
#endif
