//Goods.cpp
#include"Goods.h"
#include<string.h>
#include<iostream>
#include<iomanip>
using namespace std;
Goods::Goods()//ȱʡ���캯��
{
	strcpy(name,"name1");
	NO=001;
	price=0.0f;
    number=0;
}


Goods::Goods(char *n,int N,float p,int no,Date sf):time(sf)//��ȱʡ���캯��
{
	strcpy(name,n);
    NO=N;
	price=p;
	number=no;
}


void Goods::insert()//������Ʒ��Ϣ
{
	cout<<"��Ʒ����:";
	cin.getline(name,30);
    cout<<"��Ʒ���:";
	cin>>NO;
	cin.ignore();
	cout<<"��Ʒ�۸�:";
	cin>>price;
	cin.ignore();
	cout<<"��Ʒ����:";
	cin>>number;
	cin.ignore();
	cout<<"�ϼ�ʱ��";
	time.insert();

}


void Goods::Print()//��ӡ��Ʒ��Ϣ
{
	cout<<"��Ʒ����:"<<name<<endl;
	cout<<"��Ʒ���:"<<NO<<endl;
	cout<<"�۸�(Ԫ):"<<price<<endl;
	cout<<"��Ʒ����:"<<number<<endl;
	cout<<"�ϼ�ʱ��:";
	time.Print();
}

float Goods::GetPrice()//��ȡ��Ʒ�۸���
{
	return price;
}
char *Goods::Getname()//��ȡ���ƺ���
{
	return name;
}
int Goods::Getnumber()//������Ʒ����
{
	return number;
}
void Goods::Putnumber(int nu)//������Ʒ����
{
	 number-=nu;
}

void Goods::Putname(char *a)//������Ʒ����
{
	strcpy(name,a);
}

int  Goods::GetNO()//������Ʒ���
{
    return NO;
}
