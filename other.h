#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED
//此头文件为函数声明专用

void gsjm();//显示公示栏
void shijian();//显示时间
void mainmenu();//主菜单
void villmenu();//村民菜单
void guanmenu();//管理员菜单
void wangye();//打开网页
void guanzhuce();//管理员注册
int  guanVeri(char acc[]);//管理员验证
void guanjiemian( char acc[] );//管理员界面
int  cunVeri(char acc[]);//村民验证
void cunjiemian( char acc[] );//村民界面
void cunzhuce();//村民注册
void shangjia();//上架商品
void  xianshincp();//显示农产品信息
void  gouwuche(int);//购物车界面
struct newbuy//存入购买商品的结构体
{
    int bh;
    char name[20];
    int  gmsl;

};
void shanchusp();//删除购物车中的农产品信息
void ygm();//显示已经在购物车中的商品信息
#endif // OTHER_H_INCLUDED
