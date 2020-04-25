//Date.cpp
#include "Date.h"
#include<iostream>
#include<iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;
Date::Date(int year,int month,int day)//构造函数
{
	this->year=year;
	this->month=month;
	this->day=day;
}
Date::Date(const Date &br)//拷贝构造函数
{
	year=br.year;
	month=br.month;
	day=br.day;
}
void Date::Print()//输出日期信息
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}

void Date::insert()//输入Date类数据
{
	cout<<"年份:";
	cin>>year;
	cin.ignore();
	while(year<1950||year>2018)
	{
		cout<<"年份在1950-2018之间"<<endl;
		cout<<"年份:";
		cin>>year;
		cin.ignore();
	}

	cout<<"月份:";
	cin>>month;
	cin.ignore();
	while(month<1||month>12)
	{
		cout<<"月份在1-12之间"<<endl;
		cout<<"月份:";
		cin>>month;
		cin.ignore();
	}
	cout<<"日:";
	cin>>day;
	cin.ignore();
	while(day<1||day>31)
	{
		cout<<"日在1-31之间"<<endl;
		cout<<"日:";
		cin>>day;
		cin.ignore();
	}
}

int Date::gift()//判断生日函数
{
    time_t t = time(NULL);//C++时间结构体
	struct tm *pt = localtime(&t);
	if(((pt->tm_mon+1)==month)&&(pt->tm_mday==day))
	   return 1;
    else
        return 0;

}
