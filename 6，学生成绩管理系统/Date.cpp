#include"Date.h"

Date::Date()
{
	time_t now = time(0);
	//char* dt = ctime(&now);//转换为字符串型
	//cout << "本地日期和时间：" << dt << endl;

	//tm *gmtm = gmtime(&now);
	//dt = asctime(gmtm);
	//cout << "UTC 日期和时间："<< dt << endl;
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