#ifndef _UTILS_H_
#define _UTILS_H_

#include "typedef.h"

/* 获取系统时间(精确到毫秒) */
uint64 get_current_time_ms(void);

/* 获取系统时间(精确到秒) */
uint64 get_current_time_s(void);

/* 获取系统时间(字符串格式) */
void get_sys_time(char *ptm);

/* 获取当前时间,格式类似“2009-08-20 15:55:30” */
void get_sys_time1(char *ptm);

int get_sys_time_year(void);

/* 设置系统时间 */
int set_sys_time(int year,int mon,int day,int hour,int min,int sec);

/* 获取文件大小 */
unsigned long get_file_size(const char *fname);

/* 随机数 */
long int my_random(void);

#endif 
