#ifndef _UTILS_H_
#define _UTILS_H_

#include "typedef.h"

/* ��ȡϵͳʱ��(��ȷ������) */
uint64 get_current_time_ms(void);

/* ��ȡϵͳʱ��(��ȷ����) */
uint64 get_current_time_s(void);

/* ��ȡϵͳʱ��(�ַ�����ʽ) */
void get_sys_time(char *ptm);

/* ��ȡ��ǰʱ��,��ʽ���ơ�2009-08-20 15:55:30�� */
void get_sys_time1(char *ptm);

int get_sys_time_year(void);

/* ����ϵͳʱ�� */
int set_sys_time(int year,int mon,int day,int hour,int min,int sec);

/* ��ȡ�ļ���С */
unsigned long get_file_size(const char *fname);

/* ����� */
long int my_random(void);

#endif 
