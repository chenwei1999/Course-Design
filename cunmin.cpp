//cunmin.cpp
#include "cunmin.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include "Goods.h"
#include "other.h"
#include <cstdlib>
using namespace std;

cunmin::cunmin()//缺省构造函数
{
	cID=1001;
	zhichu=0;
	strcpy(account,"000000000000");
	strcpy(password,"00000000000000");
	dang='s';
}

void cunmin::Insert()//输入村民信息
{

    char ch;
    int i=0,j;
    Person::Insert();
    cout<<"村民编号:";
    cin>>cID;
    cout<<"政治面貌（1.党员 2.群众）:";
    cin>>j;
    if(j==1)
          dang='s';
    else
          dang='f';
    cin.ignore();
    cout<<"村民账号:";
    cin.getline(account,20);
    cout<<"村民密码:";
    while((ch =getch()) != '\r')//getch函数可以在屏幕上无回显
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");//如果此时遇到返回键，屏幕上也应该减少一个输出
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
	  i++;
}

void cunmin::Print()//输出村民信息
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
	if(dang=='s')
         cout<<"政治面貌:中共党员"<<endl;
    else if(dang=='f')
         cout<<"政治面貌:群众"<<endl;
    cout<<"村民编号:"<<cID<<endl;
}

void cunmin::goumai()//村民购买商品
{
    fstream file,file1;//file用于打开存放商品的文件，file2用于打开临时购买文件
    Goods m;
    struct newbuy s;
    char ch;
    char tname[20];
    int j=0;//j用于判断文件中能否查到数据
    int sl;
    file.open("goods.dat",ios::in|ios::binary);
    file1.open("buytemp.dat",ios::out|ios::binary|ios::app);
    if(file.fail())
    {
        cout<<"此处功能调用失败"<<endl;
        exit(0);
    }
    if(file1.fail())
    {
        cout<<"此处功能调用失败"<<endl;
        exit(0);
    }
    cout<<"请输入商品名称:";
    cin.getline(tname,20);
    file.read((char *)&m,sizeof(m));
    while(!file.eof())
    {
        if(strcmp(tname,m.Getname())==0)
        { m.Print();
          j++;
          cout<<"是否要购买(是Y否N):";
          cin>>ch;
          if(ch=='Y')
          {
            s.bh=m.GetNO();
            strcpy(s.name,m.Getname());
            cout<<"请输入你要购买的数量:";
            cin>>sl;
            s.gmsl=sl;
            file1.write((char *)&s,sizeof(s));//此时将商品临时信息存入临时文件
          }
        }
         file.read((char *)&m,sizeof(m));
    }
    if(j==0)
       cout<<"无此商品!";
    file.close();
    file1.close();
}



void cunmin::algoumai()//查看村民已经购买的商品
{    struct newbuy s;
     fstream file;
     char filename[20];
     char buf[10];
     itoa(cID, buf, 10);
     strcpy(filename,buf);
     strcat(filename,"s.dat");
     file.open(filename,ios::in|ios::binary);
     file.read((char *)&s,sizeof(s));
     while(!file.eof())
     {
          cout<<"商品名称:"
             <<s.name
             <<"   "
             <<"购买数量:"
             <<s.gmsl
             <<endl;
         file.read((char *)&s,sizeof(s));
     }

     file.close();
}
void cunmin::jiezhang()//结账功能
{
    struct newbuy s;
    Goods  m;
    char filename[20];
    char buf[10];
    itoa(cID, buf, 10);//将村民编号转化为字符串
    fstream file1,file2,file3,fileout;
    //file1:打开临时购物信息
    //file2：新建一个保存此对象购物信息的文件
    //file3：打开存放商品的文件，用于修改商品库存

    strcpy(filename,buf);
    strcat(filename,"s.dat");;

    file1.open("buytemp.dat",ios::in|ios::binary);
    file2.open(filename,ios::out|ios::binary|ios::app);
    file3.open("goods.dat",ios::out|ios::binary|ios::in);

    if(file1.fail())
    {
        cout<<"此处功能调用失败"<<endl;
        exit(0);
    }

    if(file2.fail())
    {
        cout<<"此处功能调用失败"<<endl;
        exit(0);
    }

    if(file3.fail())
    {
        cout<<"此处功能调用失败"<<endl;
        exit(0);
    }


    file1.read((char *)&s,sizeof(s));
    while(!file1.eof())
    {
         file3.read((char *)&m,sizeof(m));
         while(!file3.eof())
         {
             if(m.GetNO()==s.bh)
              {   m.Putnumber(s.gmsl);//修改库存
                  file3.seekp(-(int)sizeof(m),ios::cur);//将写指针前置一个大小
                  file3.write((char *)&m,sizeof(m));//重新写入库存信息
                  file2.write((char *)&s,sizeof(s));//将此购物信息写入对象文件
              }
              file3.read((char *)&m,sizeof(m));
         }
         file1.read((char *)&s,sizeof(s));
    }

    file1.close();
    file2.close();
    file3.close();

    cout<<"\n结账成功，欢迎下次光临！\n";
    fileout.open("buytemp.dat",ios::out|ios::binary);//试图将buytemp.dat文件删空所存信息
    if(fileout.fail())
    {
        cout << "Create file failure...\n";
        exit(0);
    }

    fileout.close();

}








