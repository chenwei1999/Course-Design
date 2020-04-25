//Manager.h
#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "Person.h"

class Manager:public Person//Manager类继承了Person类
{
 private:
      int gID;//管理员编号
     char zhiwu[20];//村长，村书记等
     char account[20];//管理员账号
     char password[50];//管理员密码
 public:
      Manager();//缺省构造函数

      Manager(const Manager &obj)//Manager的拷贝构造函数
     {
        strcpy(zhiwu,obj.zhiwu);
        strcpy(account,obj.account);
        strcpy(password,obj.password);
        gID=obj.gID;
        birthday=obj.birthday;
        strcpy(name,obj.name);
        strcpy(address,obj.address);
        strcpy(ID,obj.ID);
        sex=obj.sex;
     }


        Manager operator =(const Manager &obj1)//重载=运算符
       {
        strcpy(zhiwu,obj1.zhiwu);
        strcpy(account,obj1.account);
        strcpy(password,obj1.password);
        gID=obj1.gID;
        Person::operator =(obj1);
        return *this;
       }


      void Insert();//输入管理员信息

      void Print();//输出管理员信息

      void  fbgs();//管理员发布公告

      char*  GetPassword()//返回密码
      {
          return password;
      }

      char* GetAccount()//返回账号
      {
           return account;
      }

      char* GetName()//返回管理员姓名
      {
           return name;
      }

      void xianshi();//显示村民信息

      void search();//搜索村民

      void xiugai();//修改村民信息

      void shanchu();//删除村民信息
};




#endif // MANAGER_H_INCLUDED
