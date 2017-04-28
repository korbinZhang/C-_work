#include"Student.h"

Student::Student(string rclass)
{	
	sum=0;
	mclass=rclass;
	stu_h=NULL;

}
void Student::showstu()
{	
	studentinf* p=stu_h;
	cout<<mclass<<endl;
	cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;//-------+
	cout<<"|学号\t"<<"|姓名\t"<<"|英语\t"<<"|数学\t"<<"|日期\t\t\t|"<<endl;
	cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;
	while(p!=NULL)
	{
		cout<<"|"<<p->no<<"\t|"<<p->name<<"\t|";
		if(p->english<0||p->english>100)
			cout<<"空\t|";
		else
			cout<<p->english<<"\t|";
		if(p->math<0||p->math>100)
			cout<<"空\t|";
		else
			cout<<p->math<<"\t|";
		p->date.showdate();
		cout<<"\t|"<<endl;
		p=p->next;
	}
	cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;
}
void Student::insert(int rno,char rname[])
{
	studentinf *p,*s;
	Date da;
	s=(studentinf*)malloc(sizeof(studentinf));
	s->no=rno;
	strcpy(s->name,rname);
	s->date=da;
	s->english=-1;
	s->math=-1;
	s->next=NULL;
	if(stu_h!=NULL)
	{
		p=stu_h;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=s;
	}else
		stu_h=s;
	sum++;
}
void Student::update(int rno,int rmath,int renglish)
{
	studentinf *p;
	if(stu_h==NULL)
	{
		cout<<"未录入数据"<<endl;
		return;
	}
	p=stu_h;
	while(p->no!=rno&&p->next!=NULL)
	{
		p=p->next;
	}
	if(p->no==rno)
	{
		p->math=rmath;
		p->english=renglish;
	}else
		cout<<"学号"<<rno<<"的学生信息未录入"<<endl;
}
void Student::insert(int rno,char rname[],int rmath,int renglish)
{
	insert(rno,rname);
	update(rno,rmath,renglish);
}
void Student::del(int rno)
{
	studentinf *p,*de;//de是p的前一个节点
	if(stu_h==NULL)
	{
		cout<<"未录入数据"<<endl;
		return;
	}
	de=stu_h;
	p=stu_h;
	while(p->no!=rno&&p->next!=NULL)
	{	
		de=p;
		p=p->next;
	}
	if(p->no==rno)
	{	
		de->next=p->next;
	}else
		cout<<"学号"<<rno<<"的学生信息未录入"<<endl;
	if(stu_h->next==NULL&&stu_h->no==rno)
	{
		stu_h=NULL;
	}
}
void Student::select(int rno)
{
	studentinf *p;
	if(stu_h==NULL)
	{
		cout<<"未录入数据"<<endl;
		return;
	}
	p=stu_h;
	while(p->no!=rno&&p->next!=NULL)
	{
		p=p->next;
	}
	if(p->no==rno)
	{
		cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;
		cout<<"|学号\t"<<"|姓名\t"<<"|英语\t"<<"|数学\t"<<"|日期\t\t\t|"<<endl;
		cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;
		cout<<"|"<<p->no<<"\t|"<<p->name<<"\t|";
		if(p->english<0||p->english>100)
			cout<<"空\t|";
		else
			cout<<p->english<<"\t|";
		if(p->math<0||p->math>100)
			cout<<"空\t|";
		else
			cout<<p->math<<"\t|";
		p->date.showdate();
		cout<<"\t|"<<endl;
		cout<<"+-------+-------+-------+-------+-----------------------+"<<endl;
	}else
		cout<<"学号"<<rno<<"的学生信息未录入"<<endl;
}