#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int can[10]={1,1,1,1,1,1,1,1,1,1},a,b;
	bool change[10][10]={0},use[10]={0};
	int queue[15];
	int head=0,tail=0;
	string num;
	cin>>num;
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		change[a][b]=1;
	}
	for(int i=0;i<10;i++)
	{
		tail=head=0;
		queue[tail++]=i;
		memset(use,0,sizeof(use));
		use[i]=1;
		while(tail-head>0)
		{
			for(int j=0;j<10;j++)
			{
				if(change[queue[head]][j]&&!use[j])
				{
					queue[tail++]=j;
					use[j]=1;
				}
			}
			head++;
		}
		can[i]=tail;
	}
	int ans=1;
	for(int i=0;i<num.size();i++) ans*=can[num[i]-'0'];
	cout<<ans<<endl;
	return 0;
}
