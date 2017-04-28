#include<iostream>
#include<string>
#include<ctime>
using namespace std;
enum time_zone{w11=-11,w10=-10,w9=-9,w8=-8,w7=-7,w6=-6,w5=-5,w4=-4,w3=-3,w2,w1,we0=0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,we12};
//-----------------Date----------------------------------------------------------------//

/**********c中tm结构********************
struct tm {//c中关于tm结构体的学习
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

class Date//Date类的定义
{
	public:
		int year,month,day,hour,minute,second;
		Date();//直接获取系统时间
		Date(int,int,int,int,int,int);//构造时设置时间
		void setdate(int,int,int,int,int,int);//设置
		void showdate();//显示不带回车
		void showdate_endl();//显示带回车
};
//-----------------Date2----------------------------------------------------------------//
class Date2:public Date
{
	public:
		time_zone zone;
		Date2(int,int,int,int,int,int);//
		void showdate2();
		void set_zone(time_zone);
	private:
		string zone_str;//时区
};
//-----------------声明----------------------------------------------------------------//
//-----------------Date----------------------------------------------------------------//
Date::Date()//Date类的实现
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	year=ltm->tm_year+1900;
	month=ltm->tm_mon;
	day=ltm->tm_mday;
	hour=ltm->tm_hour;
	minute=ltm->tm_min;
	second=ltm->tm_sec;
}

Date::Date(int ryear,int rmonth,int rday,int rhour,int rminute,int rsecond)
{
	year=ryear;
	month=rmonth;
	day=rday;
	hour=rhour;
	minute=rminute;
	second=rsecond;
}
void Date::setdate(int ryear,int rmonth,int rday,int rhour,int rminute,int rsecond)
{
	year=ryear;
	month=rmonth;
	day=rday;
	hour=rhour;
	minute=rminute;
	second=rsecond;
}
void Date::showdate()
{
	cout<<year<<"-"<<month<<"-"<<day<<" "<<hour<<":"<<minute<<":"<<second;
}
void Date::showdate_endl()
{
	cout<<year<<"-"<<month<<"-"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
//-----------------Date----------------------------------------------------------------//
//-----------------Date2----------------------------------------------------------------//
Date2::Date2(int ryear,int rmonth,int rday,int rhour,int rminute,int rsecond)
											:Date(ryear,rmonth,rday,rhour,rminute,rsecond)
{
	zone_str="东八区";
	zone=e8;
	cout<<"..Date2."<<endl;
}
void Date2::showdate2()
{	
	cout<<zone_str<<": ";
	showdate();
}
void Date2::set_zone(time_zone rz)
{	
	int p=zone;
	int n=rz;
	hour-=p-n;
	if(hour>24)
	{
		day++;
		hour-=24;
	}else if(hour<0)
	{
		day--;
		hour+=24;
	}
	zone=rz;
	switch(zone)
	{
		case w11:zone_str="西十一区";break;
		case w10:zone_str="西十区";break;
		case w9:zone_str="西九区";break;
		case w8:zone_str="西八区";break;
		case w7:zone_str="西七区";break;
		case w6:zone_str="西六区";break;
		case w5:zone_str="西五区";break;
		case w4:zone_str="西四区";break;
		case w3:zone_str="西三区";break;
		case w2:zone_str="西二区";break;
		case w1:zone_str="西一区";break;
		case we0:zone_str="中时区";break;
		case e1:zone_str="东一区";break;
		case e2:zone_str="东二区";break;
		case e3:zone_str="东三区";break;
		case e4:zone_str="东四区";break;
		case e5:zone_str="东五区";break;
		case e6:zone_str="东六区";break;
		case e7:zone_str="东七区";break;
		case e8:zone_str="东八区";break;
		case e9:zone_str="东九区";break;
		case e10:zone_str="东十区";break;
		case e11:zone_str="东十一区";break;
		case we12:zone_str="东西十二区";break;
	}
}



//-----------------Date2----------------------------------------------------------------//

int main()
{	
	Date2 d(2011,5,6,11,11,11);
	d.showdate2();
	time_zone z=w8;
	d.set_zone(z);
	d.showdate2();
	return 0;
}