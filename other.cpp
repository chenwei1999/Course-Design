//other.cpp
#include <iostream>
using namespace std;
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "other.h"
#include <tchar.h>
#include <assert.h>
#include "Manager.h"
#include <cstring>
#include "cunmin.h"


void gsjm()//��������ʾ����
{
    fstream file;
    file.open("gongshi.txt",ios::in);
    //gongshi.txt����Ź���Աд�Ĺ�ʾ��Ϣ
    if(file.fail())
    {
        cout<<"\t\t\t\t\t��ȡ��ʾ��Ϣʧ��"<<endl;
        exit(0);
    }

   	cout<<"\t\t\t\t\t********�岿����ʾ��********"<<endl<<endl;
    cout<<"\t\t\t\t\t      ��������   ����ǰ��"<<endl;
    cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;

    char gongshi[500];
    file.getline(gongshi,500);
    while(!file.eof())
    {
        cout<<"\t\t\t"<<gongshi<<endl;
        file.getline(gongshi,500);
    }
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;

}

void  shijian()//��ʾʱ��ĺ���
{
    while(1)
    {
        time_t t = time(NULL);
        struct tm *pt = localtime(&t);
        cout<<asctime(pt);
        Sleep(1000);
        system("cls");
    }
}

void mainmenu()//���˵�
{
    int ch=5;
    while(ch!=3)//��change='3'ʱ�˳�
    {
        time_t t = time(NULL);
        struct tm *pt = localtime(&t);
        cout<<"\t\t\t\t\t********�ǻ����  ��������********"<<endl<<endl;
		cout<<"\t\t\t\t\t      �����ʱ����������»���"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t\t1.����\t";
		cout<<"\t\t\t2.����Ա\t"<<endl<<endl<<endl;
		cout<<"\t\t\t\t3.�˳�ϵͳ\t";
		cout<<"\t\t4.����\t"<<endl;
		cout<<endl<<endl<<endl;
		cout<<"\t��ǰʱ��: "<<pt->tm_year+1900<<"."<<pt->tm_mon+1<<"."<<pt->tm_mday<<"  ";//��ʾʱ��������
		cout<<pt->tm_hour<<":";
        //������ʾ��ʱ������int�ͱ����洢0xʱ����ʾȱ0�����Դ˴�����

		if((pt->tm_min)>=0&&(pt->tm_min)<=9)
            cout<<"0"<<pt->tm_min;
		else
		    cout<<pt->tm_min;

		cout<<"\t\t\t\t\t\tCopyright (c) 2018 Chen Wei"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;
		cin>>ch;
        switch(ch)
        {
            case 1 :villmenu();
                    break;
            case 2 :guanmenu();
                    break;
            case 3 :break;
            case 4 :
                    system("cls");
                    break;
            default:
			cout<<"�������ָ���д�!"<<endl;
			ch=3;
			break;
        }
    }

}

void villmenu()//����˵�
{
	int change=9;//��change='4'ʱ�˳�
	while(change!=4)
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)�����¼";
		cout<<"\t2)����ע��";
		cout<<"\t3)�������";
		cout<<"\t4)������ҳ";
		cout<<"\t5)����"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"��ѡ��:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 :  char acc[50];
                  cout<<"�˺�:";
                  cin>>acc;
                  if(cunVeri(acc)==1 )
                      cunjiemian(acc);
                  break;
         case 2 : cunzhuce();
                  break;
         case 3 : wangye();
                  break;
         case 4 : break;
		 case 5 :
			     system("cls");
			     break;
          default:
			 cout<<"�������ָ���д�!"<<endl;
             break;
		}
      }

}

void guanmenu()//����Ա����
{
    int change=9;
	while(change!=3)//��change='3'ʱ�˳�
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)����Ա��¼";
		cout<<"\t2)����Աע��";
		cout<<"\t3)������ҳ";
		cout<<"\t4)����"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"��ѡ��:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
          case 1:
                  char acc[50];
                  cout<<"�˺�:";
                  cin>>acc;
                  if(guanVeri(acc)==1 )
                      guanjiemian(acc);
                  break;
          case 2: guanzhuce();
                  cin.ignore();
                  break;

          case 3 : break;
		  case 4 :
			      system("cls");
                  break;
          default:
			 cout<<"�������ָ���д�!"<<endl;
			 break;
		}

    }
}

void wangye()//��ʾ�����ҳ����
{
    int ch=9;
    char change;
    while(ch!=3)//��ch='3'ʱ�˳�
	{
		cout<<"\t\t\t\t\t********��������Ż���վ********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)�㱱��";
		cout<<"\t2)��������";
		cout<<"\t3)����  ";
		cout<<"\t4)����"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"��ѡ��:";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{

         case 1:
                cout<<"���:"<<endl<<"   �㱱��λ�ڽ���ʡ������Ͻ����ǹ��Ҽ���̬�壬��ȫ��������������Ʒ�������أ�";
                cout<<"��Ʒ��ù����л�ʳƷ��֤��\n2012��12�µף�������ϯ���������㱱���Ӳ졣";
                cout<<"�㱱�壬�������⡰�桱Դ��"<<endl<<endl;
                cout<<"�Ƿ�Ҫ���Ż���վ(��:Y��:N):";
                cin>>change;
                if(change=='Y')
                   {
                        ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://www.hengbeicun.com/index.asp"), NULL, SW_SHOW);//�򿪺㱱����ҳ
                        break;
                   }
                else
                   break;
           case 2:
                  cout<<"���:"<<endl<<"   ��������λ���γ��д�����·���";
                  cout<<"����԰���������������糵������ΪԪ�أ�";
                  cout<<"������к���������������л�԰��"<<endl<<endl;
                  cout<<"�Ƿ�Ҫ����Ż���վ(��:Y��:N):";
                  cin>>change;
                  if(change=='Y')
                      {
                        ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://www.dfhlhh.com/portal/"), NULL, SW_SHOW);//�򿪺���������ҳ
                        break;
                      }
                  else
                       break;
           case 3 : break;
           case 4 :
                   system("cls");
                   break;
            default:
                   system("cls");
                   cout<<"�������ָ���д�!"<<endl;
                   break;
        }
      }
}

void guanjiemian(char acc[])//����Ա����
{
    Manager a;
    fstream in;
    in.open("Manager.dat",ios::in|ios::binary);
    in.read((char *)&a,sizeof(Manager));
    while(!in.eof())
     {
        if(strcmp(a.GetAccount(),acc)==0)
              break;
        else
           in.read((char *)&a,sizeof(Manager));
    }
    in.close();
    int change=20;
	while(change!=9)
	{
		cout<<"\t\t\t\t\t********����Ա����********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t1)��������";
		cout<<"\t2)��ѯ������Ϣ";
		cout<<"\t\t3)��ʾ������Ϣ";
		cout<<"\t\t4)�޸Ĵ�����Ϣ"<<endl<<endl;
		cout<<"\t\t5)ɾ��������Ϣ";
		cout<<"\t6)����ũ��Ʒ��Ϣ";
		cout<<"\t7)�鿴ũ��Ʒ��Ϣ";
		cout<<"\t8)�鿴������"<<endl<<endl;
		cout<<"\t\t9)������һҳ";
		cout<<"\t10)����";
		cout<<"\t\t\t11)����Ա��Ϣ"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"��ѡ��:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
             case 1 :a.fbgs();break;
             case 2 :a.search();
                     Sleep(5000);
                     break;
             case 3 :cout<<endl<<"������Ϣ����:"<<endl;
                     a.xianshi();
                     break;
             case 4 :a.xiugai();break;
             case 5 :a.shanchu();break;
             case 6 :shangjia();break;
             case 7 :xianshincp();break;
             case 8 :gsjm();
                     Sleep(5000);
                     break;
             case 9 :break;
             case 10:
			         system("cls");
			         break;
             case 11:a.Print();
                     Sleep(5000);
                     break;
             default:
			         cout<<"�������ָ���д�!"<<endl;
			         break;
		}

    }
}


void cunjiemian(char acc[])//�������
{
    cunmin a;
    fstream in;
    in.open("cunmin.dat",ios::in|ios::binary);
    in.read((char *)&a,sizeof(cunmin));

     while(!in.eof())
     {
        if(strcmp(a.GetAccount(),acc)==0)
              break;
         else
           in.read((char *)&a,sizeof(cunmin));
    }
    in.close();
    int change=20;//��change='8'ʱ�˳�
	while(change!=8)
	{
		 cout<<"\t\t\t\t\t********�������********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t1)�鿴������";
		cout<<"\t\t2)ʱ������"<<endl<<endl;
		cout<<"\t3)�鿴ũ��Ʒ";
		cout<<"\t\t4)����ũ��Ʒ\t";
		cout<<"\t5)���ﳵ";
		cout<<"\t\t6)�ѹ���"<<endl<<endl;
		cout<<"\t7)������Ϣ";
		cout<<"\t\t8)������һҳ";
		cout<<"\t\t9)����"<<endl;

		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		//��Date���gift�����ж��Ƿ������
		if(a.shengri()==1)
              cout<<endl<<"\t\t\t\t\t*******���տ���!!********"<<endl<<endl;
		cout<<"��ѡ��:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 : gsjm();Sleep(5000);break;
         case 2 : cout<<"\n��������Ѷ����ҳ��......";
                  Sleep(3000);
                  ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://news.qq.com/"), NULL, SW_SHOW);//����Ѷ������ҳ
                  break;
         case 3 : xianshincp();break;
         case 4 : a.goumai();break;
         case 5 : gouwuche(a.GetcID());break;
         case 6 : a.algoumai();break;
         case 7 : a.Print();
                  Sleep(3000);
                  break;
         case 8 : break;
		 case 9 : system("cls");
                  break;
          default:
			 cout<<"�������ָ���д�!"<<endl;
			 break;
		}

    }
}

void gouwuche(int mmp)//���ﳵ����
{
    cunmin a;
    fstream in;
    in.open("cunmin.dat",ios::in|ios::binary);
    in.read((char *)&a,sizeof(a));
    while(!in.eof())
     {
        if(mmp==a.GetcID())
              break;
        else
           in.read((char *)&a,sizeof(a));
    }
    in.close();
    int change=9;
    char ch;
	while(change!=5)//��change='5'ʱ�˳�
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)��ѡ��ũ��Ʒ";
		cout<<"\t2)ɾ��ũ��Ʒ";
		cout<<"\t3)����";
		cout<<"\t4)����";
		cout<<"\t5)����"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"��ѡ��:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 : ygm(); break;
         case 2 : shanchusp(); break;
         case 3 : cout<<"�Ƿ�Ҫ����:";
                  cin>>ch;
                  if(ch=='Y')
                        a.jiezhang();
                  break;
		 case 4 :
                  system("cls");
                  break;
         case 5 :break;
          default:
			 cout<<"�������ָ���д�!"<<endl;
			 break;
		}

		}
}


