#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int menu();
int study(int *ans);
int main()
{	
	int i;
	int rmenu;//菜单选项
	char ch;//加减法
	int s[20],ans[10];//s:随机20个数；ans:答案
	ofstream fp;
	while(1)
	{
		srand((unsigned)time(NULL));//种子
		for(i=0;i<20;i++)
		{
			s[i]=rand()%90+10;
			//cout<<s[i]<<endl;
		}
		rmenu=menu();
		if(rmenu!=1&&rmenu!=2)
			exit(1);
		ch=rmenu==2?'-':'+';
		fp.open("data.txt",ios::out);
		if(fp==NULL)
		{
			cout<<"error"<<endl;
			exit(1);
		}
		for(i=0;i<10;i++)
		{
			fp<<s[i]<<ch<<s[i+10]<<"="<<endl;
			ans[i]=rmenu==2?s[i]-s[i+10]:s[i]+s[i+10];
		}
		fp.close();
		cout<<"得分:"<<study(ans)<<endl;
		//cout<<"得分:"<<study(ans)<<"用时:"<<(start-clock())/1000<<"秒"<<endl;
	}
}

int menu()
{	int in;
	cout<<"1,加法"<<endl;
	cout<<"2,减法"<<endl;
	cout<<"3,退出"<<endl;
	cin>>in;
	return in;
}
int study(int *ans)
{	
	int i;
	int user_ans;
	int result=0;
	char s;
	ifstream fp1("data.txt",ios::in);
	for(i=0;i<10;i++)
	{	
		s=fp1.get();
		while(s!='\n')
		{
			cout<<s;
			s=fp1.get();
		}
		cin>>user_ans;
		if(user_ans==ans[i])
			result+=10;
	}
	
	fp1.close;
	return result;
}
