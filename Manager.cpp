//Manager.cpp
#include "Manager.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include "cunmin.h"
using namespace std;

Manager::Manager()//缺省构造函数
{

    gID=1001;
	strcpy(zhiwu,"cunzhang");
	strcpy(account,"000000000000");
	strcpy(password,"00000000000000");
}

void Manager::Insert()//输入管理员信息
{   char ch;
    int i=0;
    Person::Insert();
    cout<<"管理员编号:";
    cin>>gID;
    cin.ignore();
    cout<<"管理员职务:";
    cin.getline(zhiwu,20);
    cout<<"管理员账号:";
    cin.getline(account,20);
    cout<<"管理员密码:";
     while((ch =getch()) != '\r')
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                password[i++] = ch;
                cout << '*';
            }
        }
	 password[i]='\0';


	  cout<<endl;
}

void Manager::Print()//打印管理员信息
{
    cout<<endl<<"管理员信息如下:"<<endl;
    cout<<"姓名:"<<name<<endl;
	if(sex=='M'||sex=='m')
		cout<<"性别:"<<"男"<<endl;
	if(sex=='f'||sex=='F')
		cout<<"性别:"<<"女"<<endl;
	cout<<"地 址:"<<address<<endl;
	cout<<"出生日期:";
	birthday.Print();
	cout<<"身份证号:"<<ID<<endl;
    cout<<"职务:"<<zhiwu<<endl;
    cout<<"管理员编号:"<<gID<<endl;
}

void Manager::fbgs()//管理员发布公告函数
{
    fstream file;
    file.open("gongshi.txt",ios::out);
    //此处文件为写公告用
    char ch;

    if(file.fail())
    {
        cout<<"\t\t\t\t\t发布公示信息失败"<<endl;
        exit(0);
    }

    cout<<"\t\t\t\t\t********发布告示********"<<endl<<endl;
    cout<<"\t\t\t\t\t   不忘初心   继续前进"<<endl;

    time_t t = time(NULL);
	struct tm *pt = localtime(&t);
	cout<<"\t日期:"<<pt->tm_year+1900<<"年"<<pt->tm_mon+1<<"月"<<pt->tm_mday<<"日";

    cout<<"\t\t\t\t\t\t\t  当前管理员:"<<name<<endl;
    cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;
    cout<<"请输入你要发布的消息（以键入'-1'结束）："<<endl;
    char s[500];
    cin.getline(s,500);

    while(1)
    {   if(strcmp(s,"-1")==0)
                {
                    cout<<endl<<endl<<"是否结束信息发布（是Y否N）：";
                    cin>>ch;
                    cin.ignore();

                }
        if(ch=='Y')
            break;

        if(strcmp(s,"-1")!=0)
        { file<<s;
          file<<'\n';
        }
        cin.getline(s,500);

    }

    file.seekp(0,ios::end);//将写指针放置最后
    cout<<endl<<"发布消息成功!"<<endl;
    file.close();

}


void Manager::xianshi()//显示村民信息
{
    cunmin s;
    fstream in;
    char ch='Y';
    int j=0;//这里用了j,意图为显示时每页只显示3个村民信息
    in.open("cunmin.dat",ios::in|ios::binary);//cunmin.dat存放着村民信息

    if(in.fail())
    {
      cout<<"村民显示失败！"<<endl;
      exit(0);
    }

    in.read((char *)&s,sizeof(cunmin));

    while(!in.eof()&&ch=='Y')
    {   j++;
        s.Print();
        cout<<endl;
        in.read((char *)&s,sizeof(cunmin));
        if(j==3)
        {
           cout<<endl;
           cout<<"按Y显示下一页:";
           cin>>ch;
           j=0;
           system("cls");//清屏
        }
    }

      in.close();
}

void Manager::search()//搜索村民信息
{
    cunmin s;
    fstream file;
    char temp[20];
    int i,j,rec,k=0;//k判断是否查找成功
    char temp2[20];
    file.open("cunmin.dat",ios::binary|ios::in);
    if(file.fail())
    {
      cout<<"村民查询失败！"<<endl;
      exit(0);
    }

    cout<<"请输入你要查找的村民(支持模糊查询):";
    cin.getline(temp,20);
    int sLen=strlen(temp);//读取子串长度
    file.read((char *)&s,sizeof(cunmin));

    while(!file.eof())
    {

        strcpy(temp2,s.GetName());
        int origin=strlen(temp2);         //读取原串长度
        for(i=0;i<=(origin-sLen);i++)    //遍历原来中的所有可能位置，依序进行比对
        {

        rec=0;
        for(j=0;j<sLen;j++)            //从当前位置开始进行比对，有不同即退出比对
        {
         if(temp2[i+j]!=temp[j])
            break;
         else
            rec++;                //在此计数用于退出比对后判断是否已找到串
        }
        if(rec==sLen)
                 {
                     s.Print();
                     k++;
                     cout<<endl;
                 }
        }
        file.read((char *)&s,sizeof(cunmin));
    }

    if(k==0)
    cout<<endl<<endl<<"系统无此村民信息"<<endl;

    file.close();
}

void Manager::xiugai()//修改村民信息
{
    cunmin s;
    cunmin m;
    fstream file;
    int bianhao,i=0;
    char change;
    file.open("cunmin.dat",ios::binary|ios::in|ios::out);

    if(file.fail())
    {
      cout<<"村民修改失败！"<<endl;
      exit(0);
    }
    cout<<"请输入你要修改的村民编号:";
    cin>>bianhao;
    file.read((char *)&s,sizeof(cunmin));

    while(!file.eof())
    {

       if(s.GetcID()==bianhao)
        {
            cout<<endl;
            s.Print();
            i++;
            cout<<endl<<"是否修改信息:";
            cin>>change;
            if(change=='Y')
            {
              cin.ignore();
              m.Insert();
              file.seekp(-(int)(sizeof(cunmin)),ios::cur);
              file.write((char *)&m,sizeof(cunmin));
              cout<<endl<<"修改成功!";
              break;
            }
          else
           {
             cout<<"删除失败！";
           }

        }
     if(i!=0)
           break;

     file.read((char *)&s,sizeof(cunmin));
    }


    if(i==0)
       {
           cout<<endl<<endl<<"系统无此村民信息"<<endl;
       }

    file.close();
}

void Manager::shanchu()//删除村民信息
{
    fstream file,file1;
    cunmin temp;
    char again;
    int bianhao,s=0;
    file.open("cunmin.dat",ios::in|ios::binary);
    //打开存储村民信息的文件
    file1.open("temp.dat",ios::out|ios::binary);
    //打开临时文件
    if(file.fail())
    {
    cout<<"修改模块调用失败!";
    exit(0);
    }

    if(file1.fail())
    {
    cout<<"修改模块调用失败!";
    exit(0);
    }

    cout<<"请输入你要删除村民的编号：";
    cin>>bianhao;
    file.read((char *)&temp,sizeof(temp));
    while(!file.eof())
    {
      if(temp.GetcID()==bianhao)
      {
          temp.Print();
          s++;
          break;
      }
      file.read((char *)&temp,sizeof(temp));
    }

    if(s==0)
       cout<<"无此村民信息!\n";
    else
    {
          cout<<"是否要删除该村民信息:";
          cin>>again;
          if(again=='Y')
           {
              file.seekg(0,ios::beg);
              file.read((char *)&temp,sizeof(temp));
              while(!file.eof())
                {
                      if(temp.GetcID()!=bianhao)
                     {
                       file1.write((char *)&temp,sizeof(temp));
                     }
                       file.read((char *)&temp,sizeof(temp));
                }
                cout<<"删除成功！"<<endl;

           }
          else
              {
                exit(0);
              }
    }

    file.close();
    file1.close();
    remove("cunmin.dat");//删除原文件
    rename("temp.dat","cunmin.dat");//将临时文件改名为原文件
}
