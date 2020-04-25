//Person.cpp
#include <iostream>
using namespace std;
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "other.h"
#include <tchar.h>
#include <assert.h>
#include "Person.h"

Person::Person()//缺省构造函数
{
    strcpy(name,"name");
    strcpy(address,"address");
    strcpy(ID,"000000000000000000");
    sex='m';
}



void Person::Insert()//输入人的信息
{
    cout<<"请填写相关信息:"<<endl;
    cout<<"姓名:";
	cin.getline(name,10);
	cout<<"性别(M男,F女):";
	cin>>sex;
	cin.ignore();
	cout<<"地址:";
	cin.getline(address,100);
	cout<<"出生日期"<<endl;
	cin>>birthday;
	cin.ignore();
	cout<<"身份证号:";
	cin.getline(ID,19);

}

void Person::Print()//输出人的信息
{
	cout<<"姓名:"<<name<<endl;
	if(sex=='M'||sex=='m')
		cout<<"性别:"<<"男"<<endl;
	if(sex=='f'||sex=='F')
		cout<<"性别:"<<"女"<<endl;
	cout<<"地 址:"<<address<<endl;
	cout<<"出生日期:";
	birthday.Print();
	cout<<"身份证号:"<<ID<<endl;
}
