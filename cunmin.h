//cunmin.h
#ifndef CUNMIN_H_INCLUDED
#define CUNMIN_H_INCLUDED
#include "Person.h"

class  cunmin:public Person//cunmin��->�̳�Person��
{
  private:
       int  cID;//��¼������
       int  zhichu;//��¼����֧��
       char dang;//��ԱΪs���ǵ�ԱΪf
       char account[20];//��¼�����˺�
       char password[20];//��¼��������
  public:
        cunmin();//ȱʡ���캯��

        cunmin(const cunmin &obj)//cunmin�Ŀ������캯��
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


        cunmin operator =(const cunmin &obj1)//����=�����
        {
            cID=obj1.cID;
            zhichu=obj1.zhichu;
            dang=obj1.dang;
            strcpy(account,obj1.account);
            strcpy(password,obj1.password);
            Person::operator =(obj1);
            return *this;
        }

      char* GetPassword()//��������
      {
          return password;
      }

      char*  GetAccount()//�����˺���Ϣ
      {
           return account;
      }

      char*  GetName()//��������
      {
           return name;
      }

      void Insert();//���������Ϣ

      void Print();//�����ӡ������Ϣ

      int  shengri()//�жϴ����Ƿ������
      {
          if(birthday.gift()==1)//gift����д��Date.h
               return 1;
          else
               return 0;
      }


      int GetcID()//���ش�����
      {
          return cID;
      }

      void goumai();//��������Ʒ

      void algoumai();//�鿴�����Ѿ��������Ʒ

      void jiezhang();//������˹���
};


#endif // CUNMIN_H_INCLUDED
