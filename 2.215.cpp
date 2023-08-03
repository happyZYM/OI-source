#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,m,num;
int a[maxn];
bool loop,ok[maxn],vis[maxn];
string s[maxn];
struct node
{
	int id,sign;
	node(int id=0,int sign=0):id(id),sign(sign){}
};
vector<node> ex[maxn];
int dfs(int cur)
{
	if(!ok[cur])
	{
		loop=true;
		return 0;
	}
	if(ex[cur].empty()) return a[cur];
	if(vis[cur])
	{
		ok[cur]=false;
		loop=true;
		return 0;
	}
	vis[cur]=true;
	for(int i=0;i<ex[cur].size();++i)
	{
		node& k=ex[cur][i];
		if(ok[k.id]) a[cur]+=k.sign*dfs(k.id);
		if(!ok[k.id])
		{
			ok[cur]=false;
			loop=true;
		}
	}
	ex[cur].clear();
	return a[cur];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>n>>m&&n&&m)
	{
		loop=false;
		memset(a,0,sizeof(a));
		memset(ok,1,sizeof(ok));
		memset(vis,0,sizeof(vis));
		int num=n*m;
		for(int i=0;i<num;++i)
		{
			cin>>s[i];
			string k=s[i];
			vector<int> sign;
			if(k[0]=='-') sign.push_back(-1);
			else sign.push_back(1);
			for(int j=0;j<k.length();++j)
			{
				if(k[j]=='-') sign.push_back(-1),k[j]=' ';
				else if(k[j]=='+') sign.push_back(1),k[j]=' ';
			}
			stringstream ss(k);
			int pos=0;
			ex[i].clear();
			while(ss>>k)
			{
				if(isdigit(k[0]))
				{
					istringstream tmp(k);
					int cur;
					tmp>>cur;
					a[i]+=cur*sign[pos++];
				}
				else ex[i].push_back(node((k[0]-'A')*m+(k[1]-'0'),sign[pos++]));
			}
		}
		for(int i=0;i<num;++i) dfs(i);
		if(loop)
		{
			for(int i=0;i<num;++i)
				if(!ok[i]) printf("%c%d: %s\n",i/m+'A',i%m,s[i].c_str());
		}
		else
		{
			putchar(' ');
			for(int i=0;i<m;++i) printf("%6d",i);
			printf("\n");
			for(int i=0;i<n;++i)
			{
				printf("%c",i+'A');
				for(int j=0;j<m;++j) printf("%6d",a[i*m+j]);
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
