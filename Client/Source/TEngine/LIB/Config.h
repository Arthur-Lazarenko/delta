  //-----------------------------------------------------------//
  //-------------------------- ���� ---------------------------//
  //---------------------------(H)-----------------------------//

#ifndef CONFIGH
#define CONFIGH

//-- ����������� ����� ���������� --//
#include "SortTypes.h"

struct SConfig
{
	//-- �������� ������� ������� ����� --//
	unsigned int MainFormWidth = 1000;
	unsigned int MainFormHeight = 600;

	//-- �������� ����������� ��������� --//
	bool TrayMinimize = false;

	//-- �������� ��������� ����������� --//
	bool NotificationsHint = false;

	//-- �������� ���� --//
	bool Theme = true;

	//-- �������� ���������� ���������� ������ --//
	unsigned int LastCollectedDD = 00;

	unsigned int LastCollectedMM = 00;

	unsigned int LastCollectedYY = 00;

	unsigned int LastCollectedHH = 00;

	unsigned int LastCollectedNN = 00;

	unsigned int LastCollectedSS = 00;

	unsigned int LastTimeOnCollect = 0;

	//-- ���� ������� --//
	UnicodeString HostServer = "finlab.akite.org";

	//-- ���� ������� --//
	unsigned int PortServer = 82;

	//-- ����� ��� ����������� �� ������� --//
	UnicodeString LoginServer;

	//-- ������ ��� ����������� �� ������� --//
	UnicodeString PasswordServer;

	//-- ��������� �������� ���������� --//
	unsigned int SortSources = eID;
	bool SortSourcesInd = true;

	unsigned int SortCurrencys = eID;
	bool SortCurrencysInd = true;

	unsigned int SortLines = eID;
	bool SortLinesInd = true;

	unsigned int SortCorrections = eID;
	bool SortCorrectionsInd = true;

	unsigned int SortArbitrations = eFACTOR;
	bool SortArbitrationsInd = true;

	//-- ��������� ������������� ������ �������� --//
	float SourcesCol_0 = 0.05;
	float SourcesCol_1 = 0.15;
	float SourcesCol_2 = 0.20;
	float SourcesCol_3 = 0.20;
	float SourcesCol_4 = 0.10;
	float SourcesCol_5 = 0.10;
	float SourcesCol_6 = 0.20;

	float CurrencysCol_0 = 0.05;
	float CurrencysCol_1 = 0.15;
	float CurrencysCol_2 = 0.10;
	float CurrencysCol_3 = 0.08;
	float CurrencysCol_4 = 0.10;
	float CurrencysCol_5 = 0.06;
	float CurrencysCol_6 = 0.10;
	float CurrencysCol_7 = 0.35;

	float LinesNamesCol_0 = 0.20;
	float LinesNamesCol_1 = 0.50;
	float LinesNamesCol_2 = 0.30;

	float CorrectionsCol_0 = 0.05;
	float CorrectionsCol_1 = 0.15;
	float CorrectionsCol_2 = 0.15;
	float CorrectionsCol_3 = 0.15;
	float CorrectionsCol_4 = 0.10;
	float CorrectionsCol_5 = 0.09;
	float CorrectionsCol_6 = 0.32;

	float ArbitrationsCol_0 = 0.00;
	float ArbitrationsCol_1 = 0.08;
	float ArbitrationsCol_2 = 0.10;
	float ArbitrationsCol_3 = 0.12;
	float ArbitrationsCol_4 = 0.12;
	float ArbitrationsCol_5 = 0.12;
	float ArbitrationsCol_6 = 0.16;
	float ArbitrationsCol_7 = 0.07;
	float ArbitrationsCol_8 = 0.07;
	float ArbitrationsCol_9 = 0.07;
	float ArbitrationsCol_10 = 0.08;



};

#endif
