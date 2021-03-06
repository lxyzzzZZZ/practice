/*************************************************************
					  lcd1602头文件

实现功能：lcd1602的控制

补充说明：
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602引脚定义*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602函数声明*******************/
void lcd_init(void);								   //初始化函数
void lcd_write_command(uchar command);				   //写指令函数
void lcd_write_data(uchar dat);						   //写数据函数
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //显示一个字符,  x(0-16),y(1-2)。
void lcd1602_write_character(uchar x, uchar y, uchar *p);//显示一个字符串,x(0-16),y(1-2)。
void lcd1602_write_pic(uchar add, uchar *pic_num);      //写入自定义字符
void delay_n40us(uint n);							   //延时函数

/*****************lcd1602自定义字符“℃”*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602显示的字符数组

/********************************************************
函数名称:void lcd_init(void)
函数作用:lcd1602初始化函数
参数说明:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7 
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x0c);//整体显示，关光标，不闪烁
	lcd_write_command(0x06);//设定输入方式，增量不移位
	lcd_write_command(0x01);//清除屏幕显示
	delay_n40us(100);//实践证明，我的 lcd1602 上，用 for 循环 200 次就能可靠完成清屏指令。
}

/********************************************************
函数名称:void lcd_write_command(uchar dat)
函数作用:lcd1602写命令
参数说明:dat为指令，参考数据手册
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//指令
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);//实践证明，我的 lcd1602 上，用 for 循环 1 次就能完成普通	写指令。
}

/********************************************************
函数名称:void lcd_write_data(uchar dat)
函数作用:lcd1602写数据
参数说明:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//数据
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
函数名称:void lcd_disp_char(uchar x,uchar y,uchar dat)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）显示一个字符dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);//写入需要显示的地址 
	lcd_write_data(dat);   //写入需要显示的内容
}

/********************************************************
函数名称:lcd1602_write_character(uchar x,uchar y,uchar *p)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）开始显示字符串*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);  //写入需要显示的地址 
	while (*p != '\0') 	     //写入需要显示的内容，直到字符串全部显示完成
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
函数名称:void lcd1602_write_pic(uchar add,uchar *pic_num)
函数作用:lcd1602写入自定义字符
参数说明:在add地址写入自定义字符代码
********************************************************/
void lcd1602_write_pic(uchar add, uchar *pic_num)
{
	unsigned char i;
	add = add << 3;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command(0x40 | add + i);
		lcd_write_data(*pic_num++);
	}
}

/********************************************************
函数名称:void delay_n40us(uint n)
函数作用:lcd1602延时函数
参数说明:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602头文件

实现功能：lcd1602的控制

补充说明：
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602引脚定义*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602函数声明*******************/
void lcd_init(void);								   //初始化函数
void lcd_write_command(uchar command);				   //写指令函数
void lcd_write_data(uchar dat);						   //写数据函数
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //显示一个字符,  x(0-16),y(1-2)。
void lcd1602_write_character(uchar x, uchar y, uchar *p);//显示一个字符串,x(0-16),y(1-2)。
void lcd1602_write_pic(uchar add, uchar *pic_num);      //写入自定义字符
void delay_n40us(uint n);							   //延时函数

/*****************lcd1602自定义字符“℃”*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602显示的字符数组

/********************************************************
函数名称:void lcd_init(void)
函数作用:lcd1602初始化函数
参数说明:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7 
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x0c);//整体显示，关光标，不闪烁
	lcd_write_command(0x06);//设定输入方式，增量不移位
	lcd_write_command(0x01);//清除屏幕显示
	delay_n40us(100);//实践证明，我的 lcd1602 上，用 for 循环 200 次就能可靠完成清屏指令。
}

/********************************************************
函数名称:void lcd_write_command(uchar dat)
函数作用:lcd1602写命令
参数说明:dat为指令，参考数据手册
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//指令
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);//实践证明，我的 lcd1602 上，用 for 循环 1 次就能完成普通	写指令。
}

/********************************************************
函数名称:void lcd_write_data(uchar dat)
函数作用:lcd1602写数据
参数说明:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//数据
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
函数名称:void lcd_disp_char(uchar x,uchar y,uchar dat)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）显示一个字符dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);//写入需要显示的地址 
	lcd_write_data(dat);   //写入需要显示的内容
}

/********************************************************
函数名称:lcd1602_write_character(uchar x,uchar y,uchar *p)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）开始显示字符串*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);  //写入需要显示的地址 
	while (*p != '\0') 	     //写入需要显示的内容，直到字符串全部显示完成
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
函数名称:void lcd1602_write_pic(uchar add,uchar *pic_num)
函数作用:lcd1602写入自定义字符
参数说明:在add地址写入自定义字符代码
********************************************************/
void lcd1602_write_pic(uchar add, uchar *pic_num)
{
	unsigned char i;
	add = add << 3;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command(0x40 | add + i);
		lcd_write_data(*pic_num++);
	}
}

/********************************************************
函数名称:void delay_n40us(uint n)
函数作用:lcd1602延时函数
参数说明:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602头文件

实现功能：lcd1602的控制

补充说明：
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602引脚定义*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602函数声明*******************/
void lcd_init(void);								   //初始化函数
void lcd_write_command(uchar command);				   //写指令函数
void lcd_write_data(uchar dat);						   //写数据函数
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //显示一个字符,  x(0-16),y(1-2)。
void lcd1602_write_character(uchar x, uchar y, uchar *p);//显示一个字符串,x(0-16),y(1-2)。
void lcd1602_write_pic(uchar add, uchar *pic_num);      //写入自定义字符
void delay_n40us(uint n);							   //延时函数

/*****************lcd1602自定义字符“℃”*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602显示的字符数组

/********************************************************
函数名称:void lcd_init(void)
函数作用:lcd1602初始化函数
参数说明:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7 
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x0c);//整体显示，关光标，不闪烁
	lcd_write_command(0x06);//设定输入方式，增量不移位
	lcd_write_command(0x01);//清除屏幕显示
	delay_n40us(100);//实践证明，我的 lcd1602 上，用 for 循环 200 次就能可靠完成清屏指令。
}

/********************************************************
函数名称:void lcd_write_command(uchar dat)
函数作用:lcd1602写命令
参数说明:dat为指令，参考数据手册
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//指令
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);//实践证明，我的 lcd1602 上，用 for 循环 1 次就能完成普通	写指令。
}

/********************************************************
函数名称:void lcd_write_data(uchar dat)
函数作用:lcd1602写数据
参数说明:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//数据
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
函数名称:void lcd_disp_char(uchar x,uchar y,uchar dat)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）显示一个字符dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);//写入需要显示的地址 
	lcd_write_data(dat);   //写入需要显示的内容
}

/********************************************************
函数名称:lcd1602_write_character(uchar x,uchar y,uchar *p)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）开始显示字符串*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);  //写入需要显示的地址 
	while (*p != '\0') 	     //写入需要显示的内容，直到字符串全部显示完成
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
函数名称:void lcd1602_write_pic(uchar add,uchar *pic_num)
函数作用:lcd1602写入自定义字符
参数说明:在add地址写入自定义字符代码
********************************************************/
void lcd1602_write_pic(uchar add, uchar *pic_num)
{
	unsigned char i;
	add = add << 3;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command(0x40 | add + i);
		lcd_write_data(*pic_num++);
	}
}

/********************************************************
函数名称:void delay_n40us(uint n)
函数作用:lcd1602延时函数
参数说明:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602头文件

实现功能：lcd1602的控制

补充说明：
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602引脚定义*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602函数声明*******************/
void lcd_init(void);								   //初始化函数
void lcd_write_command(uchar command);				   //写指令函数
void lcd_write_data(uchar dat);						   //写数据函数
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //显示一个字符,  x(0-16),y(1-2)。
void lcd1602_write_character(uchar x, uchar y, uchar *p);//显示一个字符串,x(0-16),y(1-2)。
void lcd1602_write_pic(uchar add, uchar *pic_num);      //写入自定义字符
void delay_n40us(uint n);							   //延时函数

/*****************lcd1602自定义字符“℃”*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602显示的字符数组

/********************************************************
函数名称:void lcd_init(void)
函数作用:lcd1602初始化函数
参数说明:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7 
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x0c);//整体显示，关光标，不闪烁
	lcd_write_command(0x06);//设定输入方式，增量不移位
	lcd_write_command(0x01);//清除屏幕显示
	delay_n40us(100);//实践证明，我的 lcd1602 上，用 for 循环 200 次就能可靠完成清屏指令。
}

/********************************************************
函数名称:void lcd_write_command(uchar dat)
函数作用:lcd1602写命令
参数说明:dat为指令，参考数据手册
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//指令
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);//实践证明，我的 lcd1602 上，用 for 循环 1 次就能完成普通	写指令。
}

/********************************************************
函数名称:void lcd_write_data(uchar dat)
函数作用:lcd1602写数据
参数说明:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//数据
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
函数名称:void lcd_disp_char(uchar x,uchar y,uchar dat)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）显示一个字符dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);//写入需要显示的地址 
	lcd_write_data(dat);   //写入需要显示的内容
}

/********************************************************
函数名称:lcd1602_write_character(uchar x,uchar y,uchar *p)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）开始显示字符串*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);  //写入需要显示的地址 
	while (*p != '\0') 	     //写入需要显示的内容，直到字符串全部显示完成
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
函数名称:void lcd1602_write_pic(uchar add,uchar *pic_num)
函数作用:lcd1602写入自定义字符
参数说明:在add地址写入自定义字符代码
********************************************************/
void lcd1602_write_pic(uchar add, uchar *pic_num)
{
	unsigned char i;
	add = add << 3;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command(0x40 | add + i);
		lcd_write_data(*pic_num++);
	}
}

/********************************************************
函数名称:void delay_n40us(uint n)
函数作用:lcd1602延时函数
参数说明:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602头文件

实现功能：lcd1602的控制

补充说明：
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602引脚定义*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602函数声明*******************/
void lcd_init(void);								   //初始化函数
void lcd_write_command(uchar command);				   //写指令函数
void lcd_write_data(uchar dat);						   //写数据函数
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //显示一个字符,  x(0-16),y(1-2)。
void lcd1602_write_character(uchar x, uchar y, uchar *p);//显示一个字符串,x(0-16),y(1-2)。
void lcd1602_write_pic(uchar add, uchar *pic_num);      //写入自定义字符
void delay_n40us(uint n);							   //延时函数

/*****************lcd1602自定义字符“℃”*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602显示的字符数组

/********************************************************
函数名称:void lcd_init(void)
函数作用:lcd1602初始化函数
参数说明:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7 
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x38);//设置 8 位格式，2 行，5x7
	lcd_write_command(0x0c);//整体显示，关光标，不闪烁
	lcd_write_command(0x06);//设定输入方式，增量不移位
	lcd_write_command(0x01);//清除屏幕显示
	delay_n40us(100);//实践证明，我的 lcd1602 上，用 for 循环 200 次就能可靠完成清屏指令。
}

/********************************************************
函数名称:void lcd_write_command(uchar dat)
函数作用:lcd1602写命令
参数说明:dat为指令，参考数据手册
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//指令
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);//实践证明，我的 lcd1602 上，用 for 循环 1 次就能完成普通	写指令。
}

/********************************************************
函数名称:void lcd_write_data(uchar dat)
函数作用:lcd1602写数据
参数说明:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//数据
	lcd_rw = 0;//写入
	lcd_e = 1;//允许
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
函数名称:void lcd_disp_char(uchar x,uchar y,uchar dat)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）显示一个字符dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);//写入需要显示的地址 
	lcd_write_data(dat);   //写入需要显示的内容
}

/********************************************************
函数名称:lcd1602_write_character(uchar x,uchar y,uchar *p)
函数作用:lcd1602显示一个字符
参数说明:在横坐标x（0~15），纵坐标y（1~2）开始显示字符串*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//根据显示位置（x,y）确定显示地址 
	if (y == 1) 			   //在第1行显示
		add = 0x80 + x;
	else 				   //在第2行显示
		add = 0xc0 + x;
	lcd_write_command(add);  //写入需要显示的地址 
	while (*p != '\0') 	     //写入需要显示的内容，直到字符串全部显示完成
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
函数名称:void lcd1602_write_pic(uchar add,uchar *pic_num)
函数作用:lcd1602写入自定义字符
参数说明:在add地址写入自定义字符代码
********************************************************/
void lcd1602_write_pic(uchar add, uchar *pic_num)
{
	unsigned char i;
	add = add << 3;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command(0x40 | add + i);
		lcd_write_data(*pic_num++);
	}
}

/********************************************************
函数名称:void delay_n40us(uint n)
函数作用:lcd1602延时函数
参数说明:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif