//special.cpp
#include <iostream>
#include "Manager.h"
#include "cunmin.h"
using namespace std;
#include  <fstream>
#include  <conio.h>
#include  "other.h"
#include  "Goods.h"
void guanzhuce()//����Աע��
{
    Manager  g;
    int i=0,j=0;
    char ch;
    char pw[17];
    fstream  out;
    out.open("Manager.dat",ios::out|ios::binary|ios::app);
    if(out.fail())
    {
        cout<<"ע��ģ�����ʧ�ܣ�"<<endl;
        return ;
    }
    g.Insert();
    strcpy(pw,g.GetPassword());
	while(j<3)
	{
	    i=0;
	    cout<<"ȷ������:";
         while((ch =getch()) != '\r')
           {

                if(ch == '\b' && i >=0)
                {
                    printf("\b \b");
                    i--;
                }
                else
                    {
                        i++;
                        cout<<"*";
                    }

                if(pw[i-1]!=ch)
                {
                    cout<<"�������,����"<<(2-j)<<"�λ���!"<<endl;
                    j+=1;
                    break;
                }

          }
		cout<<endl;

		if(ch=='\r'&&pw[i]=='\0')
		{
			out.write((char *)&g,sizeof(Manager));
			cout<<"ע��ɹ�!"<<endl;
			break;
		}
	}
    out.close();

}


int guanVeri(char acc[])//����Ա��֤3��
{   Manager s;
    fstream  in;
    in.open("Manager.dat",ios::in|ios::binary);
    if(in.fail())
    {
        cout<<"��֤ģ�����ʧ�ܣ�"<<endl;
        return 0;
    }
    int i = 0;
    int times = 1;
    char ch;
    char pw[50];

     in.read((char *)&s,sizeof(Manager));
     while(!in.eof())
     {
        if(strcmp(s.GetAccount(),acc)==0)
              break;
        else
           in.read((char *)&s,sizeof(Manager));
    }
    if(strcmp(s.GetAccount(),acc)!=0)
          {
              cout<<"��������˻���������"<<endl;

              return 0;
          }
    cout<<"���������룺";
    while(times <= 3)
    {
        i = 0;
        while((ch = getch()) != '\r')
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if(strcmp(pw,s.GetPassword())!=0)
        {
            if(times == 3)
                cout << "��������˳���" << endl << endl;
            else
                cout << "�������ʣ��" << (3-times) << "�λ��᣺";
            times++;
        }
        else
        {
            cout << "������ȷ��" << endl << endl;
            in.close();
            return 1;
        }
    }

    if(times == 4)
    {
        in.close();
        return 0;
    }
    return 0;
}


void cunzhuce()//����ע�ắ��
{
    cunmin  g;
    int i=0,j=0;
    char ch;
    char pw[17];
    fstream  out;
    out.open("cunmin.dat",ios::out|ios::binary|ios::app);
    if(out.fail())
    {
        cout<<"ע��ģ�����ʧ�ܣ�"<<endl;
        return ;
    }
    g.Insert();
    strcpy(pw,g.GetPassword());
	while(j<3)
	{
	    i=0;
	    cout<<"ȷ������:";

		  while((ch =getch()) != '\r')
        {

            if(ch == '\b' && i >=0)
            {
                printf("\b \b");
                i--;
            }
            else
                {
                    i++;
                    cout<<"*";
                }

            if(pw[i-1]!=ch)
            {
                cout<<"�������,����"<<(2-j)<<"�λ���!"<<endl;
				j+=1;
				break;
            }

          }
		cout<<endl;

		if(ch=='\r'&&pw[i]=='\0')
		{
			out.write((char *)&g,sizeof(cunmin));
			cout<<"ע��ɹ�!"<<endl;
			break;
		}
	}
    out.close();

}


int cunVeri(char acc[])//������֤����
{   cunmin s;
    fstream  in;
    in.open("cunmin.dat",ios::in|ios::binary);
    if(in.fail())
    {
        cout<<"��֤ģ�����ʧ�ܣ�"<<endl;
        return 0;
    }
    int i = 0;
    int times = 1;
    char ch;
    char pw[50];

     in.read((char *)&s,sizeof(cunmin));
     while(!in.eof())
     {
        if(strcmp(s.GetAccount(),acc)==0)
              break;
        else
           in.read((char *)&s,sizeof(cunmin));
    }
    if(strcmp(s.GetAccount(),acc)!=0)
          {
              cout<<"��������˻���������"<<endl;
              return 0;
          }
    cout<<"���������룺";
    while(times <= 3)
    {
        i = 0;
        while((ch = getch()) != '\r')
        {
            if(ch == '\b' && i > 0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                pw[i++] = ch;
                cout << '*';
            }
        }
        pw[i] = '\0';
        cout << endl;
        if(strcmp(pw,s.GetPassword())!=0)
        {
            if(times == 3)
                cout << "��������˳���" << endl << endl;
            else
                cout << "�������ʣ��" << (3-times) << "�λ��᣺";
            times++;
        }
        else
        {
            cout << "������ȷ��" << endl << endl;
            in.close();
            return 1;
        }
    }


    if(times == 4)
    {
        in.close();
        return 0;
    }
    return 0;
}



void shangjia()//�ϼ���Ʒ����
{   Goods m;
    fstream file;
    char ch;
    if(file.fail())
    {
        cout<<"��Ʒ�ϼ�ʧ��!"<<endl;
        exit(0);
    }
    file.open("goods.dat",ios::out|ios::binary|ios::app);
    do
    {
        m.insert();
        file.write((char *)&m,sizeof(m));
        cout<<"�Ƿ����(��Y��N):"<<endl;
        cin>>ch;
        cin.ignore();
    }
    while(ch=='Y');
    cout<<"\n�ϼ�ũ��Ʒ����!";

}

void  xianshincp()//��ʾũ��Ʒ
{
    Goods m;
    fstream file;
    int j=0;
    char ch='Y';

    if(file.fail())
    {
        cout<<"��Ʒ��ʾʧ��!"<<endl;
        exit(0);
    }

    file.open("goods.dat",ios::in|ios::binary);
    file.read((char *)&m,sizeof(m));
      while(!file.eof()&&ch=='Y')
      {
          j++;
          m.Print();
          cout<<endl;
          file.read((char *)&m,sizeof(m));
          if(j==3)
          {
             cout<<endl;
             cout<<"��Y��ʾ��һҳ:";
             cin>>ch;
             j=0;
              system("cls");
          }


      }
      file.close();


}

void ygm()//��ʾ���빺�ﳵ�ĺ���
{
     fstream in;
     struct newbuy s;
     in.open("buytemp.dat",ios::in|ios::binary);

     if(in.fail())
     {
         cout<<"��ģ�����ʧ�ܣ�"<<endl;
         exit(0);
     }

     in.read((char *)&s,sizeof(s));

     cout<<"��������Ʒ����:\n";
     while(!in.eof())
     {
         cout<<"��Ʒ����:"
             <<s.name
             <<"   "
             <<"��������:"
             <<s.gmsl
             <<endl;
         in.read((char *)&s,sizeof(s));
     }
     in.close();
}

void shanchusp()//ɾ�����ﳵ�е���Ϣ
{
     fstream in,in2;
     struct newbuy s;
     char tname[20];
     char again;
     in.open("buytemp.dat",ios::in|ios::binary);
     in2.open("buytemp2.dat",ios::out|ios::binary);
     if(in.fail())
     {
         exit(0);
     }
     if(in2.fail())
     {
         exit(0);
     }
     cout<<"��������Ҫɾ������Ʒ:\n";
     cin.getline(tname,20);
     in.read((char *)&s,sizeof(s));
	 while(!in.eof())
	   {
		if(strcmp(s.name,tname)==0)
              {

                  cout<<"��Ʒ����:";
                  cout<<s.name;
                  cout<<"\n��Ʒ����:";
                  cout<<s.gmsl<<endl;
                  break;
              }
	      	 in.read((char *)&s,sizeof(s));
    }

       cout<<"�Ƿ�Ҫɾ������Ʒ:";
       cin>>again;
           if(again=='Y')
			{
			      in.seekg(0,ios::beg);
                   in.read((char *)&s,sizeof(s));
						while(!in.eof())
						{

                             if(strcmp(s.name,tname)!=0)
                             {
                           	     in2.write((char *)&s,sizeof(s));
                             }


						   in.read((char *)&s,sizeof(s));
		          	    }

		            cout<<"ɾ���ɹ���"<<endl;

	        }
	     else
	       {
		     exit(0);
      	   }

	   in.close();
	   in2.close();

	   remove("buytemp.dat");//ɾ����ʱ��ƷԴ�ļ�
       rename("buytemp2.dat","buytemp.dat");//����ʱ�ļ�����ΪԴ�ļ�

}




