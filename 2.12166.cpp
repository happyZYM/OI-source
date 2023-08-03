#include <iostream>
#include <string>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
string line;
map<LL,int> base;	   //LL±íÊ¾×ÜÖØÁ¿£¬int±íÊ¾³öÏÖµÄ´ÎÊý
int sum;
void dfs(int depth,int s, int e)
{
	if(line[s]=='[')
	{
		int p=0;
		for(int i=s+1;i!=e;++i)
		{
			if(line[i]=='[')++p;
			if(line[i]==']')--p;
			if(p==0&&line[i]==',')
			{
				dfs(depth+1,s+1,i-1);
				dfs(depth+1,i+1,e-1);
			}
		}
	}
	else
	{
		LL w =0;
		for(int i=s;i<=e;++i) w=w*10+line[i]-'0';
		++sum;++base[w<<depth];
		//³ÓíÈµÄ×ÜÖØÁ¿(w<<depth)³öÏÖµÄ´ÎÊý+1£¬³ÓíÈ×ÜÊý(sum)+1£»
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(false); //È¡ÏûcinºÍstdinÍ¬²½£¬Ê¹µÃcinËÙ¶ÈÏàµ±ÓÚscanf
	int T;
	cin>>T;
	while(T--)
	{
		cin>>line;
		base.clear();   //Çå¿Õmap
		sum =0;		 //×ÜÊýÇåÁã
		dfs(0,0,(int)line.size()-1);
		int maxn=0;
		for(auto it = base.begin();it != base.end(); ++it)
			maxn = max(maxn,it->second);
		cout<<sum-maxn<<endl;
	}
	return 0;
}
