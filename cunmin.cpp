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

cunmin::cunmin()//ȱʡ���캯��
{
	cID=1001;
	zhichu=0;
	strcpy(account,"000000000000");
	strcpy(password,"00000000000000");
	dang='s';
}

void cunmin::Insert()//���������Ϣ
{

    char ch;
    int i=0,j;
    Person::Insert();
    cout<<"������:";
    cin>>cID;
    cout<<"������ò��1.��Ա 2.Ⱥ�ڣ�:";
    cin>>j;
    if(j==1)
          dang='s';
    else
          dang='f';
    cin.ignore();
    cout<<"�����˺�:";
    cin.getline(account,20);
    cout<<"��������:";
    while((ch =getch()) != '\r')//getch������������Ļ���޻���
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");//�����ʱ�������ؼ�����Ļ��ҲӦ�ü���һ�����
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

void cunmin::Print()//���������Ϣ
{


    cout<<"����:"<<name<<endl;
	if(sex=='M'||sex=='m')
		cout<<"�Ա�:"<<"��"<<endl;
	if(sex=='f'||sex=='F')
		cout<<"�Ա�:"<<"Ů"<<endl;
	cout<<"�� ַ:"<<address<<endl;
	cout<<"��������:";
	birthday.Print();
	cout<<"���֤��:"<<ID<<endl;
	if(dang=='s')
         cout<<"������ò:�й���Ա"<<endl;
    else if(dang=='f')
         cout<<"������ò:Ⱥ��"<<endl;
    cout<<"������:"<<cID<<endl;
}

void cunmin::goumai()//��������Ʒ
{
    fstream file,file1;//file���ڴ򿪴����Ʒ���ļ���file2���ڴ���ʱ�����ļ�
    Goods m;
    struct newbuy s;
    char ch;
    char tname[20];
    int j=0;//j�����ж��ļ����ܷ�鵽����
    int sl;
    file.open("goods.dat",ios::in|ios::binary);
    file1.open("buytemp.dat",ios::out|ios::binary|ios::app);
    if(file.fail())
    {
        cout<<"�˴����ܵ���ʧ��"<<endl;
        exit(0);
    }
    if(file1.fail())
    {
        cout<<"�˴����ܵ���ʧ��"<<endl;
        exit(0);
    }
    cout<<"��������Ʒ����:";
    cin.getline(tname,20);
    file.read((char *)&m,sizeof(m));
    while(!file.eof())
    {
        if(strcmp(tname,m.Getname())==0)
        { m.Print();
          j++;
          cout<<"�Ƿ�Ҫ����(��Y��N):";
          cin>>ch;
          if(ch=='Y')
          {
            s.bh=m.GetNO();
            strcpy(s.name,m.Getname());
            cout<<"��������Ҫ���������:";
            cin>>sl;
            s.gmsl=sl;
            file1.write((char *)&s,sizeof(s));//��ʱ����Ʒ��ʱ��Ϣ������ʱ�ļ�
          }
        }
         file.read((char *)&m,sizeof(m));
    }
    if(j==0)
       cout<<"�޴���Ʒ!";
    file.close();
    file1.close();
}



void cunmin::algoumai()//�鿴�����Ѿ��������Ʒ
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
          cout<<"��Ʒ����:"
             <<s.name
             <<"   "
             <<"��������:"
             <<s.gmsl
             <<endl;
         file.read((char *)&s,sizeof(s));
     }

     file.close();
}
void cunmin::jiezhang()//���˹���
{
    struct newbuy s;
    Goods  m;
    char filename[20];
    char buf[10];
    itoa(cID, buf, 10);//��������ת��Ϊ�ַ���
    fstream file1,file2,file3,fileout;
    //file1:����ʱ������Ϣ
    //file2���½�һ������˶�������Ϣ���ļ�
    //file3���򿪴����Ʒ���ļ��������޸���Ʒ���

    strcpy(filename,buf);
    strcat(filename,"s.dat");;

    file1.open("buytemp.dat",ios::in|ios::binary);
    file2.open(filename,ios::out|ios::binary|ios::app);
    file3.open("goods.dat",ios::out|ios::binary|ios::in);

    if(file1.fail())
    {
        cout<<"�˴����ܵ���ʧ��"<<endl;
        exit(0);
    }

    if(file2.fail())
    {
        cout<<"�˴����ܵ���ʧ��"<<endl;
        exit(0);
    }

    if(file3.fail())
    {
        cout<<"�˴����ܵ���ʧ��"<<endl;
        exit(0);
    }


    file1.read((char *)&s,sizeof(s));
    while(!file1.eof())
    {
         file3.read((char *)&m,sizeof(m));
         while(!file3.eof())
         {
             if(m.GetNO()==s.bh)
              {   m.Putnumber(s.gmsl);//�޸Ŀ��
                  file3.seekp(-(int)sizeof(m),ios::cur);//��дָ��ǰ��һ����С
                  file3.write((char *)&m,sizeof(m));//����д������Ϣ
                  file2.write((char *)&s,sizeof(s));//���˹�����Ϣд������ļ�
              }
              file3.read((char *)&m,sizeof(m));
         }
         file1.read((char *)&s,sizeof(s));
    }

    file1.close();
    file2.close();
    file3.close();

    cout<<"\n���˳ɹ�����ӭ�´ι��٣�\n";
    fileout.open("buytemp.dat",ios::out|ios::binary);//��ͼ��buytemp.dat�ļ�ɾ��������Ϣ
    if(fileout.fail())
    {
        cout << "Create file failure...\n";
        exit(0);
    }

    fileout.close();

}








