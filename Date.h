//Date.h
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
class Date//时间类
{
  protected:
	int year,month,day;
  public:
	Date(int year=1990,int month=1,int day=1);//构造函数
	Date(const Date &br);//拷贝构造函数
	friend istream & operator>>(istream & strm,Date & obj)//重载输入流>>
	{

			cout<<"年份:";
			strm>>obj.year;
			while(obj.year<1950||obj.year>2050)
			{
				cout<<"年份在1950-2050之间"<<endl;
				cout<<"年份:";
			    strm>>obj.year;

			}
			cout<<"月:";
			strm>>obj.month;
			while(obj.month<1||obj.month>12)
			{
				cout<<"月份在1-12之间"<<endl;
				cout<<"月:";
			    strm>>obj.month;

			}
			cout<<"日:";
			strm>>obj.day;
			while(obj.day<1||obj.day>31)
			{
				cout<<"日在1-31之间"<<endl;
				cout<<"日:";
				strm>>obj.day;

			}

			return strm;
	}
	void Print();//输出时间的函数
	void insert();//输入时间的函数
    int gift();//判断当天是否是生日的函数
};


#endif // DATE_H_INCLUDED
