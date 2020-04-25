//Date.cpp
#include "Date.h"
#include<iostream>
#include<iomanip>
#include <time.h>
#include <cstdlib>
using namespace std;
Date::Date(int year,int month,int day)//���캯��
{
	this->year=year;
	this->month=month;
	this->day=day;
}
Date::Date(const Date &br)//�������캯��
{
	year=br.year;
	month=br.month;
	day=br.day;
}
void Date::Print()//���������Ϣ
{
	cout<<year<<"-"<<month<<"-"<<day<<endl;
}

void Date::insert()//����Date������
{
	cout<<"���:";
	cin>>year;
	cin.ignore();
	while(year<1950||year>2018)
	{
		cout<<"�����1950-2018֮��"<<endl;
		cout<<"���:";
		cin>>year;
		cin.ignore();
	}

	cout<<"�·�:";
	cin>>month;
	cin.ignore();
	while(month<1||month>12)
	{
		cout<<"�·���1-12֮��"<<endl;
		cout<<"�·�:";
		cin>>month;
		cin.ignore();
	}
	cout<<"��:";
	cin>>day;
	cin.ignore();
	while(day<1||day>31)
	{
		cout<<"����1-31֮��"<<endl;
		cout<<"��:";
		cin>>day;
		cin.ignore();
	}
}

int Date::gift()//�ж����պ���
{
    time_t t = time(NULL);//C++ʱ��ṹ��
	struct tm *pt = localtime(&t);
	if(((pt->tm_mon+1)==month)&&(pt->tm_mday==day))
	   return 1;
    else
        return 0;

}
