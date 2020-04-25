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


void gsjm()//公告栏显示界面
{
    fstream file;
    file.open("gongshi.txt",ios::in);
    //gongshi.txt存放着管理员写的公示信息
    if(file.fail())
    {
        cout<<"\t\t\t\t\t读取公示信息失败"<<endl;
        exit(0);
    }

   	cout<<"\t\t\t\t\t********村部事务公示栏********"<<endl<<endl;
    cout<<"\t\t\t\t\t      不忘初心   继续前进"<<endl;
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

void  shijian()//显示时间的函数
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

void mainmenu()//主菜单
{
    int ch=5;
    while(ch!=3)//当change='3'时退出
    {
        time_t t = time(NULL);
        struct tm *pt = localtime(&t);
        cout<<"\t\t\t\t\t********智慧乡村  阳光政务********"<<endl<<endl;
		cout<<"\t\t\t\t\t      绘就新时代美丽乡村新画卷"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t\t1.村民\t";
		cout<<"\t\t\t2.管理员\t"<<endl<<endl<<endl;
		cout<<"\t\t\t\t3.退出系统\t";
		cout<<"\t\t4.清屏\t"<<endl;
		cout<<endl<<endl<<endl;
		cout<<"\t当前时间: "<<pt->tm_year+1900<<"."<<pt->tm_mon+1<<"."<<pt->tm_mday<<"  ";//显示时间年月日
		cout<<pt->tm_hour<<":";
        //底下显示秒时，由于int型变量存储0x时会显示缺0，所以此处修饰

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
			cout<<"您输入的指令有错!"<<endl;
			ch=3;
			break;
        }
    }

}

void villmenu()//村民菜单
{
	int change=9;//当change='4'时退出
	while(change!=4)
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)村民登录";
		cout<<"\t2)村民注册";
		cout<<"\t3)美丽乡村";
		cout<<"\t4)返回首页";
		cout<<"\t5)清屏"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"请选择:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 :  char acc[50];
                  cout<<"账号:";
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
			 cout<<"您输入的指令有错!"<<endl;
             break;
		}
      }

}

void guanmenu()//管理员界面
{
    int change=9;
	while(change!=3)//当change='3'时退出
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)管理员登录";
		cout<<"\t2)管理员注册";
		cout<<"\t3)返回首页";
		cout<<"\t4)清屏"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"请选择:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
          case 1:
                  char acc[50];
                  cout<<"账号:";
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
			 cout<<"您输入的指令有错!"<<endl;
			 break;
		}

    }
}

void wangye()//显示乡村网页界面
{
    int ch=9;
    char change;
    while(ch!=3)//当ch='3'时退出
	{
		cout<<"\t\t\t\t\t********美丽乡村门户网站********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)恒北村";
		cout<<"\t2)荷兰花海";
		cout<<"\t3)返回  ";
		cout<<"\t4)清屏"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"请选择:";
		cin>>ch;
		cin.ignore();
		switch(ch)
		{

         case 1:
                cout<<"简介:"<<endl<<"   恒北村位于江苏省大丰区南郊，是国家级生态村，是全国最大的早酥梨商品生产基地，";
                cout<<"产品获得国家有机食品认证。\n2012年12月底，国家主席胡锦涛来恒北村视察。";
                cout<<"恒北村，犹如世外“梨”源。"<<endl<<endl;
                cout<<"是否要打开门户网站(是:Y否:N):";
                cin>>change;
                if(change=='Y')
                   {
                        ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://www.hengbeicun.com/index.asp"), NULL, SW_SHOW);//打开恒北村网页
                        break;
                   }
                else
                   break;
           case 2:
                  cout<<"简介:"<<endl<<"   荷兰花海位于盐城市大丰区新丰镇，";
                  cout<<"以田园、河网、建筑、风车、花海为元素，";
                  cout<<"打造具有荷兰风情的旅游休闲花园。"<<endl<<endl;
                  cout<<"是否要浏览门户网站(是:Y否:N):";
                  cin>>change;
                  if(change=='Y')
                      {
                        ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://www.dfhlhh.com/portal/"), NULL, SW_SHOW);//打开荷兰花海网页
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
                   cout<<"您输入的指令有错!"<<endl;
                   break;
        }
      }
}

void guanjiemian(char acc[])//管理员界面
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
		cout<<"\t\t\t\t\t********管理员界面********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t1)发布公告";
		cout<<"\t2)查询村民信息";
		cout<<"\t\t3)显示村民信息";
		cout<<"\t\t4)修改村民信息"<<endl<<endl;
		cout<<"\t\t5)删除村民信息";
		cout<<"\t6)发布农产品信息";
		cout<<"\t7)查看农产品信息";
		cout<<"\t8)查看公告栏"<<endl<<endl;
		cout<<"\t\t9)返回上一页";
		cout<<"\t10)清屏";
		cout<<"\t\t\t11)管理员信息"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"请选择:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
             case 1 :a.fbgs();break;
             case 2 :a.search();
                     Sleep(5000);
                     break;
             case 3 :cout<<endl<<"村民信息如下:"<<endl;
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
			         cout<<"您输入的指令有错!"<<endl;
			         break;
		}

    }
}


void cunjiemian(char acc[])//村民界面
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
    int change=20;//当change='8'时退出
	while(change!=8)
	{
		 cout<<"\t\t\t\t\t********村民界面********"<<endl<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t1)查看公告栏";
		cout<<"\t\t2)时事新闻"<<endl<<endl;
		cout<<"\t3)查看农产品";
		cout<<"\t\t4)购买农产品\t";
		cout<<"\t5)购物车";
		cout<<"\t\t6)已购买"<<endl<<endl;
		cout<<"\t7)个人信息";
		cout<<"\t\t8)返回上一页";
		cout<<"\t\t9)清屏"<<endl;

		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		//用Date类的gift函数判断是否过生日
		if(a.shengri()==1)
              cout<<endl<<"\t\t\t\t\t*******生日快乐!!********"<<endl<<endl;
		cout<<"请选择:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 : gsjm();Sleep(5000);break;
         case 2 : cout<<"\n即将打开腾讯新闻页面......";
                  Sleep(3000);
                  ShellExecute(NULL, _T("open"), _T("explorer.exe"), _T("http://news.qq.com/"), NULL, SW_SHOW);//打开腾讯新闻网页
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
			 cout<<"您输入的指令有错!"<<endl;
			 break;
		}

    }
}

void gouwuche(int mmp)//购物车界面
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
	while(change!=5)//当change='5'时退出
	{
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\t\t\t1)已选中农产品";
		cout<<"\t2)删除农产品";
		cout<<"\t3)结账";
		cout<<"\t4)清屏";
		cout<<"\t5)返回"<<endl;
		cout<<"\t---------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"请选择:";
		cin>>change;
		cin.ignore();
		switch(change)
		{
         case 1 : ygm(); break;
         case 2 : shanchusp(); break;
         case 3 : cout<<"是否要结账:";
                  cin>>ch;
                  if(ch=='Y')
                        a.jiezhang();
                  break;
		 case 4 :
                  system("cls");
                  break;
         case 5 :break;
          default:
			 cout<<"您输入的指令有错!"<<endl;
			 break;
		}

		}
}


