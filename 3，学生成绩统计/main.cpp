#include<iostream>
#include<math.h>
#include<string>
#include<time.h>
using namespace std;

struct studentinf//学生结构体
{
	int no;
	int cla;
	char name[10];
	int english;
	int math;
	int computer;
};
struct count//分数段统计使用
{
	int e1;//小于60
	int e2;//大于等于60小于70
	int e3;//大于等于70小于80
	int e4;//大于等于80小于90
	int e5;//大于等于90
};
//题目，目的，结构，流程图
void main()
{	
	srand((unsigned)time(NULL));
	studentinf student[30];
	count e_num,m_num,c_num;//统计初始化
	e_num.e1=0;e_num.e2=0;e_num.e3=0;e_num.e4=0;e_num.e5=0;
	m_num.e1=0;m_num.e2=0;m_num.e3=0;m_num.e4=0;m_num.e5=0;
	c_num.e1=0;c_num.e2=0;c_num.e3=0;c_num.e4=0;c_num.e5=0;
	for(int i=0;i<30;i++)
	{
		student[i].cla=14;
		student[i].no=1401+i;
		strcpy(student[i].name,"张三");
		student[i].english=rand()%90+10;
		student[i].math=rand()%90+10;
		student[i].computer=rand()%90+10;
	}
	
	cout<<"学生成绩表"<<endl;
	cout<<"|班级\t|学号\t|姓名\t|英语\t|数学\t|计算机\t|"<<endl;
	for(i=0;i<30;i++)
		cout<<"|"<<student[i].cla<<"\t|"<<student[i].no<<"\t|"<<student[i].name<<"\t|"<<student[i].english<<"\t|"<<student[i].math<<"\t|"<<student[i].computer<<"\t|"<<endl;
	


	//统计输出
	for(i=0;i<30;i++)
	{
		if(student[i].english<60)//英语统计
			e_num.e1++;
		else if(student[i].english>=60&&student[i].english<70)
			e_num.e2++;
		else if(student[i].english>=70&&student[i].english<80)
			e_num.e3++;
		else if(student[i].english>=80&&student[i].english<90)
			e_num.e4++;
		else if(student[i].english>=90)
			e_num.e5++;

		if(student[i].math<60)//数学统计
			m_num.e1++;
		else if(student[i].math>=60&&student[i].math<70)
			m_num.e2++;
		else if(student[i].math>=70&&student[i].math<80)
			m_num.e3++;
		else if(student[i].math>=80&&student[i].math<90)
			m_num.e4++;
		else if(student[i].math>=90)
			m_num.e5++;

		if(student[i].computer<60)//计算机统计
			c_num.e1++;
		else if(student[i].computer>=60&&student[i].computer<70)
			c_num.e2++;
		else if(student[i].computer>=70&&student[i].computer<80)
			c_num.e3++;
		else if(student[i].computer>=80&&student[i].computer<90)
			c_num.e4++;
		else if(student[i].computer>=90)
			c_num.e5++;
	}
	
	//输出统计结果
	cout<<"统计结果:"<<endl;
	cout<<"|统计\t|90以上\t|80-90\t|70-80\t|60-70\t|60以下\t|"<<endl;
	cout<<"|英语\t|"<<e_num.e5<<"\t|"<<e_num.e4<<"\t|"<<e_num.e3<<"\t|"<<e_num.e2<<"\t|"<<e_num.e1<<"\t|"<<endl;
	cout<<"|数学\t|"<<m_num.e5<<"\t|"<<m_num.e4<<"\t|"<<m_num.e3<<"\t|"<<m_num.e2<<"\t|"<<m_num.e1<<"\t|"<<endl;
	cout<<"|计算机\t|"<<c_num.e5<<"\t|"<<c_num.e4<<"\t|"<<c_num.e3<<"\t|"<<c_num.e2<<"\t|"<<c_num.e1<<"\t|"<<endl;

}
