#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "utils.h"


#define LOGFILE "/oxServer/mlog.log"

/* 获取系统当前时间(精确到毫秒) */
uint64 get_current_time_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64)tv.tv_sec*1000 + (uint64)tv.tv_usec/1000;
}

/* 获取系统当前时间(精确到秒) */
uint64 get_current_time_s(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64)tv.tv_sec;
}

/* 获取系统时间(格式类似Mon Nov 23 19:11:19 2009) */
void _get_time(char *ptm)
{
    time_t now;				/* 实例化time_t结构 */
    struct tm *timenow;		/* 实例化tm结构指针 */

    /* 读取当前国际标准时间 */
    time(&now);
    /* 转换成本地区时间 */
    timenow = localtime(&now);
    /* 将时间转化成字符串 */
    sprintf(ptm, "%s", asctime(timenow));
}

/* 获取当前时间,格式类似“20090820155530” */
void get_sys_time(char *ptm)
{
    time_t now;
    struct tm *tmnow;

    time(&now);
    tmnow = localtime(&now);
    sprintf(ptm, "%04d%02d%02d%02d%02d%02d",
            tmnow->tm_year + 1900, tmnow->tm_mon + 1, tmnow->tm_mday,
            tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
}

/* 获取当前时间,格式类似“2009-08-20 15:55:30” */
void get_sys_time1(char *ptm)
{
    time_t now;
    struct tm *tmnow;

    time(&now);
    tmnow = localtime(&now);
    sprintf(ptm, "%04d-%02d-%02d %02d:%02d:%02d",
            tmnow->tm_year + 1900, tmnow->tm_mon + 1, tmnow->tm_mday,
            tmnow->tm_hour, tmnow->tm_min, tmnow->tm_sec);
}

int get_sys_time_year(void)
{
    time_t now;
    struct tm *tmnow;

    time(&now);
    tmnow = localtime(&now);
    return (tmnow->tm_year + 1900);
 
}

/* 设置系统时间 */
int set_sys_time(int year, int mon, int day, int hour, int min, int sec)
{
    struct tm _tm;
    struct timeval tv;
    time_t timep;
    _tm.tm_sec = sec;
    _tm.tm_min = min;
    _tm.tm_hour = hour;
    _tm.tm_mday = day;
    _tm.tm_mon = mon - 1;
    _tm.tm_year = year - 1900;
    //printf("%d %d %d %d %d %d\r\n", year, mon, day, hour, min, sec);

    timep = mktime(&_tm);
    tv.tv_sec = timep;
    tv.tv_usec = 0;
    if (settimeofday(&tv, (struct timezone*)0) < 0)
    {
        return -1;
    }

    return 0;
}


/* 获取文件大小 */
unsigned long get_file_size(const char *fname)
{
    struct stat buf;

    if (stat(fname, &buf) < 0)
    {
        return -1;
    }

    return (unsigned long)buf.st_size;
}


/* 随机数 */
long int my_random(void)
{
    srandom(time(NULL));
    return random();
}



