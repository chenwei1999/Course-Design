//Goods.h
#ifndef GOODS_H_INCLUDED
#define GOODS_H_INCLUDED
#include "Date.h"
class Goods//商品类
{
private:
	char   name[26];//商品名称
	int    NO;//商品编号
	float  price;//商品价格
	int    number;//商品数量
	Date   time;//商品上架时间
public:
	Goods();//缺省构造函数
	Goods(char *n,int N,float p,int no,Date sf);//非缺省构造函数
	void insert();//输入/上架商品函数
	void Print();//输出商品相关信息函数
	float GetPrice();//返回价格
	char *Getname();//返回商品名称
	int  Getnumber();//返回商品数量
	int  GetNO();//返回商品编号
	void  Putname(char *a);//输入商品名称
	void Putnumber(int nu);//减少商品数量
};

#endif // GOODS_H_INCLUDED
