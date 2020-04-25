//special.cpp
#include <iostream>
#include "Manager.h"
#include "cunmin.h"
using namespace std;
#include  <fstream>
#include  <conio.h>
#include  "other.h"
#include  "Goods.h"
void guanzhuce()//管理员注册
{
    Manager  g;
    int i=0,j=0;
    char ch;
    char pw[17];
    fstream  out;
    out.open("Manager.dat",ios::out|ios::binary|ios::app);
    if(out.fail())
    {
        cout<<"注册模块调用失败！"<<endl;
        return ;
    }
    g.Insert();
    strcpy(pw,g.GetPassword());
	while(j<3)
	{
	    i=0;
	    cout<<"确认密码:";
         while((ch =getch()) != '\r')
           {

                if(ch == '\b' && i >=0)
                {
                    printf("\b \b");
                    i--;
                }
                else
                    {
                        i++;
                        cout<<"*";
                    }

                if(pw[i-1]!=ch)
                {
                    cout<<"密码错误,还有"<<(2-j)<<"次机会!"<<endl;
                    j+=1;
                    break;
                }

          }
		cout<<endl;

		if(ch=='\r'&&pw[i]=='\0')
		{
			out.write((char *)&g,sizeof(Manager));
			cout<<"注册成功!"<<endl;
			break;
		}
	}
    out.close();

}


int guanVeri(char acc[])//管理员验证3次
{   Manager s;
    fstream  in;
    in.open("Manager.dat",ios::in|ios::binary);
    if(in.fail())
    {
        cout<<"验证模块调用失败！"<<endl;
        return 0;
    }
    int i = 0;
    int times = 1;
    char ch;
    char pw[50];

     in.read((char *)&s,sizeof(Manager));
     while(!in.eof())
     {
        if(strcmp(s.GetAccount(),acc)==0)
              break;
        else
           in.read((char *)&s,sizeof(Manager));
    }
    if(strcmp(s.GetAccount(),acc)!=0)
          {
              cout<<"您输入的账户名不存在"<<endl;

              return 0;
          }
    cout<<"请输入密码：";
    while(times <= 3)
    {
        i = 0;
        while((ch = getch()) != '\r')
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if(strcmp(pw,s.GetPassword())!=0)
        {
            if(times == 3)
                cout << "密码错误，退出！" << endl << endl;
            else
                cout << "密码错误，剩余" << (3-times) << "次机会：";
            times++;
        }
        else
        {
            cout << "密码正确！" << endl << endl;
            in.close();
            return 1;
        }
    }

    if(times == 4)
    {
        in.close();
        return 0;
    }
    return 0;
}


void cunzhuce()//村民注册函数
{
    cunmin  g;
    int i=0,j=0;
    char ch;
    char pw[17];
    fstream  out;
    out.open("cunmin.dat",ios::out|ios::binary|ios::app);
    if(out.fail())
    {
        cout<<"注册模块调用失败！"<<endl;
        return ;
    }
    g.Insert();
    strcpy(pw,g.GetPassword());
	while(j<3)
	{
	    i=0;
	    cout<<"确认密码:";

		  while((ch =getch()) != '\r')
        {

            if(ch == '\b' && i >=0)
            {
                printf("\b \b");
                i--;
            }
            else
                {
                    i++;
                    cout<<"*";
                }

            if(pw[i-1]!=ch)
            {
                cout<<"密码错误,还有"<<(2-j)<<"次机会!"<<endl;
				j+=1;
				break;
            }

          }
		cout<<endl;

		if(ch=='\r'&&pw[i]=='\0')
		{
			out.write((char *)&g,sizeof(cunmin));
			cout<<"注册成功!"<<endl;
			break;
		}
	}
    out.close();

}


int cunVeri(char acc[])//村民验证函数
{   cunmin s;
    fstream  in;
    in.open("cunmin.dat",ios::in|ios::binary);
    if(in.fail())
    {
        cout<<"验证模块调用失败！"<<endl;
        return 0;
    }
    int i = 0;
    int times = 1;
    char ch;
    char pw[50];

     in.read((char *)&s,sizeof(cunmin));
     while(!in.eof())
     {
        if(strcmp(s.GetAccount(),acc)==0)
              break;
        else
           in.read((char *)&s,sizeof(cunmin));
    }
    if(strcmp(s.GetAccount(),acc)!=0)
          {
              cout<<"您输入的账户名不存在"<<endl;
              return 0;
          }
    cout<<"请输入密码：";
    while(times <= 3)
    {
        i = 0;
        while((ch = getch()) != '\r')
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if(strcmp(pw,s.GetPassword())!=0)
        {
            if(times == 3)
                cout << "密码错误，退出！" << endl << endl;
            else
                cout << "密码错误，剩余" << (3-times) << "次机会：";
            times++;
        }
        else
        {
            cout << "密码正确！" << endl << endl;
            in.close();
            return 1;
        }
    }


    if(times == 4)
    {
        in.close();
        return 0;
    }
    return 0;
}



void shangjia()//上架商品函数
{   Goods m;
    fstream file;
    char ch;
    if(file.fail())
    {
        cout<<"商品上架失败!"<<endl;
        exit(0);
    }
    file.open("goods.dat",ios::out|ios::binary|ios::app);
    do
    {
        m.insert();
        file.write((char *)&m,sizeof(m));
        cout<<"是否继续(是Y否N):"<<endl;
        cin>>ch;
        cin.ignore();
    }
    while(ch=='Y');
    cout<<"\n上架农产品结束!";

}

void  xianshincp()//显示农产品
{
    Goods m;
    fstream file;
    int j=0;
    char ch='Y';

    if(file.fail())
    {
        cout<<"商品显示失败!"<<endl;
        exit(0);
    }

    file.open("goods.dat",ios::in|ios::binary);
    file.read((char *)&m,sizeof(m));
      while(!file.eof()&&ch=='Y')
      {
          j++;
          m.Print();
          cout<<endl;
          file.read((char *)&m,sizeof(m));
          if(j==3)
          {
             cout<<endl;
             cout<<"按Y显示下一页:";
             cin>>ch;
             j=0;
              system("cls");
          }


      }
      file.close();


}

void ygm()//显示放入购物车的函数
{
     fstream in;
     struct newbuy s;
     in.open("buytemp.dat",ios::in|ios::binary);

     if(in.fail())
     {
         cout<<"此模块调用失败！"<<endl;
         exit(0);
     }

     in.read((char *)&s,sizeof(s));

     cout<<"待结账商品如下:\n";
     while(!in.eof())
     {
         cout<<"商品名称:"
             <<s.name
             <<"   "
             <<"购买数量:"
             <<s.gmsl
             <<endl;
         in.read((char *)&s,sizeof(s));
     }
     in.close();
}

void shanchusp()//删除购物车中的信息
{
     fstream in,in2;
     struct newbuy s;
     char tname[20];
     char again;
     in.open("buytemp.dat",ios::in|ios::binary);
     in2.open("buytemp2.dat",ios::out|ios::binary);
     if(in.fail())
     {
         exit(0);
     }
     if(in2.fail())
     {
         exit(0);
     }
     cout<<"请输入你要删除的商品:\n";
     cin.getline(tname,20);
     in.read((char *)&s,sizeof(s));
	 while(!in.eof())
	   {
		if(strcmp(s.name,tname)==0)
              {

                  cout<<"商品名称:";
                  cout<<s.name;
                  cout<<"\n商品数量:";
                  cout<<s.gmsl<<endl;
                  break;
              }
	      	 in.read((char *)&s,sizeof(s));
    }

       cout<<"是否要删除该商品:";
       cin>>again;
           if(again=='Y')
			{
			      in.seekg(0,ios::beg);
                   in.read((char *)&s,sizeof(s));
						while(!in.eof())
						{

                             if(strcmp(s.name,tname)!=0)
                             {
                           	     in2.write((char *)&s,sizeof(s));
                             }


						   in.read((char *)&s,sizeof(s));
		          	    }

		            cout<<"删除成功！"<<endl;

	        }
	     else
	       {
		     exit(0);
      	   }

	   in.close();
	   in2.close();

	   remove("buytemp.dat");//删除临时商品源文件
       rename("buytemp2.dat","buytemp.dat");//将临时文件改名为源文件

}




