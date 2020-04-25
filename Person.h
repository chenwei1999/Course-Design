//Person.h
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <cstring>
#include "Date.h"
class  Person
{
   protected:
        Date birthday;//����
        char sex;//�Ա�
        char ID[19];//���֤��
        char name[20];//����
        char address[100];//��ַ
   public:
        Person();//ȱʡ���캯��
        void Insert();//����Person��Ϣ

        Person(const Person &obj1)//�������캯��
         {
            birthday=obj1.birthday;
            strcpy(name,obj1.name);
            strcpy(address,obj1.address);
            strcpy(ID,obj1.ID);
            sex=obj1.sex;
        }

        Person operator =(const Person &obj1)//���ص����������
        {
            birthday=obj1.birthday;
            strcpy(name,obj1.name);
            strcpy(address,obj1.address);
            strcpy(ID,obj1.ID);
            sex=obj1.sex;
            return *this;
        }

        virtual void Print();//�����麯��

};


#endif // PERSON_H_INCLUDED
