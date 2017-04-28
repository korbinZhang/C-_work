#include<iostream>
#include<string>
#include <stdlib.h>
#include"Student.h"
using namespace std;
int menu();
int main()
{
	Student stu("5214");
	int m=menu();
	int no,english,math;
	char name[10];
	while(1)
	{
		switch(m)
		{
		case 1://插入学生
			cout<<"写入格式 例:14112 test"<<endl;
			cin>>no>>name;
			stu.insert(no,name);
			break;
		case 2://插入学生和成绩
			cout<<"写入格式 例:14112 test 数学成绩 英语成绩"<<endl;
			cin>>no>>name>>math>>english;
			stu.insert(no,name,math,english);
			break;
		case 3://更新成绩
			cout<<"输入格式:学号 数学成绩 英语成绩"<<endl;
			cin>>no>>math>>english;
			stu.update(no,math,english);
			break;
		case 4://显示数据
			stu.showstu();
			system("pause");
			break;
		case 5:
			cout<<"输入学号:"<<endl;
			cin>>no;
			stu.select(no);
			break;
		case 6:
			cout<<"输入学号:"<<endl;
			cin>>no;
			stu.del(no);
			break;
		case 7://退出
			return 0;
			break;
		default:
			cout<<"请重新选择"<<endl;
			m=menu();
			break;
		}
		m=menu();
	}
	
	return 0;
}
int menu()
{	
	int m;
	cout<<"1,插入学生"<<endl;
	cout<<"2,插入学生和成绩"<<endl;
	cout<<"3,更新成绩"<<endl;
	cout<<"4,显示数据"<<endl;
	cout<<"5,查找学生"<<endl;
	cout<<"6,删除学生"<<endl;
	cout<<"7,退出"<<endl;
	cin>>m;
	return m;
}