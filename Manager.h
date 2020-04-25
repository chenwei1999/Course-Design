//Manager.h
#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "Person.h"

class Manager:public Person//Manager��̳���Person��
{
 private:
      int gID;//����Ա���
     char zhiwu[20];//�峤������ǵ�
     char account[20];//����Ա�˺�
     char password[50];//����Ա����
 public:
      Manager();//ȱʡ���캯��

      Manager(const Manager &obj)//Manager�Ŀ������캯��
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


        Manager operator =(const Manager &obj1)//����=�����
       {
        strcpy(zhiwu,obj1.zhiwu);
        strcpy(account,obj1.account);
        strcpy(password,obj1.password);
        gID=obj1.gID;
        Person::operator =(obj1);
        return *this;
       }


      void Insert();//�������Ա��Ϣ

      void Print();//�������Ա��Ϣ

      void  fbgs();//����Ա��������

      char*  GetPassword()//��������
      {
          return password;
      }

      char* GetAccount()//�����˺�
      {
           return account;
      }

      char* GetName()//���ع���Ա����
      {
           return name;
      }

      void xianshi();//��ʾ������Ϣ

      void search();//��������

      void xiugai();//�޸Ĵ�����Ϣ

      void shanchu();//ɾ��������Ϣ
};




#endif // MANAGER_H_INCLUDED
