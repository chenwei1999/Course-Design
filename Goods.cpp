//Goods.cpp
#include"Goods.h"
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;
Goods::Goods()//缺省构造函数
{
	strcpy(name,"name1");
	NO=001;
	price=0.0f;
    number=0;
}


Goods::Goods(char *n,int N,float p,int no,Date sf):time(sf)//非缺省构造函数
{
	strcpy(name,n);
    NO=N;
	price=p;
	number=no;
}


void Goods::insert()//输入商品信息
{
	cout<<"商品名称:";
	cin.getline(name,30);
    cout<<"商品编号:";
	cin>>NO;
	cin.ignore();
	cout<<"商品价格:";
	cin>>price;
	cin.ignore();
	cout<<"商品数量:";
	cin>>number;
	cin.ignore();
	cout<<"上架时间";
	time.insert();

}


void Goods::Print()//打印商品信息
{
	cout<<"商品名称:"<<name<<endl;
	cout<<"商品编号:"<<NO<<endl;
	cout<<"价格(元):"<<price<<endl;
	cout<<"商品数量:"<<number<<endl;
	cout<<"上架时间:";
	time.Print();
}

float Goods::GetPrice()//获取商品价格函数
{
	return price;
}
char *Goods::Getname()//获取名称函数
{
	return name;
}
int Goods::Getnumber()//返回商品数量
{
	return number;
}
void Goods::Putnumber(int nu)//减少商品数量
{
	 number-=nu;
}

void Goods::Putname(char *a)//输入商品名称
{
	strcpy(name,a);
}

int  Goods::GetNO()//返回商品编号
{
    return NO;
}
