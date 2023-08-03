#include<iostream>
#include<algorithm>
//#include"conio.h"
using namespace std;
long long hashtable[3628800];
inline void set_hash(long long n)
{
	static long long p;
	p=(n*1000009)%3628800;
	while(hashtable[p]>0&&hashtable[p]!=n) p++;
	hashtable[p]=n;
}
inline bool get_hash(long long n)
{
	static long long p;
	p=(n*1000009)%3628800;
	while(hashtable[p]>0)
	{
		if(hashtable[p]==n) return 1;
		p++;
	}
	return 0;
}
struct node
{
	long long state;
	int step;
};
long long s,e;
node que[362885];
int head,tail;
char arr[10];
int d[]={-3,-1,1,3};
int main()
{
	cin>>s;
	e=123804765;
//	cout<<"s= "<<s<<" e= "<<e<<endl;
	set_hash(s);
	que[tail++].state=s;
	node t;
	int i,pos,j;
	long long tt;
	while(head<tail)
	{
		t=que[head];
		if(t.state==e)
		{
			cout<<que[head].step<<endl;
			return 0;
		}
		for(i=8;i>=0;i--)
		{
			arr[i]=t.state%10;
			t.state/=10;
			if(arr[i]==0) pos=i;
		}
		for(i=0;i<4;i++)
		{
			switch(d[i])
			{
				case -3:
					if(pos/3>0) goto addr1;
					else goto addr2;
				case -1:
					if(pos%3>0) goto addr1;
					else goto addr2;
				case 1:
					if(pos%3<2) goto addr1;
					else goto addr2;
				case 3:
					if(pos/3<2) goto addr1;
					else goto addr2;
			}
addr1:
			swap(arr[pos+d[i]],arr[pos]);
			tt=0;
			for(j=0;j<9;j++)
				tt=tt*10+arr[j];
			if(!get_hash(tt))
			{
				set_hash(tt);
//					cout<<"insert "<<tt<<endl;
//					getch();
				que[tail].state=tt;
				que[tail].step=t.step+1;
				tail++;
			}
			swap(arr[pos+d[i]],arr[pos]);
addr2:
			continue;
		}
		head++;
	}
	cout<<"impossible"<<endl;
	return 0;
}
/*
283104765
123804765
*/
