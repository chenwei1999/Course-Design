//Date.h
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
using namespace std;
#include <cstdlib>
class Date//ʱ����
{
  protected:
	int year,month,day;
  public:
	Date(int year=1990,int month=1,int day=1);//���캯��
	Date(const Date &br);//�������캯��
	friend istream & operator>>(istream & strm,Date & obj)//����������>>
	{

			cout<<"���:";
			strm>>obj.year;
			while(obj.year<1950||obj.year>2050)
			{
				cout<<"�����1950-2050֮��"<<endl;
				cout<<"���:";
			    strm>>obj.year;

			}
			cout<<"��:";
			strm>>obj.month;
			while(obj.month<1||obj.month>12)
			{
				cout<<"�·���1-12֮��"<<endl;
				cout<<"��:";
			    strm>>obj.month;

			}
			cout<<"��:";
			strm>>obj.day;
			while(obj.day<1||obj.day>31)
			{
				cout<<"����1-31֮��"<<endl;
				cout<<"��:";
				strm>>obj.day;

			}

			return strm;
	}
	void Print();//���ʱ��ĺ���
	void insert();//����ʱ��ĺ���
    int gift();//�жϵ����Ƿ������յĺ���
};


#endif // DATE_H_INCLUDED
