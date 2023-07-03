// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PARSEINTERFACE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PARSEINTERFACE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#define PARSEINTERFACE_EXPORTS
#ifdef PARSEINTERFACE_EXPORTS
#define PARSEINTERFACE_API __declspec(dllexport)
#else
#define PARSEINTERFACE_API __declspec(dllimport)
#endif

#include <stdint.h>

enum ARGUMENTS_DATA_E
{
	ARGUMENTS_DATA_KX1 = 0,
	ARGUMENTS_DATA_D1Ymax1,
	ARGUMENTS_DATA_KX2,
	ARGUMENTS_DATA_KX3,
	ARGUMENTS_DATA_KX4,
	ARGUMENTS_DATA_KX5,
	ARGUMENTS_DATA_D1Ymin1,
	ARGUMENTS_DATA_KX6,
	ARGUMENTS_DATA_D1Ymax2,
	ARGUMENTS_DATA_KX7,
	ARGUMENTS_DATA_D1Ymin2,
	ARGUMENTS_DATA_KX8,
	ARGUMENTS_DATA_D2Ymax1,
	ARGUMENTS_DATA_KX9,
	ARGUMENTS_DATA_D2Ymax2,
	ARGUMENTS_DATA_KX10,
	ARGUMENTS_DATA_KX11,
	ARGUMENTS_DATA_KY1,
	ARGUMENTS_DATA_KY2,//ID,19
	ARGUMENTS_DATA_KY3,//IV
	ARGUMENTS_DATA_KY4,//IG
	ARGUMENTS_DATA_KY5,
	ARGUMENTS_DATA_KY6,
	ARGUMENTS_DATA_KY7,
	ARGUMENTS_DATA_KY8,
	ARGUMENTS_DATA_KY9,
	ARGUMENTS_DATA_KY10,
	ARGUMENTS_DATA_KY11,
	ARGUMENTS_DATA_α1,
	ARGUMENTS_DATA_α2,
	ARGUMENTS_DATA_α3,
	ARGUMENTS_DATA_ID_IG, // ID / IG
	ARGUMENTS_DATA_IV_ID, // IV / ID
	ARGUMENTS_DATA_IV_IG, // IV / IG
	ARGUMENTS_DATA_PTZL,
	ARGUMENTS_DATA_Sall, // 对平滑校正后曲线800-1800段积分
	ARGUMENTS_DATA_a1, // 拟合曲线1的输出参数a
	ARGUMENTS_DATA_b1, // 拟合曲线1的输出参数b
	ARGUMENTS_DATA_c1, // 拟合曲线1的输出参数c
	ARGUMENTS_DATA_a2,
	ARGUMENTS_DATA_b2,
	ARGUMENTS_DATA_c2,
	ARGUMENTS_DATA_a3,
	ARGUMENTS_DATA_b3,
	ARGUMENTS_DATA_c3,
	ARGUMENTS_DATA_a4,
	ARGUMENTS_DATA_b4,
	ARGUMENTS_DATA_c4,
	ARGUMENTS_DATA_a5,
	ARGUMENTS_DATA_b5,
	ARGUMENTS_DATA_c5,
	ARGUMENTS_DATA_a6,
	ARGUMENTS_DATA_b6,
	ARGUMENTS_DATA_c6,
	ARGUMENTS_DATA_a7,
	ARGUMENTS_DATA_b7,
	ARGUMENTS_DATA_c7,
	ARGUMENTS_DATA_S71, // 7峰拟合中第1个峰的峰面积
	ARGUMENTS_DATA_S72, // 7峰拟合中第2个峰的峰面积
	ARGUMENTS_DATA_S73, // 7峰拟合中第3个峰的峰面积
	ARGUMENTS_DATA_S74, // 7峰拟合中第4个峰的峰面积
	ARGUMENTS_DATA_S75, // 7峰拟合中第5个峰的峰面积
	ARGUMENTS_DATA_S76, // 7峰拟合中第6个峰的峰面积
	ARGUMENTS_DATA_S77, // 7峰拟合中第7个峰的峰面积
	ARGUMENTS_DATA_S7all, // S1+S2+S3+S4+S5+S6+S7 用分峰拟合的峰的面积计算总和
	ARGUMENTS_DATA_CF, // (S7all-Sall)/Sall
	ARGUMENTS_DATA_RS1,// S77/S7all
	ARGUMENTS_DATA_RS2,// S73/S7all
	ARGUMENTS_DATA_RS3,// S76/S7all
	ARGUMENTS_DATA_RS4,// (S74+S75)/S7all
	ARGUMENTS_DATA_RS5,// (S74+S75)/S73
	ARGUMENTS_DATA_RS6,// (S74+S75)/S76
	ARGUMENTS_DATA_RS7, // (S71+S72+S74+S75+S77)/S73

	ARGUMENTS_DATA_YD
};

#define ARGUMENTS_DATA_LENGTH 200

// This class is exported from the dll
class PARSEINTERFACE_API CparseInterface {
public:
	CparseInterface(void);
	// TODO: add your methods here.

	virtual ~CparseInterface();


	int IT();
	int DIT(void);

	int SetData(const float* pXData, const float* pYData, int len);
	int SPSET(uint32_t _order, uint32_t _winLength);
	int BPV(uint32_t* _bSplineVec, uint32_t _bSplineVecLen);
	int SKP(uint32_t* _keyPointLeft, uint32_t* _keyPointRight, uint32_t _keyPointlen);
	int GPS(uint32_t _startPostion, uint32_t _endPosition, uint32_t _peekNum);
	int GFS(float* _startValue, float* _lowerBounder, float* _upperBounder, uint32_t _constraintsParLen);

	int parse(float* par, int len);
	int judge(void);
	//int calc(const float* pArgDatas, int len, float* pCoalData, int len1);
	int calc(const float* pArgDatas, int len, float* pCoalData, int len1, int channel);

	int getData(float* par, int len);

private:
	int dataProcess();

	float argumentsData[ARGUMENTS_DATA_LENGTH];

	// 原始数据及其长度
	uint32_t dataLength = 0;
	double* x = NULL;
	double* y = NULL;

	// 平滑的阶数和平滑长度
	double sgfilter_order = 2;
	double sgfilter_winLength = 27;

	// B样条拟合点的位置及其拟合点的数量
	double* bSpline_Vec = NULL;
	uint32_t bSpline_Vec_Len = 30;

	// 数据处理过程数据
	double* ys = NULL;
	double* yrj = NULL;
	double* yrqj = NULL;
	double* d1y = NULL;
	double* d1ys = NULL;
	double* d2y = NULL;
	double* d2ys = NULL;
	double yrqjArea = 0;

	// 高斯多峰拟合相关变量
	uint32_t startPostion;
	uint32_t endPosition;
	uint32_t peekNum;

	uint32_t gausseFitLenght;
	double* gausseFitX;
	double* gausseFitY;

	double* startValue;
	double* lowerBounder;
	double* upperBounder;
	uint32_t constraintsParLen;

	double* gaussCoef;
	double* gaussArea;

	// 关键点位置系列参数
	uint32_t* keyPointLeft;
	uint32_t* keyPointRight;
	uint32_t keyPointlen = 0;

	uint32_t xKeyPos[11];
	double* kx = NULL;
	double* ky = NULL;

	double d1yMax1;
	double d1yMin1;
	double d1yMin2;
	double d1yMax2;
	double d2yMax1;
	double d2yMax2;
};
extern "C" __declspec(dllexport) long long int IT();//
extern "C" __declspec(dllexport) int DIT(int64_t ID);//
extern "C" __declspec(dllexport) int SetData(int64_t ID, const float* pXData, const float* pYData, int len);
extern "C" __declspec(dllexport) int SPSET(int64_t ID, uint32_t _order, uint32_t _winLength);
extern "C" __declspec(dllexport) int BPV(int64_t ID, uint32_t * _bSplineVec, uint32_t _bSplineVecLen);
extern "C" __declspec(dllexport) int SKP(int64_t ID, uint32_t * _keyPointLeft, uint32_t * _keyPointRight, uint32_t _keyPointlen);
extern "C" __declspec(dllexport) int GPS(int64_t ID, uint32_t _startPostion, uint32_t _endPosition, uint32_t _peekNum);
extern "C" __declspec(dllexport) int GFS(int64_t ID, float* _startValue, float* _lowerBounder, float* _upperBounder, uint32_t _constraintsParLen);

extern "C" __declspec(dllexport) int parse(int64_t ID, float* par, int len);


//extern "C" __declspec(dllexport) int dataProcess(int64_t ID);

extern "C" __declspec(dllexport) int judge(int64_t ID);
extern "C" __declspec(dllexport) int calc(int64_t ID, const float* pArgDatas, int len, float* pCoalData, int len1,int channel);

extern "C" __declspec(dllexport) int getData(int64_t ID, float* par, int len);


