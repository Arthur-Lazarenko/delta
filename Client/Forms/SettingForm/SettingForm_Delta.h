//---------------------------------------------------------------------------

#ifndef SettingForm_DeltaH
#define SettingForm_DeltaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Graphics.hpp>

#include "MainForm_Delta.h"

//---------------------------------------------------------------------------
class TSettingForm : public TForm
{
__published:

	TButton *SaveButton;
	TEdit *HostEdit;
	TEdit *PortEdit;
	TStaticText *HostStatic;
	TStaticText *PortStatic;
	TStaticText *TrayNotificationStatic;
	TCheckBox *TrayMinimizeCheck;
	TStaticText *ThemeStatic;
	TRadioButton *ThemeWhiteRadioButton;
	TRadioButton *ThemeBlackRadioButton;
	TImage *LogoImage;
	TImage *MinimizeImage;
	TImage *ThemeImage;
	TImage *NotificationsImage;
	TStaticText *NotificationsStatic;
	TCheckBox *NotificationsCheck;
	void __fastcall SaveButton_OneClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:


public:

	__fastcall TSettingForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TSettingForm *SettingForm;
//---------------------------------------------------------------------------
#endif
