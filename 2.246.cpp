#include<bits/stdc++.h>
using namespace std;
typedef deque<int> deq;
const char sign[3][10]={"Draw:","Loss:","Win :"};
int step;
vector<deq> s;
inline bool judge_end()
{
	for(int i=1;i<=7;i++)
		if(!s[i].empty())
			return false;
	return true;
}
bool init()
{
	int x;
	deq u,v;
	step=0;
	s.clear();
	for(int i=0;i<52;i++)
	{
		scanf("%d",&x);
		if(x==0) return false;
		u.push_back(x);
	}
	s.push_back(u);
	for(int i=0;i<7;i++)
		s.push_back(v);
	return true;
}
inline bool get_card(deq& now,int n,int *num)
{
	for(int i=0;i<n;i++)
	{
		if(now.empty()) return false;
		num[2-i]=now.back();
		now.pop_back();
	}
	for(int i=0;i<3-n;i++)
	{
		if(now.empty()) return false;
		num[i]=now.front();
		now.pop_front();
	}
	return true;
}
int solve()
{
	set<vector<deq>> g;
	g.insert(s);
	int pos=0,vis[10],fuck;
	memset(vis,0,sizeof(vis));
	while(true)
	{
		if(s[0].empty()) return 1;
		do pos=pos%7+1;while(vis[pos]);
		step++;
		int u=s[0].front();
		s[0].pop_front();
		s[pos].push_back(u);
		bool get=true;
		while(get)
		{
			get=false;
			for(int i=1;i<=3;i++)
			{
				int num[3],sum=0;
				deq now=s[pos];
				if(get_card(now,i,num)==false)
					break;
				for(int j=0;j<3;j++)
					sum+=num[j];
				if(sum%10)
					continue;
				get=true;
				for(int j=0;j<3; j++)
					s[0].push_back(num[j]);
				s[pos]=now;
				break;
			}
		}
		if(s[pos].empty()) vis[pos]=1;
		if(judge_end()) return 2;
		if(g.count(s)) return 0;
		g.insert(s);
	}
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(init())
	{
		int flag=solve();
		printf("%s %d\n",sign[flag],step);
	}
	return 0;
}
