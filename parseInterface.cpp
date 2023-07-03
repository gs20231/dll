// parseInterface.cpp : Defines the exported functions for the DLL.
//
#pragma execution_character_set("utf-8")
#include "pch.h"
#include "framework.h"
#include "parseInterface.h"
#include "VMProtectSDK.h"
#include <cstdlib>
#include <ctime>

#include<Windows.h>

#include "hklib.h"

#include <iostream>
#include <fstream>
#include "string"
#include "map"
using namespace std;
static std::map<long long int, CparseInterface*> inst_set;
long long int IT()
{
	CparseInterface* inst = new CparseInterface();
	long long int ID = (long long int)(inst);
	inst_set.insert(std::pair<long long int, CparseInterface*>(ID, inst));
	for (auto iter : inst_set)
	{
		std::cout << "IT:" << iter.first << endl;
	}
	std::cout << "IT ID:" << ID << endl;
	return ID;
}
int DIT(int64_t ID)
{
	std::cout << "DIT:" << ID << endl;
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	delete iter->second;
	inst_set.erase(iter);
}
//int dataProcess(int64_t ID)
//{
//	std::cout << "dataProcess:" << ID << endl;
//	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
//	if (iter == inst_set.end())
//	{
//		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
//		return -1;
//	}
//	
//	return iter->second->dataProcess();
//}
int SetData(int64_t ID, const float* pXData, const float* pYData, int len)
{
	for (auto iter : inst_set)
	{
		std::cout << "Set:"<<iter.first << endl;
	}
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->SetData(pXData, pYData, len);
}
int SPSET(int64_t ID, uint32_t _order, uint32_t _winLength)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->SPSET(_order, _winLength);
}
int BPV(int64_t ID, uint32_t* _bSplineVec, uint32_t _bSplineVecLen)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->BPV(_bSplineVec, _bSplineVecLen);
}
int SKP(int64_t ID, uint32_t* _keyPointLeft, uint32_t* _keyPointRight, uint32_t _keyPointlen)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->SKP(_keyPointLeft, _keyPointRight, _keyPointlen);
}
int GPS(int64_t ID, uint32_t _startPostion, uint32_t _endPosition, uint32_t _peekNum)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->GPS(_startPostion, _endPosition, _peekNum);
}
int GFS(int64_t ID, float* _startValue, float* _lowerBounder, float* _upperBounder, uint32_t _constraintsParLen)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->GFS(_startValue, _lowerBounder, _upperBounder, _constraintsParLen);
}
int parse(int64_t ID, float* par, int len)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		std::cout << "parse=if" << endl;

		return -1;
	}
	return iter->second->parse(par, len);
}

int judge(int64_t ID)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->judge();
}
int calc(int64_t ID, const float* pArgDatas, int len, float* pCoalData, int len1,int channel)
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->calc(pArgDatas, len, pCoalData, len1,channel);
}
int getData(int64_t ID, float* par, int len) 
{
	std::map<long long int, CparseInterface*>::iterator iter = inst_set.find(ID);
	if (iter == inst_set.end())
	{
		std::cout << "没有ID为:" + std::to_string(ID) + "的类对象";
		return -1;
	}
	return iter->second->getData(par, len);
}


static double abs(double x, double y) {
	return (x - y) > 0 ? (x - y) : (y - x);
}

static int findMin(uint32_t leftX, uint32_t rightX, double* x, double* y, uint32_t len, uint32_t* xp, double* fx, double* fy)
{
	return 0;
}

static int findMax(uint32_t leftX, uint32_t rightX, double* x, double* y, uint32_t len, uint32_t* xp, double* fx, double* fy)
{
	return 0;
}

static int findP2N(uint32_t leftX, uint32_t rightX, double* x, double* y, uint32_t len, uint32_t* xp, double* fx, double* fy)
{
	return 0;
}

static int findN2P(uint32_t leftX, uint32_t rightX, double* x, double* y, uint32_t len, uint32_t* xp, double* fx, double* fy)
{
	return 0;
}

static bool isLegal(double* y, uint32_t leftPoint, uint32_t rightPoint, double highest, double lowest)
{
	return true;
}

static void calcModel1(const float* pArgDatas, int len, float* pCoalData, int len1) {
	VMProtectBegin("calcModel1");
	VMProtectEnd();
}

static void calcModel2(const float* pArgDatas, int len, float* pCoalData, int len1) {
	VMProtectBegin("calcModel2");
	VMProtectEnd();

}

static void calcModel3(const float* pArgDatas, int len, float* pCoalData, int len1) {
	VMProtectBegin("calcModel3");
	VMProtectEnd();

}



// This is the constructor of a class that has been exported.
CparseInterface::CparseInterface()
{
	return;
}

CparseInterface::~CparseInterface()
{
	hklibTerminate();
}
int CparseInterface::IT()
{
	if (!hklibInitialize())
	{
		cout << "hklibInitialize fialed" << endl;
		return -1;
	}

	return 0;
}

int CparseInterface::SetData(const float* pXData, const float* pYData, int len)
{
	dataLength = len;

	x = new double[dataLength];
	if (NULL == x)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	y = new double[dataLength];
	if (NULL == y)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}

	for (uint32_t k = 0; k < dataLength; k++)
	{
		x[k] = pXData[k];
		y[k] = pYData[k];
	}

	ys = new double[dataLength];
	if (NULL == ys)
	{
		cout << "malloc ys fialed" << endl;
		return -1;
	}


	yrj = new double[dataLength];
	if (NULL == yrj)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	yrqj = new double[dataLength];
	if (NULL == yrqj)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	d1y = new double[dataLength];
	if (NULL == d1y)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	d1ys = new double[dataLength];
	if (NULL == d1ys)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	d2y = new double[dataLength];
	if (NULL == d2y)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}
	d2ys = new double[dataLength];
	if (NULL == d2ys)
	{
		cout << "malloc fialed" << endl;
		return -1;
	}

	return 0;
}

int CparseInterface::DIT(void)
{
	delete(x);
	delete(y);

	x = NULL;
	y = NULL;

	delete(ys);
	delete(yrj);
	delete(yrqj);
	delete(d1y);
	delete(d1ys);
	delete(d2y);
	delete(d2ys);

	uint32_t bSpline_Vec_Len = 30;

	ys = NULL;
	yrj = NULL;
	yrqj = NULL;
	d1y = NULL;
	d1ys = NULL;
	d2y = NULL;
	d2ys = NULL;

	delete(bSpline_Vec);
	bSpline_Vec = NULL;

	delete(gausseFitX);
	delete(gausseFitY);
	delete(startValue);
	delete(lowerBounder);
	delete(upperBounder);

	gausseFitX = NULL;
	gausseFitY = NULL;
	startValue = NULL;
	lowerBounder = NULL;
	upperBounder = NULL;

	delete(gaussCoef);
	delete(gaussArea);

	gaussCoef = NULL;
	gaussArea = NULL;

	delete(keyPointLeft);
	delete(keyPointRight);

	keyPointLeft = NULL;
	keyPointRight = NULL;

	delete(kx);
	delete(ky);
	kx = NULL;
	ky = NULL;

	return 0;
}

int CparseInterface::SPSET(uint32_t _order, uint32_t _winLength)
{
	sgfilter_order = _order;
	sgfilter_winLength = _winLength;

	return 0;
}
int CparseInterface::BPV(uint32_t* _bSplineVec, uint32_t _bSplineVecLen)
{
	bSpline_Vec_Len = _bSplineVecLen;

	bSpline_Vec = new double[bSpline_Vec_Len];
	if (NULL == bSpline_Vec)
	{
		cout << "malloc bSpline_Vec failed!" << endl;
		return -1;
	}

	for (uint32_t k = 0; k < _bSplineVecLen; k++)
	{
		bSpline_Vec[k] = _bSplineVec[k];
	}

	return 0;
}
int CparseInterface::SKP(uint32_t* _keyPointLeft, uint32_t* _keyPointRight, uint32_t _keyPointlen)
{
	keyPointlen = _keyPointlen;

	keyPointLeft = new uint32_t[keyPointlen];
	if (NULL == keyPointLeft)
	{
		cout << "malloc keyPointLeft failed!" << endl;
		return -1;
	}

	keyPointRight = new uint32_t[keyPointlen];
	if (NULL == keyPointRight)
	{
		cout << "malloc keyPointRight failed!" << endl;
		return -1;
	}
	for (uint32_t k = 0; k < keyPointlen; k++)
	{
		keyPointLeft[k] = _keyPointLeft[k];
		keyPointRight[k] = _keyPointRight[k];
	}

	memset(xKeyPos, 0, 11 * sizeof(uint32_t));

	kx = new double[keyPointlen];
	if (NULL == kx)
	{
		cout << "malloc kx failed!" << endl;
		return -1;
	}

	ky = new double[keyPointlen];
	if (NULL == ky)
	{
		cout << "malloc ky failed!" << endl;
		return -1;
	}

	return 0;
}
int CparseInterface::GPS(uint32_t _startPostion, uint32_t _endPosition, uint32_t _peekNum)
{
	startPostion = _startPostion;
	endPosition = _endPosition;
	peekNum = _peekNum;

	gausseFitLenght = endPosition - startPostion + 1;

	gausseFitX = new double[gausseFitLenght];
	if (NULL == gausseFitX)
	{
		cout << "malloc gausseFitX failed!" << endl;
		return -1;
	}

	gausseFitY = new double[gausseFitLenght];
	if (NULL == gausseFitY)
	{
		cout << "malloc gausseFitY failed!" << endl;
		return -1;
	}

	gaussCoef = new double[3 * peekNum];
	if (NULL == gaussCoef)
	{
		cout << "malloc gaussCoef failed!" << endl;
		return -1;
	}

	gaussArea = new double[peekNum];
	if (NULL == gaussArea)
	{
		cout << "malloc gaussArea failed!" << endl;
		return -1;
	}
	return 0;
}
int CparseInterface::GFS(float* _startValue, float* _lowerBounder, float* _upperBounder, uint32_t _constraintsParLen)
{
	constraintsParLen = _constraintsParLen;

	startValue = new double[constraintsParLen];
	if (NULL == startValue)
	{
		cout << "malloc startValue failed!" << endl;
		return -1;
	}


	lowerBounder = new double[constraintsParLen];
	if (NULL == lowerBounder)
	{
		cout << "malloc upperBounder failed!" << endl;
		return -1;
	}


	upperBounder = new double[constraintsParLen];
	if (NULL == upperBounder)
	{
		cout << "malloc upperBounder failed!" << endl;
		return -1;
	}

	for (uint32_t k = 0; k < constraintsParLen; k++)
	{
		startValue[k] = _startValue[k];
		lowerBounder[k] = _lowerBounder[k];
		upperBounder[k] = _upperBounder[k];
	}

	return 0;
}

int CparseInterface::parse(float* par, int len)

{
	VMProtectBegin("parse");
	int ret = -1;
	std::cout << "parse=====" << endl;
	ret = dataProcess();
	std::cout << "parse1" << endl;
	if (ret < 0)
	{
		return -1;
	}

	for (uint32_t k = 0; k < len; k++)
	{
		std::cout << "parse k:"<<k << endl;
		par[k] = argumentsData[k];
	}
	VMProtectEnd();
	return 0;
}

int CparseInterface::judge(void)

{
	VMProtectBegin("judge");
	return 0;
	VMProtectEnd();


}

int CparseInterface::calc(const float* pArgDatas, int len, float* pCoalData, int len1, int channel)
{
	switch (channel) {
	case 1:
		cout << "calcModel1" << endl;
		calcModel1(pArgDatas, len, pCoalData, len1);
		return 0;
	case 2:
		cout << "calcModel2" << endl;
		calcModel2(pArgDatas, len, pCoalData, len1);
		return 0;
	case 3:
		cout << "calcModel3" << endl;
		calcModel3(pArgDatas, len, pCoalData, len1);
		return 0;
	default:
		return 1;
	}
	return 0;
}

int CparseInterface::getData(float* par, int len)
{
	for (uint32_t k = 0; k < len; k++)
	{
		par[k] = argumentsData[k];
	}

	return 0;
}

int CparseInterface::dataProcess()
{

	VMProtectBegin("dataProcess");
	std::cout << "parse0000000---" << endl;
	mwArray mw_x(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_y(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000001" << endl;

	mwArray mw_sgfilter_order(1, 1, mxDOUBLE_CLASS, mxREAL);
		std::cout << "parse00000002" << endl;

	mwArray mw_sgfilter_winLength(1, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000002" << endl;

	mwArray mw_bSpline_Vec(bSpline_Vec_Len, 1, mxDOUBLE_CLASS, mxREAL);

	mwArray mw_ys(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_yrj(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_yrqj(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_yrqjArea(1, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000003" << endl;

	mwArray mw_d1y(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_d1ys(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_d2y(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_d2ys(dataLength, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000004" << endl;

	mwArray mw_gx(gausseFitLenght, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_gy(gausseFitLenght, 1, mxDOUBLE_CLASS, mxREAL);

	mwArray mw_startValue(peekNum * 3, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_lowerBounder(peekNum * 3, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_upperBounder(peekNum * 3, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000005" << endl;

	mwArray mw_fitcurve(gausseFitLenght, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_gaussY(gausseFitLenght, 7, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_peekNum(1, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_area(peekNum, 1, mxDOUBLE_CLASS, mxREAL);
	mwArray mw_coef(peekNum * 3, 1, mxDOUBLE_CLASS, mxREAL);
	std::cout << "parse00000006" << endl;

	mw_x.SetData(x, dataLength);
	mw_y.SetData(y, dataLength);


	 //sgfilter parameters set
	mw_sgfilter_order.SetData(&sgfilter_order, 1);
	mw_sgfilter_winLength.SetData(&sgfilter_winLength, 1);
	sgfilter(1, mw_ys, mw_y, mw_sgfilter_order, mw_sgfilter_winLength);

	//argumentsData[ARGUMENTS_DATA_Sall] = 0;
	argumentsData[ARGUMENTS_DATA_Sall] = 1;
	argumentsData[ARGUMENTS_DATA_a1] = 2;
	argumentsData[ARGUMENTS_DATA_b1] = 3;
	argumentsData[ARGUMENTS_DATA_c1] = 4;
	argumentsData[ARGUMENTS_DATA_a2] = 5;
	argumentsData[ARGUMENTS_DATA_b2] = 6;
	argumentsData[ARGUMENTS_DATA_c2] = 7;
	argumentsData[ARGUMENTS_DATA_a3] = 8;
	argumentsData[ARGUMENTS_DATA_b3] = 9;
	argumentsData[ARGUMENTS_DATA_c3] = 10;
	argumentsData[ARGUMENTS_DATA_a4] = 11;
	argumentsData[ARGUMENTS_DATA_b4] = 12;
	argumentsData[ARGUMENTS_DATA_c4] = 13;
	argumentsData[ARGUMENTS_DATA_a5] = 14;
	argumentsData[ARGUMENTS_DATA_b5] = 15;
	argumentsData[ARGUMENTS_DATA_c5] = 16;
	argumentsData[ARGUMENTS_DATA_a6] = 17;
	argumentsData[ARGUMENTS_DATA_b6] = 18;
	argumentsData[ARGUMENTS_DATA_c6] = 19;
	argumentsData[ARGUMENTS_DATA_a7] = 20;
	argumentsData[ARGUMENTS_DATA_b7] = 21;
	argumentsData[ARGUMENTS_DATA_c7] = 22;

	argumentsData[ARGUMENTS_DATA_S71] = 23;
	argumentsData[ARGUMENTS_DATA_S72] = 24;
	argumentsData[ARGUMENTS_DATA_S73] = 25;
	argumentsData[ARGUMENTS_DATA_S74] = 26;
	argumentsData[ARGUMENTS_DATA_S75] = 27;
	argumentsData[ARGUMENTS_DATA_S76] = 28;
	argumentsData[ARGUMENTS_DATA_S77] = 29;
	argumentsData[ARGUMENTS_DATA_S7all] = 30;


	argumentsData[ARGUMENTS_DATA_CF] = 31;
	argumentsData[ARGUMENTS_DATA_RS1] = 32;
	argumentsData[ARGUMENTS_DATA_RS2] = 33;
	argumentsData[ARGUMENTS_DATA_RS3] = 34;
	argumentsData[ARGUMENTS_DATA_RS4] = 35;
	argumentsData[ARGUMENTS_DATA_RS5] = 36;
	argumentsData[ARGUMENTS_DATA_RS6] = 37;
	argumentsData[ARGUMENTS_DATA_RS7] = 38;


	argumentsData[ARGUMENTS_DATA_KX1] = 39;
	argumentsData[ARGUMENTS_DATA_D1Ymax1] = 40;
	argumentsData[ARGUMENTS_DATA_KX2] = 41;
	argumentsData[ARGUMENTS_DATA_KX3] = 42;
	argumentsData[ARGUMENTS_DATA_KX4] = 43;
	argumentsData[ARGUMENTS_DATA_KX5] = 44;
	argumentsData[ARGUMENTS_DATA_D1Ymin1] = 45;
	argumentsData[ARGUMENTS_DATA_KX6] = 46;
	argumentsData[ARGUMENTS_DATA_D1Ymax2] = 47;
	argumentsData[ARGUMENTS_DATA_KX7] = 48;
	argumentsData[ARGUMENTS_DATA_D1Ymin2] = 49;
	argumentsData[ARGUMENTS_DATA_KX8] = 50;
	argumentsData[ARGUMENTS_DATA_D2Ymax1] = 51;
	argumentsData[ARGUMENTS_DATA_KX9] = 52;
	argumentsData[ARGUMENTS_DATA_D2Ymax2] = 53;
	argumentsData[ARGUMENTS_DATA_KX10] = 54;
	argumentsData[ARGUMENTS_DATA_KX11] = 55;

	argumentsData[ARGUMENTS_DATA_KY1] = 56;
	argumentsData[ARGUMENTS_DATA_KY2] = 57;
	argumentsData[ARGUMENTS_DATA_KY3] = 58;
	argumentsData[ARGUMENTS_DATA_KY4] = 59;
	argumentsData[ARGUMENTS_DATA_KY5] = 60;
	argumentsData[ARGUMENTS_DATA_KY6] = 61;
	argumentsData[ARGUMENTS_DATA_KY7] = 62;
	argumentsData[ARGUMENTS_DATA_KY8] = 63;
	argumentsData[ARGUMENTS_DATA_KY9] = 64;
	argumentsData[ARGUMENTS_DATA_KY10] = 65;
	argumentsData[ARGUMENTS_DATA_KY11] = 66;


	VMProtectEnd();
	return 0;
}

