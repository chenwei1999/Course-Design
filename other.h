#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED
//��ͷ�ļ�Ϊ��������ר��

void gsjm();//��ʾ��ʾ��
void shijian();//��ʾʱ��
void mainmenu();//���˵�
void villmenu();//����˵�
void guanmenu();//����Ա�˵�
void wangye();//����ҳ
void guanzhuce();//����Աע��
int  guanVeri(char acc[]);//����Ա��֤
void guanjiemian( char acc[] );//����Ա����
int  cunVeri(char acc[]);//������֤
void cunjiemian( char acc[] );//�������
void cunzhuce();//����ע��
void shangjia();//�ϼ���Ʒ
void  xianshincp();//��ʾũ��Ʒ��Ϣ
void  gouwuche(int);//���ﳵ����
struct newbuy//���빺����Ʒ�Ľṹ��
{
    int bh;
    char name[20];
    int  gmsl;

};
void shanchusp();//ɾ�����ﳵ�е�ũ��Ʒ��Ϣ
void ygm();//��ʾ�Ѿ��ڹ��ﳵ�е���Ʒ��Ϣ
#endif // OTHER_H_INCLUDED
