#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<ctime>
/**********c中tm结构********************
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
}***********************************/
using namespace std;

class Date
{
	public:
		int year,month,day,hour,minute,second;
		Date();
		Date(int,int,int,int,int,int);//构造
		void setdate(int,int,int,int,int,int);//设置
		void showdate();//显示不带回车
		void showdate_endl();//显示带回车
};

#endif