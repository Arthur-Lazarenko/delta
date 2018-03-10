//-----------------------------------------------------------//
//----------------- �������������� ������ -------------------//
//---------------------------(H)-----------------------------//

#ifndef MAPSIDH
#define MAPSIDH

//-- ����������� Map'�� --//
#include <map>

//-- ����������� Vector'�� --//
#include <vector>

//-- ����������� UnicodeString --//
#include <vcl.h>

//-- ��������� ��� ���������� --//
struct SSource
{
	UnicodeString name;

	UnicodeString url;

	UnicodeString dataurl;

	UnicodeString getter;

	UnicodeString enabled;

    UnicodeString notes;
};

//-- ��������� ��� ����� --//
struct SCurrency
{
	UnicodeString name;

	UnicodeString shortn;

	UnicodeString fee;

	UnicodeString minSum;

	UnicodeString base;

	UnicodeString enabled;

	UnicodeString notes;
};

//-- ��������� ��� ����� --//
struct SLine
{
	UnicodeString name;

	std::vector<int> sources;

	std::vector<int> �urrencys;

	std::vector<int> bases;

	UnicodeString enabled;

	UnicodeString notes;
};

//-- ��������� ��� ���������� --//
struct SParam
{
	UnicodeString factor;

	UnicodeString maxChainLen;
};

//-- ��������� ��� ��������� --//
struct SCorrection
{
	UnicodeString sourceId;

	UnicodeString currOut;

	UnicodeString currIn;

	UnicodeString fee;

	UnicodeString enabled;

	UnicodeString notes;
};


//-- ��������� ��� ��������� --//

struct SOperation
{
	UnicodeString currOut;

	UnicodeString currIn;

	UnicodeString idSource;

	UnicodeString rate;

	UnicodeString realRate;

	UnicodeString amount;
};

struct SArbitration
{
	UnicodeString factor;

	UnicodeString line;

	UnicodeString relevance;

	UnicodeString time;


	std::vector< SOperation > operations;
};



//-- ���������� ���� ��������������� ��� ���������������� ���� Source --//
typedef std::map< unsigned int, SSource > MSource;

//-- ���������� ���� ��������������� ��� ���������������� ���� Currency --//
typedef std::map< unsigned int, SCurrency > MCurrency;

//-- ���������� ���� ��������������� ��� ���������������� ���� Line --//
typedef std::map< unsigned int, SLine > MLine;

//-- ���������� ���� ��������������� ��� ���������������� ���� Correction --//
typedef std::map< unsigned int, SCorrection > MCorrection;

//-- ���������� ���� ��������������� ��� ���������������� ���� Arbitration --//
typedef std::map< unsigned int, SArbitration > MArbitration;

//-- ���������� ���� ��������������� ��� ���������������� ���� Collection --//
typedef std::map< unsigned int, UnicodeString > MCollection;



//-- ���������� ��������� ������ --//
struct SData
{
	//-- �������� ��������������� ���������� --//
	MSource map_sources;

	//-- �������� ��������������� ����� --//
	MCurrency map_currencys;

	//-- �������� ��������������� ����� --//
	MLine map_lines;

	//-- �������� ��������������� ��������� --//
	MCorrection map_corrections;

    //-- �������� ��������������� ��������� --//
	MArbitration map_arbitrations;

	//-- �������� ���������� ������������ --//
	SParam params;

    MCollection map_collections;
};


#endif
