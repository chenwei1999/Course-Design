//cunmin.h
#ifndef CUNMIN_H_INCLUDED
#define CUNMIN_H_INCLUDED
#include "Person.h"

class  cunmin:public Person//cunmin类->继承Person类
{
  private:
       int  cID;//记录村民编号
       int  zhichu;//记录村民支出
       char dang;//党员为s，非党员为f
       char account[20];//记录村民账号
       char password[20];//记录村民密码
  public:
        cunmin();//缺省构造函数

        cunmin(const cunmin &obj)//cunmin的拷贝构造函数
       {
         strcpy(account,obj.account);
         strcpy(password,obj.password);
         cID=obj.cID;
         birthday=obj.birthday;
         strcpy(name,obj.name);
         strcpy(address,obj.address);
         strcpy(ID,obj.ID);
         sex=obj.sex;
         zhichu=obj.zhichu;
         dang=obj.dang;
     }


        cunmin operator =(const cunmin &obj1)//重载=运算符
        {
            cID=obj1.cID;
            zhichu=obj1.zhichu;
            dang=obj1.dang;
            strcpy(account,obj1.account);
            strcpy(password,obj1.password);
            Person::operator =(obj1);
            return *this;
        }

      char* GetPassword()//返回密码
      {
          return password;
      }

      char*  GetAccount()//返回账号信息
      {
           return account;
      }

      char*  GetName()//返回姓名
      {
           return name;
      }

      void Insert();//输入村民信息

      void Print();//输出打印村民信息

      int  shengri()//判断村民是否过生日
      {
          if(birthday.gift()==1)//gift函数写在Date.h
               return 1;
          else
               return 0;
      }


      int GetcID()//返回村民编号
      {
          return cID;
      }

      void goumai();//村民购买商品

      void algoumai();//查看村民已经购买的商品

      void jiezhang();//村民结账功能
};


#endif // CUNMIN_H_INCLUDED
