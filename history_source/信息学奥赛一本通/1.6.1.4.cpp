#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='A'&&a[i]<='Z') a[i]+=32; 
	int front=-1,sum=0,pos=-1;
	bool flag=1;
	string b;
	char w;
	w=getchar();
	while(++pos,w=getchar(),w!='\n')
	{
		if(w!=' ') b+=(w>='A'&&w<='Z'?w+32:w);
		else
		{
			if(a==b)
			{
				if(flag) front=pos-a.size();
				flag=0;
				sum++;
			}
			b="";
		}
	}
	if(a==b)
	{
		if(flag) front=pos;
		flag=0;
		sum++;
	}
	if(front>-1) printf("%d %d\n",sum,front);
	else printf("-1\n");
	return 0;
}
