#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
const int maxn=25;
map<string,int> s_i;
string i_s[maxn+5],a,b;
int n,m,cnt,i,j,k,kase;
inline int ID(const string &str)
{
	if(!s_i.count(str))
	{
		s_i[str]=cnt;
		i_s[cnt++]=str;
	}
	return s_i[str];
}
bool g[maxn+5][maxn+5],e[maxn+5][maxn+5],vis[maxn+5],flag;
void dfs(int id)
{
	if(vis[id]) return;
	if(flag) cout<<", ";
	flag=true;
	cout<<i_s[id];
	vis[id]=true;
	for(int i=0;i<n;i++)
		if(e[id][i])
			dfs(i);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while((cin>>n>>m)&&n)
	{
		s_i.clear();
		cnt=0;
		memset(g,0,sizeof(g));
		memset(e,0,sizeof(e));
		memset(vis,0,sizeof(vis));
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			g[ID(a)][ID(b)]=true;
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
				if(g[i][j]&&g[j][i]) e[i][j]=e[j][i]=1;
//		for(i=0;i<n;i++)
//			for(j=0;j<n;j++)
//				if(g[i][j]) cout<<i_s[i]<<" -> "<<i_s[j]<<endl;
//		for(i=0;i<n;i++)
//			for(j=0;j<n;j++)
//				if(e[i][j]) cout<<i_s[i]<<" <-> "<<i_s[j]<<endl;
		if(kase) cout<<endl;
		cout<<"Calling circles for data set "<<++kase<<":\n";
		for(i=0;i<n;i++)
			if(!vis[i])
			{
				flag=false;
				dfs(i);
				cout<<endl;
			}
	}
	return 0;
}
