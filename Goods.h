//Goods.h
#ifndef GOODS_H_INCLUDED
#define GOODS_H_INCLUDED
#include "Date.h"
class Goods//��Ʒ��
{
private:
	char   name[26];//��Ʒ����
	int    NO;//��Ʒ���
	float  price;//��Ʒ�۸�
	int    number;//��Ʒ����
	Date   time;//��Ʒ�ϼ�ʱ��
public:
	Goods();//ȱʡ���캯��
	Goods(char *n,int N,float p,int no,Date sf);//��ȱʡ���캯��
	void insert();//����/�ϼ���Ʒ����
	void Print();//�����Ʒ�����Ϣ����
	float GetPrice();//���ؼ۸�
	char *Getname();//������Ʒ����
	int  Getnumber();//������Ʒ����
	int  GetNO();//������Ʒ���
	void  Putname(char *a);//������Ʒ����
	void Putnumber(int nu);//������Ʒ����
};

#endif // GOODS_H_INCLUDED
