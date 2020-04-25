//Person.h
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <cstring>
#include "Date.h"
class  Person
{
   protected:
        Date birthday;//生日
        char sex;//性别
        char ID[19];//身份证号
        char name[20];//姓名
        char address[100];//地址
   public:
        Person();//缺省构造函数
        void Insert();//输入Person信息

        Person(const Person &obj1)//拷贝构造函数
         {
            birthday=obj1.birthday;
            strcpy(name,obj1.name);
            strcpy(address,obj1.address);
            strcpy(ID,obj1.ID);
            sex=obj1.sex;
        }

        Person operator =(const Person &obj1)//重载等于运算符号
        {
            birthday=obj1.birthday;
            strcpy(name,obj1.name);
            strcpy(address,obj1.address);
            strcpy(ID,obj1.ID);
            sex=obj1.sex;
            return *this;
        }

        virtual void Print();//定义虚函数

};


#endif // PERSON_H_INCLUDED
