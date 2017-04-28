#ifndef STUDENT_H
#define STUDENT_H
#define NAMEMAX 10

#include<iostream>
#include<cstring>
#include<stdlib.h>

#include"Date.h"
using namespace std;

struct studentinf//结构体声明
{
	int no;
	char name[NAMEMAX];
	int english;
	int math;
	Date date;
	studentinf *next;
};
class Student
{
	public:
		Student(string);//建表
		void insert(int,char[]);//插入
		void insert(int,char[],int,int);//插入
		void del(int);//删除
		void update(int,int,int);//修改姓名
		void select(int);//查找
		void showstu();//显示
	private:
		int sum;//数据总数
		string mclass;//班级或表名
		studentinf *stu_h;
};

#endif