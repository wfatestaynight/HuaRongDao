#pragma once
////////////////////////////////////////////////////////////////
//              文件名称：ChessEncoded.h 
//              功    能: 华容道棋盘编码类
//				创建时间：2016年11月6日
//				创建  人：魏菲
////////////////////////////////////////////////////////////////

const char U[] = "ABBBBCCCCCHHHHHM";; //棋子类型表
const int COL[20] = {0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3,0,1,2,3};   //列号表
const int ROW[20] = {0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4};   //行号表
const int WQ2[13] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096}; //二进制位权表(12个)

class ChessEncoded
{
public:
	//功能：编码类的构造函数 将棋盘的数据进行编码便于计算
	//输入：棋盘的当前数据，用于计算当前棋盘上棋子的类型
	//chessData 一维数组 5*4 = 20个元素代表20个棋盘上的点
	ChessEncoded(char *chessData);

	~ChessEncoded();

	//功能：将传入的棋盘进行编码
	//chessData 一维数组 5*4 = 20个元素代表20个棋盘上的点
	//返回：该棋盘的位权编码唯一
	int Encoded(char *chessData);


	//功能：查看棋盘对称的情况,对其编码
	//chessData 一维数组 5*4 = 20个元素代表20个棋盘上的点
	//返回：该棋盘的位权编码唯一
	int SymmetryEncoded(char *chessData);

	short int *Hz,*Sz,*Bz;  //竖将,横将,小兵,组合序号表

	int *Hw,*Sw,Mw[12]; //权值表:竖将,横将,大王

	int codeTotalNum;  //编码生成的最大权值数量
};

