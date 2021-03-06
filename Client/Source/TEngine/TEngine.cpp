  //-----------------------------------------------------------//
  //-------------------- ������ ��������� ---------------------//
  //--------------------------(CPP)----------------------------//

//-- ����������� ������������� ����� --//
#include "TEngine.h"

namespace TEngineNS
{

	//-- ����������� ����������� --//
	TEngine::TEngine()
	:   TStapLIBNS::TStapLIB(),
		way_to_config_file("files\\"),
		name_config_file("config.ini"),
		need_to_restart(false),
		encoder64(new TIdEncoderMIME),
        decoder64(new TIdDecoderMIME)
	{
	}

	//-- ����������� ���������� --//
	TEngine::~TEngine()
	{
	}


    //-- ������� ������������� ����������� ��� ������ �������� ����������� ������ --//
	bool TEngine::NeedToRestart() const
	{
		return need_to_restart;
    }

    //-- �������� ���������� ��������� --//
	void TEngine::LoadConfig()
	{
		//-- ��������� ������������� ����� ������������ --//
		bool file_exist = true;

		//-- �������� �� ������� ����� ������������ --//
		if(!FileExists( way_to_config_file + name_config_file))
		{
            file_exist = false;

			//-- ���� ����� ������������ ���, ������ ��� --//

			MkDir( way_to_config_file );
			FileCreate( way_to_config_file + name_config_file );
		}

		//-- ������� ���� �������������� ����� --//
		ini_config.reset(new TIniFile ( way_to_config_file + name_config_file ));

		//-- ���� ���� ����������  --//
		if(file_exist)
		{
			//-- ���������� ������������ �� ����� --//

			//-- �������� ������� ������� ����� --//
			config.MainFormWidth = ini_config.get()->ReadInteger("Interface", "MainFormWidth", config.MainFormWidth);
            config.MainFormHeight = ini_config.get()->ReadInteger("Interface", "MainFormHeight", config.MainFormHeight);

			//-- �������� ��������� ����������� --//
			config.NotificationsHint = ini_config.get()->ReadBool("Interface", "NotificationsHint", config.NotificationsHint);

			//-- �������� ���������� ��������� --//
			config.TrayMinimize = ini_config.get()->ReadBool("Interface", "TrayMinimize", config.TrayMinimize);

			//-- �������� ���� --//
			config.Theme = ini_config.get()->ReadBool("Interface", "Theme", config.Theme);

			//-- �������� ���������� ���������� ������ --//
			config.LastCollectedDD = ini_config.get()->ReadInteger("LastCollected", "DD", config.LastCollectedDD);

			config.LastCollectedMM = ini_config.get()->ReadInteger("LastCollected", "MM", config.LastCollectedMM);

			config.LastCollectedYY = ini_config.get()->ReadInteger("LastCollected", "YY", config.LastCollectedYY);

			config.LastCollectedHH = ini_config.get()->ReadInteger("LastCollected", "HH", config.LastCollectedHH);

			config.LastCollectedNN = ini_config.get()->ReadInteger("LastCollected", "NN", config.LastCollectedNN);

			config.LastCollectedSS = ini_config.get()->ReadInteger("LastCollected", "SS", config.LastCollectedSS);

			config.LastTimeOnCollect = ini_config.get()->ReadInteger("LastCollected", "LastTimeOnCollect", config.LastTimeOnCollect);

			//-- �������� ����� ������� --//
			config.HostServer = ini_config.get()->ReadString("Server", "Host", config.HostServer);

			//-- �������� ����� ������� --//
			config.PortServer = ini_config.get()->ReadInteger("Server", "Port", config.PortServer) ;

			//-- �������� ������ --//
			config.LoginServer = ini_config.get()->ReadString( "Auth", "Login", config.LoginServer);

			//-- �������� ������ --//
			config.PasswordServer = decoder64.get()->DecodeString(ini_config.get()->ReadString("Auth", "Password", config.PasswordServer), IndyTextEncoding_UTF8() );

			config.PasswordServer = XOR_Crypt(config.PasswordServer, "8hfwn8newf8nm298um8un23mfmuwen8fmm28fmu8n8m2fuimn283f8m8wmuf8");

			//-- ��������� �������� ���������� --//
			config.SortSources = ini_config.get()->ReadInteger("ParamSort", "SortSources", config.SortSources);
			config.SortSourcesInd = ini_config.get()->ReadBool("ParamSort", "SortSourcesInd", config.SortSourcesInd);

			config.SortCurrencys = ini_config.get()->ReadInteger("ParamSort", "SortCurrencys", config.SortCurrencys);
			config.SortCurrencysInd = ini_config.get()->ReadBool("ParamSort", "SortCurrencysInd", config.SortCurrencysInd);

			config.SortLines = ini_config.get()->ReadInteger("ParamSort", "SortLines", config.SortLines);
			config.SortLinesInd = ini_config.get()->ReadBool("ParamSort", "SortLinesInd", config.SortLinesInd);

			config.SortCorrections = ini_config.get()->ReadInteger("ParamSort", "SortCorrections", config.SortCorrections);
			config.SortCorrectionsInd = ini_config.get()->ReadBool("ParamSort", "SortCorrectionsInd", config.SortCorrectionsInd);

			config.SortArbitrations = ini_config.get()->ReadInteger("ParamSort", "SortArbitrations", config.SortArbitrations);
			config.SortArbitrationsInd = ini_config.get()->ReadBool("ParamSort", "SortArbitrationsInd", config.SortArbitrationsInd);

            //-- ��������� ������������� ������ �������� --//
			config.SourcesCol_0 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_0", config.SourcesCol_0);
			config.SourcesCol_1 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_1", config.SourcesCol_1);
			config.SourcesCol_2 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_2", config.SourcesCol_2);
			config.SourcesCol_3 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_3", config.SourcesCol_3);
			config.SourcesCol_4 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_4", config.SourcesCol_4);
			config.SourcesCol_5 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_5", config.SourcesCol_5);
			config.SourcesCol_6 = ini_config.get()->ReadFloat("ParamWidth", "SourcesCol_6", config.SourcesCol_6);

			config.CurrencysCol_0 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_0", config.CurrencysCol_0);
			config.CurrencysCol_1 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_1", config.CurrencysCol_1);
			config.CurrencysCol_2 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_2", config.CurrencysCol_2);
			config.CurrencysCol_3 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_3", config.CurrencysCol_3);
			config.CurrencysCol_4 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_4", config.CurrencysCol_4);
			config.CurrencysCol_5 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_5", config.CurrencysCol_5);
			config.CurrencysCol_6 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_6", config.CurrencysCol_6);
			config.CurrencysCol_7 = ini_config.get()->ReadFloat("ParamWidth", "CurrencysCol_7", config.CurrencysCol_7);

			config.LinesNamesCol_0 = ini_config.get()->ReadFloat("ParamWidth", "LinesNamesCol_0", config.LinesNamesCol_0);
			config.LinesNamesCol_1 = ini_config.get()->ReadFloat("ParamWidth", "LinesNamesCol_1", config.LinesNamesCol_1);
			config.LinesNamesCol_2 = ini_config.get()->ReadFloat("ParamWidth", "LinesNamesCol_2", config.LinesNamesCol_2);

            config.CorrectionsCol_0 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_0", config.CorrectionsCol_0);
			config.CorrectionsCol_1 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_1", config.CorrectionsCol_1);
			config.CorrectionsCol_2 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_2", config.CorrectionsCol_2);
			config.CorrectionsCol_3 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_3", config.CorrectionsCol_3);
			config.CorrectionsCol_4 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_4", config.CorrectionsCol_4);
			config.CorrectionsCol_5 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_5", config.CorrectionsCol_5);
			config.CorrectionsCol_6 = ini_config.get()->ReadFloat("ParamWidth", "CorrectionsCol_6", config.CorrectionsCol_6);

			config.ArbitrationsCol_0 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_0", config.ArbitrationsCol_0);
			config.ArbitrationsCol_1 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_1", config.ArbitrationsCol_1);
			config.ArbitrationsCol_2 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_2", config.ArbitrationsCol_2);
			config.ArbitrationsCol_3 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_3", config.ArbitrationsCol_3);
			config.ArbitrationsCol_4 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_4", config.ArbitrationsCol_4);
			config.ArbitrationsCol_5 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_5", config.ArbitrationsCol_5);
			config.ArbitrationsCol_6 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_6", config.ArbitrationsCol_6);
			config.ArbitrationsCol_7 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_7", config.ArbitrationsCol_7);
			config.ArbitrationsCol_8 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_8", config.ArbitrationsCol_8);
			config.ArbitrationsCol_9 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_9", config.ArbitrationsCol_9);
			config.ArbitrationsCol_10 = ini_config.get()->ReadFloat("ParamWidth", "ArbitrationsCol_10", config.ArbitrationsCol_10);
		}
		else
		{
			need_to_restart = true;

			throw Exception("The files have been created, please restart the program.");
		}
	}

    //-- ���������� ���������� ��������� --//
	void TEngine::SaveConfig()
	{

		//-- ������ ������������ � ���� --//

		if( ini_config.get() )
		{
            //-- �������� ������� ������� ����� --//
			ini_config.get()->WriteInteger("Interface", "MainFormWidth", config.MainFormWidth);
			ini_config.get()->WriteInteger("Interface", "MainFormHeight", config.MainFormHeight);

			//-- �������� ��������� ����������� --//
			ini_config.get()->WriteBool("Interface", "NotificationsHint", config.NotificationsHint);

			//-- �������� ����������� ��������� --//
			ini_config.get()->WriteBool("Interface", "TrayMinimize", config.TrayMinimize);

			//-- �������� ���� --//
			ini_config.get()->WriteBool("Interface", "Theme", config.Theme);

			//-- �������� ���������� ���������� ������ --//
			ini_config.get()->WriteInteger("LastCollected", "DD", config.LastCollectedDD);

			ini_config.get()->WriteInteger("LastCollected", "MM", config.LastCollectedMM);

			ini_config.get()->WriteInteger("LastCollected", "YY", config.LastCollectedYY);

			ini_config.get()->WriteInteger("LastCollected", "HH", config.LastCollectedHH);

			ini_config.get()->WriteInteger("LastCollected", "NN", config.LastCollectedNN);

			ini_config.get()->WriteInteger("LastCollected", "SS", config.LastCollectedSS);

			ini_config.get()->WriteInteger("LastCollected", "LastTimeOnCollect", config.LastTimeOnCollect);

			//-- �������� ����� ������� --//
			ini_config.get()->WriteString("Server", "Host", config.HostServer);

			//-- �������� ����� ������� --//
			ini_config.get()->WriteInteger("Server", "Port", config.PortServer);

			//-- �������� ������ --//
			ini_config.get()->WriteString("Auth", "Login", config.LoginServer );

			//-- �������� ������ --//
			config.PasswordServer = XOR_Crypt(config.PasswordServer, "8hfwn8newf8nm298um8un23mfmuwen8fmm28fmu8n8m2fuimn283f8m8wmuf8");

			ini_config.get()->WriteString("Auth", "Password", encoder64.get()->EncodeString( config.PasswordServer, IndyTextEncoding_UTF8() ));

			//-- ��������� �������� ���������� --//
			ini_config.get()->WriteInteger("ParamSort", "SortSources", config.SortSources);
			ini_config.get()->WriteBool("ParamSort", "SortSourcesInd", config.SortSourcesInd);

			ini_config.get()->WriteInteger("ParamSort", "SortCurrencys", config.SortCurrencys);
			ini_config.get()->WriteBool("ParamSort", "SortCurrencysInd", config.SortCurrencysInd);

			ini_config.get()->WriteInteger("ParamSort", "SortLines", config.SortLines);
			ini_config.get()->WriteBool("ParamSort", "SortLinesInd", config.SortLinesInd);

			ini_config.get()->WriteInteger("ParamSort", "SortCorrections", config.SortCorrections);
			ini_config.get()->WriteBool("ParamSort", "SortCorrectionsInd", config.SortCorrectionsInd);

			ini_config.get()->WriteInteger("ParamSort", "SortArbitrations", config.SortArbitrations);
			ini_config.get()->WriteBool("ParamSort", "SortArbitrationsInd", config.SortArbitrationsInd);

			//-- ��������� ������������� ������ �������� --//
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_0", config.SourcesCol_0);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_1", config.SourcesCol_1);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_2", config.SourcesCol_2);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_3", config.SourcesCol_3);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_4", config.SourcesCol_4);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_5", config.SourcesCol_5);
			ini_config.get()->WriteFloat("ParamWidth", "SourcesCol_6", config.SourcesCol_6);

			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_0", config.CurrencysCol_0);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_1", config.CurrencysCol_1);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_2", config.CurrencysCol_2);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_3", config.CurrencysCol_3);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_4", config.CurrencysCol_4);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_5", config.CurrencysCol_5);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_6", config.CurrencysCol_6);
			ini_config.get()->WriteFloat("ParamWidth", "CurrencysCol_7", config.CurrencysCol_7);

			ini_config.get()->WriteFloat("ParamWidth", "LinesNamesCol_0", config.LinesNamesCol_0);
			ini_config.get()->WriteFloat("ParamWidth", "LinesNamesCol_1", config.LinesNamesCol_1);
			ini_config.get()->WriteFloat("ParamWidth", "LinesNamesCol_2", config.LinesNamesCol_2);

            ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_0", config.CorrectionsCol_0);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_1", config.CorrectionsCol_1);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_2", config.CorrectionsCol_2);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_3", config.CorrectionsCol_3);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_4", config.CorrectionsCol_4);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_5", config.CorrectionsCol_5);
			ini_config.get()->WriteFloat("ParamWidth", "CorrectionsCol_6", config.CorrectionsCol_6);

			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_0", config.ArbitrationsCol_0);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_1", config.ArbitrationsCol_1);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_2", config.ArbitrationsCol_2);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_3", config.ArbitrationsCol_3);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_4", config.ArbitrationsCol_4);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_5", config.ArbitrationsCol_5);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_6", config.ArbitrationsCol_6);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_7", config.ArbitrationsCol_7);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_8", config.ArbitrationsCol_8);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_9", config.ArbitrationsCol_9);
			ini_config.get()->WriteFloat("ParamWidth", "ArbitrationsCol_10", config.ArbitrationsCol_10);
		}
	}

    //-- ���������/����������� ������ --//
	UnicodeString TEngine::XOR_Crypt(UnicodeString In, UnicodeString Pass) const
	{
		UnicodeString out;
		for (int i=1; i != In.Length()+1; i ++)
		{
			out = out + (char)(In[i] ^ Pass[ i%Pass.Length()+1 ]);
		}

		return out;
	}

    //-- ������� ������������ ��������� --//
	SConfig* TEngine::Config()
	{
		return &config;
	}

    //-- ������� ��������������� �������� ������ � ������� � �������� ������ � ������ --//
	UnicodeString TEngine::FloatWithDots(const UnicodeString FloatNum) const
	{
		UnicodeString Num = FloatNum;

		return StringReplace(Num, ",", ".", TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
	}

};