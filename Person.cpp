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

Person::Person()//ȱʡ���캯��
{
    strcpy(name,"name");
    strcpy(address,"address");
    strcpy(ID,"000000000000000000");
    sex='m';
}



void Person::Insert()//�����˵���Ϣ
{
    cout<<"����д�����Ϣ:"<<endl;
    cout<<"����:";
	cin.getline(name,10);
	cout<<"�Ա�(M��,FŮ):";
	cin>>sex;
	cin.ignore();
	cout<<"��ַ:";
	cin.getline(address,100);
	cout<<"��������"<<endl;
	cin>>birthday;
	cin.ignore();
	cout<<"���֤��:";
	cin.getline(ID,19);

}

void Person::Print()//����˵���Ϣ
{
	cout<<"����:"<<name<<endl;
	if(sex=='M'||sex=='m')
		cout<<"�Ա�:"<<"��"<<endl;
	if(sex=='f'||sex=='F')
		cout<<"�Ա�:"<<"Ů"<<endl;
	cout<<"�� ַ:"<<address<<endl;
	cout<<"��������:";
	birthday.Print();
	cout<<"���֤��:"<<ID<<endl;
}
