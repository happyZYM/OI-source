#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int T,k;
bool found[7][128];
char x;
vector<char> can[7];
int last[7];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		memset(found,0,sizeof(found));
		for(int i=1;i<=5;i++) can[i].clear();
		cin>>k;
		for(int i=1;i<=6;i++)
			for(int j=1;j<=5;j++)
				found[j][cin>>x,x]=1;
		for(int i=1;i<=6;i++)
			for(int j=1;j<=5;j++)
				if(found[j][cin>>x,x])
				{
					can[j].push_back(x);
					found[j][x]=0;
				}
		for(int i=1;i<=5;i++) sort(can[i].begin(),can[i].end());
		last[5]=1;
		for(int i=4;i>=0;i--) last[i]=last[i+1]*can[i+1].size();
		if(k>last[0]) cout<<"NO"<<endl;
		else
		{
			for(int i=1;i<=5;i++)
			{
			    int j=ceil((double)k/last[i])-1;
			    cout<<can[i][j];
			    k-=last[i]*j;
			}
			cout<<endl;
		}
	}
	return 0;
}
