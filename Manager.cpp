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

Manager::Manager()//ȱʡ���캯��
{

    gID=1001;
	strcpy(zhiwu,"cunzhang");
	strcpy(account,"000000000000");
	strcpy(password,"00000000000000");
}

void Manager::Insert()//�������Ա��Ϣ
{   char ch;
    int i=0;
    Person::Insert();
    cout<<"����Ա���:";
    cin>>gID;
    cin.ignore();
    cout<<"����Աְ��:";
    cin.getline(zhiwu,20);
    cout<<"����Ա�˺�:";
    cin.getline(account,20);
    cout<<"����Ա����:";
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

void Manager::Print()//��ӡ����Ա��Ϣ
{
    cout<<endl<<"����Ա��Ϣ����:"<<endl;
    cout<<"����:"<<name<<endl;
	if(sex=='M'||sex=='m')
		cout<<"�Ա�:"<<"��"<<endl;
	if(sex=='f'||sex=='F')
		cout<<"�Ա�:"<<"Ů"<<endl;
	cout<<"�� ַ:"<<address<<endl;
	cout<<"��������:";
	birthday.Print();
	cout<<"���֤��:"<<ID<<endl;
    cout<<"ְ��:"<<zhiwu<<endl;
    cout<<"����Ա���:"<<gID<<endl;
}

void Manager::fbgs()//����Ա�������溯��
{
    fstream file;
    file.open("gongshi.txt",ios::out);
    //�˴��ļ�Ϊд������
    char ch;

    if(file.fail())
    {
        cout<<"\t\t\t\t\t������ʾ��Ϣʧ��"<<endl;
        exit(0);
    }

    cout<<"\t\t\t\t\t********������ʾ********"<<endl<<endl;
    cout<<"\t\t\t\t\t   ��������   ����ǰ��"<<endl;

    time_t t = time(NULL);
	struct tm *pt = localtime(&t);
	cout<<"\t����:"<<pt->tm_year+1900<<"��"<<pt->tm_mon+1<<"��"<<pt->tm_mday<<"��";

    cout<<"\t\t\t\t\t\t\t  ��ǰ����Ա:"<<name<<endl;
    cout<<"\t---------------------------------------------------------------------------------------------------\t"<<endl;
    cout<<"��������Ҫ��������Ϣ���Լ���'-1'��������"<<endl;
    char s[500];
    cin.getline(s,500);

    while(1)
    {   if(strcmp(s,"-1")==0)
                {
                    cout<<endl<<endl<<"�Ƿ������Ϣ��������Y��N����";
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

    file.seekp(0,ios::end);//��дָ��������
    cout<<endl<<"������Ϣ�ɹ�!"<<endl;
    file.close();

}


void Manager::xianshi()//��ʾ������Ϣ
{
    cunmin s;
    fstream in;
    char ch='Y';
    int j=0;//��������j,��ͼΪ��ʾʱÿҳֻ��ʾ3��������Ϣ
    in.open("cunmin.dat",ios::in|ios::binary);//cunmin.dat����Ŵ�����Ϣ

    if(in.fail())
    {
      cout<<"������ʾʧ�ܣ�"<<endl;
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
           cout<<"��Y��ʾ��һҳ:";
           cin>>ch;
           j=0;
           system("cls");//����
        }
    }

      in.close();
}

void Manager::search()//����������Ϣ
{
    cunmin s;
    fstream file;
    char temp[20];
    int i,j,rec,k=0;//k�ж��Ƿ���ҳɹ�
    char temp2[20];
    file.open("cunmin.dat",ios::binary|ios::in);
    if(file.fail())
    {
      cout<<"�����ѯʧ�ܣ�"<<endl;
      exit(0);
    }

    cout<<"��������Ҫ���ҵĴ���(֧��ģ����ѯ):";
    cin.getline(temp,20);
    int sLen=strlen(temp);//��ȡ�Ӵ�����
    file.read((char *)&s,sizeof(cunmin));

    while(!file.eof())
    {

        strcpy(temp2,s.GetName());
        int origin=strlen(temp2);         //��ȡԭ������
        for(i=0;i<=(origin-sLen);i++)    //����ԭ���е����п���λ�ã�������бȶ�
        {

        rec=0;
        for(j=0;j<sLen;j++)            //�ӵ�ǰλ�ÿ�ʼ���бȶԣ��в�ͬ���˳��ȶ�
        {
         if(temp2[i+j]!=temp[j])
            break;
         else
            rec++;                //�ڴ˼��������˳��ȶԺ��ж��Ƿ����ҵ���
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
    cout<<endl<<endl<<"ϵͳ�޴˴�����Ϣ"<<endl;

    file.close();
}

void Manager::xiugai()//�޸Ĵ�����Ϣ
{
    cunmin s;
    cunmin m;
    fstream file;
    int bianhao,i=0;
    char change;
    file.open("cunmin.dat",ios::binary|ios::in|ios::out);

    if(file.fail())
    {
      cout<<"�����޸�ʧ�ܣ�"<<endl;
      exit(0);
    }
    cout<<"��������Ҫ�޸ĵĴ�����:";
    cin>>bianhao;
    file.read((char *)&s,sizeof(cunmin));

    while(!file.eof())
    {

       if(s.GetcID()==bianhao)
        {
            cout<<endl;
            s.Print();
            i++;
            cout<<endl<<"�Ƿ��޸���Ϣ:";
            cin>>change;
            if(change=='Y')
            {
              cin.ignore();
              m.Insert();
              file.seekp(-(int)(sizeof(cunmin)),ios::cur);
              file.write((char *)&m,sizeof(cunmin));
              cout<<endl<<"�޸ĳɹ�!";
              break;
            }
          else
           {
             cout<<"ɾ��ʧ�ܣ�";
           }

        }
     if(i!=0)
           break;

     file.read((char *)&s,sizeof(cunmin));
    }


    if(i==0)
       {
           cout<<endl<<endl<<"ϵͳ�޴˴�����Ϣ"<<endl;
       }

    file.close();
}

void Manager::shanchu()//ɾ��������Ϣ
{
    fstream file,file1;
    cunmin temp;
    char again;
    int bianhao,s=0;
    file.open("cunmin.dat",ios::in|ios::binary);
    //�򿪴洢������Ϣ���ļ�
    file1.open("temp.dat",ios::out|ios::binary);
    //����ʱ�ļ�
    if(file.fail())
    {
    cout<<"�޸�ģ�����ʧ��!";
    exit(0);
    }

    if(file1.fail())
    {
    cout<<"�޸�ģ�����ʧ��!";
    exit(0);
    }

    cout<<"��������Ҫɾ������ı�ţ�";
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
       cout<<"�޴˴�����Ϣ!\n";
    else
    {
          cout<<"�Ƿ�Ҫɾ���ô�����Ϣ:";
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
                cout<<"ɾ���ɹ���"<<endl;

           }
          else
              {
                exit(0);
              }
    }

    file.close();
    file1.close();
    remove("cunmin.dat");//ɾ��ԭ�ļ�
    rename("temp.dat","cunmin.dat");//����ʱ�ļ�����Ϊԭ�ļ�
}
