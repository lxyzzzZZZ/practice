/*************************************************************
					  lcd1602ͷ�ļ�

ʵ�ֹ��ܣ�lcd1602�Ŀ���

����˵����
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602���Ŷ���*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602��������*******************/
void lcd_init(void);								   //��ʼ������
void lcd_write_command(uchar command);				   //дָ���
void lcd_write_data(uchar dat);						   //д���ݺ���
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //��ʾһ���ַ�,  x(0-16),y(1-2)��
void lcd1602_write_character(uchar x, uchar y, uchar *p);//��ʾһ���ַ���,x(0-16),y(1-2)��
void lcd1602_write_pic(uchar add, uchar *pic_num);      //д���Զ����ַ�
void delay_n40us(uint n);							   //��ʱ����

/*****************lcd1602�Զ����ַ����桱*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602��ʾ���ַ�����

/********************************************************
��������:void lcd_init(void)
��������:lcd1602��ʼ������
����˵��:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7 
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x0c);//������ʾ���ع�꣬����˸
	lcd_write_command(0x06);//�趨���뷽ʽ����������λ
	lcd_write_command(0x01);//�����Ļ��ʾ
	delay_n40us(100);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ��������ָ�
}

/********************************************************
��������:void lcd_write_command(uchar dat)
��������:lcd1602д����
����˵��:datΪָ��ο������ֲ�
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//ָ��
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ	дָ�
}

/********************************************************
��������:void lcd_write_data(uchar dat)
��������:lcd1602д����
����˵��:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//����
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
��������:void lcd_disp_char(uchar x,uchar y,uchar dat)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʾһ���ַ�dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);//д����Ҫ��ʾ�ĵ�ַ 
	lcd_write_data(dat);   //д����Ҫ��ʾ������
}

/********************************************************
��������:lcd1602_write_character(uchar x,uchar y,uchar *p)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʼ��ʾ�ַ���*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);  //д����Ҫ��ʾ�ĵ�ַ 
	while (*p != '\0') 	     //д����Ҫ��ʾ�����ݣ�ֱ���ַ���ȫ����ʾ���
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
��������:void lcd1602_write_pic(uchar add,uchar *pic_num)
��������:lcd1602д���Զ����ַ�
����˵��:��add��ַд���Զ����ַ�����
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
��������:void delay_n40us(uint n)
��������:lcd1602��ʱ����
����˵��:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602ͷ�ļ�

ʵ�ֹ��ܣ�lcd1602�Ŀ���

����˵����
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602���Ŷ���*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602��������*******************/
void lcd_init(void);								   //��ʼ������
void lcd_write_command(uchar command);				   //дָ���
void lcd_write_data(uchar dat);						   //д���ݺ���
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //��ʾһ���ַ�,  x(0-16),y(1-2)��
void lcd1602_write_character(uchar x, uchar y, uchar *p);//��ʾһ���ַ���,x(0-16),y(1-2)��
void lcd1602_write_pic(uchar add, uchar *pic_num);      //д���Զ����ַ�
void delay_n40us(uint n);							   //��ʱ����

/*****************lcd1602�Զ����ַ����桱*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602��ʾ���ַ�����

/********************************************************
��������:void lcd_init(void)
��������:lcd1602��ʼ������
����˵��:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7 
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x0c);//������ʾ���ع�꣬����˸
	lcd_write_command(0x06);//�趨���뷽ʽ����������λ
	lcd_write_command(0x01);//�����Ļ��ʾ
	delay_n40us(100);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ��������ָ�
}

/********************************************************
��������:void lcd_write_command(uchar dat)
��������:lcd1602д����
����˵��:datΪָ��ο������ֲ�
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//ָ��
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ	дָ�
}

/********************************************************
��������:void lcd_write_data(uchar dat)
��������:lcd1602д����
����˵��:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//����
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
��������:void lcd_disp_char(uchar x,uchar y,uchar dat)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʾһ���ַ�dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);//д����Ҫ��ʾ�ĵ�ַ 
	lcd_write_data(dat);   //д����Ҫ��ʾ������
}

/********************************************************
��������:lcd1602_write_character(uchar x,uchar y,uchar *p)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʼ��ʾ�ַ���*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);  //д����Ҫ��ʾ�ĵ�ַ 
	while (*p != '\0') 	     //д����Ҫ��ʾ�����ݣ�ֱ���ַ���ȫ����ʾ���
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
��������:void lcd1602_write_pic(uchar add,uchar *pic_num)
��������:lcd1602д���Զ����ַ�
����˵��:��add��ַд���Զ����ַ�����
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
��������:void delay_n40us(uint n)
��������:lcd1602��ʱ����
����˵��:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602ͷ�ļ�

ʵ�ֹ��ܣ�lcd1602�Ŀ���

����˵����
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602���Ŷ���*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602��������*******************/
void lcd_init(void);								   //��ʼ������
void lcd_write_command(uchar command);				   //дָ���
void lcd_write_data(uchar dat);						   //д���ݺ���
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //��ʾһ���ַ�,  x(0-16),y(1-2)��
void lcd1602_write_character(uchar x, uchar y, uchar *p);//��ʾһ���ַ���,x(0-16),y(1-2)��
void lcd1602_write_pic(uchar add, uchar *pic_num);      //д���Զ����ַ�
void delay_n40us(uint n);							   //��ʱ����

/*****************lcd1602�Զ����ַ����桱*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602��ʾ���ַ�����

/********************************************************
��������:void lcd_init(void)
��������:lcd1602��ʼ������
����˵��:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7 
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x0c);//������ʾ���ع�꣬����˸
	lcd_write_command(0x06);//�趨���뷽ʽ����������λ
	lcd_write_command(0x01);//�����Ļ��ʾ
	delay_n40us(100);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ��������ָ�
}

/********************************************************
��������:void lcd_write_command(uchar dat)
��������:lcd1602д����
����˵��:datΪָ��ο������ֲ�
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//ָ��
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ	дָ�
}

/********************************************************
��������:void lcd_write_data(uchar dat)
��������:lcd1602д����
����˵��:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//����
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
��������:void lcd_disp_char(uchar x,uchar y,uchar dat)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʾһ���ַ�dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);//д����Ҫ��ʾ�ĵ�ַ 
	lcd_write_data(dat);   //д����Ҫ��ʾ������
}

/********************************************************
��������:lcd1602_write_character(uchar x,uchar y,uchar *p)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʼ��ʾ�ַ���*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);  //д����Ҫ��ʾ�ĵ�ַ 
	while (*p != '\0') 	     //д����Ҫ��ʾ�����ݣ�ֱ���ַ���ȫ����ʾ���
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
��������:void lcd1602_write_pic(uchar add,uchar *pic_num)
��������:lcd1602д���Զ����ַ�
����˵��:��add��ַд���Զ����ַ�����
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
��������:void delay_n40us(uint n)
��������:lcd1602��ʱ����
����˵��:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602ͷ�ļ�

ʵ�ֹ��ܣ�lcd1602�Ŀ���

����˵����
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602���Ŷ���*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602��������*******************/
void lcd_init(void);								   //��ʼ������
void lcd_write_command(uchar command);				   //дָ���
void lcd_write_data(uchar dat);						   //д���ݺ���
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //��ʾһ���ַ�,  x(0-16),y(1-2)��
void lcd1602_write_character(uchar x, uchar y, uchar *p);//��ʾһ���ַ���,x(0-16),y(1-2)��
void lcd1602_write_pic(uchar add, uchar *pic_num);      //д���Զ����ַ�
void delay_n40us(uint n);							   //��ʱ����

/*****************lcd1602�Զ����ַ����桱*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602��ʾ���ַ�����

/********************************************************
��������:void lcd_init(void)
��������:lcd1602��ʼ������
����˵��:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7 
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x0c);//������ʾ���ع�꣬����˸
	lcd_write_command(0x06);//�趨���뷽ʽ����������λ
	lcd_write_command(0x01);//�����Ļ��ʾ
	delay_n40us(100);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ��������ָ�
}

/********************************************************
��������:void lcd_write_command(uchar dat)
��������:lcd1602д����
����˵��:datΪָ��ο������ֲ�
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//ָ��
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ	дָ�
}

/********************************************************
��������:void lcd_write_data(uchar dat)
��������:lcd1602д����
����˵��:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//����
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
��������:void lcd_disp_char(uchar x,uchar y,uchar dat)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʾһ���ַ�dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);//д����Ҫ��ʾ�ĵ�ַ 
	lcd_write_data(dat);   //д����Ҫ��ʾ������
}

/********************************************************
��������:lcd1602_write_character(uchar x,uchar y,uchar *p)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʼ��ʾ�ַ���*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);  //д����Ҫ��ʾ�ĵ�ַ 
	while (*p != '\0') 	     //д����Ҫ��ʾ�����ݣ�ֱ���ַ���ȫ����ʾ���
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
��������:void lcd1602_write_pic(uchar add,uchar *pic_num)
��������:lcd1602д���Զ����ַ�
����˵��:��add��ַд���Զ����ַ�����
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
��������:void delay_n40us(uint n)
��������:lcd1602��ʱ����
����˵��:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif/*************************************************************
                      lcd1602ͷ�ļ�

ʵ�ֹ��ܣ�lcd1602�Ŀ���

����˵����
***************************************************************/
#ifndef _lcd1602_h_
#define _lcd1602_h_
#include<reg52.h>

#define uchar unsigned char
#define uint unsigned int

/*****************lcd1602���Ŷ���*******************/
#define lcd_db p0
sbit lcd_rs = p1 ^ 1;
sbit lcd_rw = p1 ^ 2;
sbit lcd_e = p1 ^ 4;

/*****************lcd1602��������*******************/
void lcd_init(void);								   //��ʼ������
void lcd_write_command(uchar command);				   //дָ���
void lcd_write_data(uchar dat);						   //д���ݺ���
void lcd_disp_char(uchar  x, uchar  y, uchar  dat);	   //��ʾһ���ַ�,  x(0-16),y(1-2)��
void lcd1602_write_character(uchar x, uchar y, uchar *p);//��ʾһ���ַ���,x(0-16),y(1-2)��
void lcd1602_write_pic(uchar add, uchar *pic_num);      //д���Զ����ַ�
void delay_n40us(uint n);							   //��ʱ����

/*****************lcd1602�Զ����ַ����桱*******************/
uchar code pic[8] = { 0x00,0x0e,0x0a,0x0e,0x00,0x00,0x00,0x00 };

uchar code ascii[] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' }; //lcd1602��ʾ���ַ�����

/********************************************************
��������:void lcd_init(void)
��������:lcd1602��ʼ������
����˵��:
********************************************************/
void lcd_init(void)
{
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7 
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x38);//���� 8 λ��ʽ��2 �У�5x7
	lcd_write_command(0x0c);//������ʾ���ع�꣬����˸
	lcd_write_command(0x06);//�趨���뷽ʽ����������λ
	lcd_write_command(0x01);//�����Ļ��ʾ
	delay_n40us(100);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 200 �ξ��ܿɿ��������ָ�
}

/********************************************************
��������:void lcd_write_command(uchar dat)
��������:lcd1602д����
����˵��:datΪָ��ο������ֲ�
********************************************************/
void lcd_write_command(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 0;//ָ��
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);//ʵ��֤�����ҵ� lcd1602 �ϣ��� for ѭ�� 1 �ξ��������ͨ	дָ�
}

/********************************************************
��������:void lcd_write_data(uchar dat)
��������:lcd1602д����
����˵��:
********************************************************/
void lcd_write_data(uchar dat)
{
	lcd_db = dat;
	lcd_rs = 1;//����
	lcd_rw = 0;//д��
	lcd_e = 1;//����
	lcd_e = 0;
	delay_n40us(1);
}
/********************************************************
��������:void lcd_disp_char(uchar x,uchar y,uchar dat)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʾһ���ַ�dat
********************************************************/
void lcd_disp_char(uchar x, uchar y, uchar dat)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);//д����Ҫ��ʾ�ĵ�ַ 
	lcd_write_data(dat);   //д����Ҫ��ʾ������
}

/********************************************************
��������:lcd1602_write_character(uchar x,uchar y,uchar *p)
��������:lcd1602��ʾһ���ַ�
����˵��:�ں�����x��0~15����������y��1~2����ʼ��ʾ�ַ���*p
********************************************************/
void lcd1602_write_character(uchar x, uchar y, uchar *p)
{
	uchar add;
	//������ʾλ�ã�x,y��ȷ����ʾ��ַ 
	if (y == 1) 			   //�ڵ�1����ʾ
		add = 0x80 + x;
	else 				   //�ڵ�2����ʾ
		add = 0xc0 + x;
	lcd_write_command(add);  //д����Ҫ��ʾ�ĵ�ַ 
	while (*p != '\0') 	     //д����Ҫ��ʾ�����ݣ�ֱ���ַ���ȫ����ʾ���
	{
		lcd_write_data(*p++);
	}
}
/********************************************************
��������:void lcd1602_write_pic(uchar add,uchar *pic_num)
��������:lcd1602д���Զ����ַ�
����˵��:��add��ַд���Զ����ַ�����
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
��������:void delay_n40us(uint n)
��������:lcd1602��ʱ����
����˵��:
********************************************************/
void delay_n40us(uint n)
{
	uint i;
	uchar j;
	for (i = n; i > 0; i--)
		for (j = 0; j < 2; j++);
}
#endif