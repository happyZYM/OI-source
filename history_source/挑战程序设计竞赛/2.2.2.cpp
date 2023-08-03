#include<bits/stdc++.h>
using namespace std;
const int MAX_N=100000;
int n,s[MAX_N],t[MAX_N];
pair<int,int> itv[MAX_N];
void solve()
{
	for(int i=0;i<n;i++)
	{
		itv[i].first=t[i];
		itv[i].second=s[i];
	}
	sort(itv,itv+n);
	int ans=0,t=0;
	for(int i=0;i<n;i++)
	{
		if(t<itv[i].second)
		{
			ans++;
			t=itv[i].first;
		}
	}
	printf("%d\n",ans);
}
void init()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",s+i);
	for(int i=0;i<n;i++) scanf("%d",t+i);
}
int main()
{
	init();
	solve();
	return 0;
}
