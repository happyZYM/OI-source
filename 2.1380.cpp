#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=200+5;
const int oo=1e9;
struct Edge
{
	int u, v, d;//d=1 u->v, d=2 v->u, d=0 u-v
	Edge(int u=0,int v=0,int d=0):u(u),v(v),d(d) { }
};
vector<Edge> edges[maxn];
int n,root,maxlen,f[maxn],g[maxn],have_father[maxn];
int dfs(int u)
{
	int ans=0,sz=edges[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=edges[u][i].v;
		if(edges[u][i].d==1)
			ans=max(ans,dfs(v)+1);
	}
	return ans;
}
bool read()
{
	bool have_data=false;
	int a,b;
	n=0;
	for(int i=0;i<maxn;i++) edges[i].clear();
	memset(have_father,0,sizeof(have_father));
	while(cin>>a&&a)
	{
		string str;
		have_data=true;
		if(a>n) n=a;//update the maximum node
		while(cin>>str&&str!="0")
		{
			int len=str.length();
			char type=str[len-1];
			if(type=='d'||type=='u') str=str.substr(0,len-1);
			stringstream ss(str);
			ss>>b;// b is a's son
			if(b>n) n=b;
			have_father[b]=true;
			if(type=='d')
			{
				edges[a].push_back(Edge(a,b,1));//forward
				edges[b].push_back(Edge(b,a,2));//backward
			}
			else if(type=='u')
			{
				edges[a].push_back(Edge(a,b,2));
				edges[b].push_back(Edge(b,a,1));
			}
			else edges[a].push_back(Edge(a,b,0));
		}
	}
	if(have_data)//find the root of the graph
		for(int i=1;i<=n;i++)
			if(!have_father[i]&&!edges[i].empty())
			{
				root=i;
				break;
			}
	return have_data;
}
struct State
{
	int w,f,g;
	State(int w=0,int f=0,int g=0):w(w),f(f),g(g) { }
};
bool cmp_f(const State& w1,const State& w2)
{ return w1.f<w2.f; }
bool cmp_g(const State& w1,const State& w2)
{ return w1.g<w2.g; }
bool dp(int i,int fa)
{
	if(edges[i].empty())//leaves
	{
		f[i]=g[i]=0;
		return true;
	}
	vector<State> sons;
	int f0=0,g0=0,sz=edges[i].size();
	//f'[i]=max{f[w]|w->i}+1,g'[i]=max{g[w]|i->w}+1
	for(int k=0;k<sz;k++)
	{
		int w=edges[i][k].v;
		if(w==fa) continue;
		dp(w,i);
		int d=edges[i][k].d;
		if(d==0) sons.push_back(State(w,f[w],g[w]));
		else if(d==1) g0=max(g0,g[w]+1);
		else f0=max(f0,f[w]+1);
	}
	if(sons.empty())//nothing directed
	{
		f[i]=f0;
		g[i]=g0;
		if(f[i]+g[i]>maxlen) f[i]=g[i]=oo;
		return f[i]<oo;
	}
	
	f[i]=g[i]=oo;
	
	int s=sons.size();
	sort(sons.begin(),sons.end(),cmp_f);
	int maxg[maxn];
	maxg[s-1]=sons[s-1].g;
	for(int k=s-2;k>=0;k--)
		maxg[k]=max(sons[k].g,maxg[k+1]);
	for(int p=0;p<=s;p++)
	{
		int ff=f0,gg=g0;
		if(p>0) ff=max(ff,sons[p-1].f+1);
		if(p<sons.size()) gg=max(gg,maxg[p]+1);
		if(ff+gg<=maxlen) f[i]=min(f[i],ff);
	}
	
	sort(sons.begin(),sons.end(),cmp_g);
	int maxf[maxn];
	maxf[s-1]=sons[s-1].f;
	for(int k=s-2;k>=0;k--)
		maxf[k]=max(sons[k].f,maxf[k+1]);
	for(int p=0;p<=s;p++)
	{
		int ff=f0,gg=g0;
		if(p>0) gg=max(gg,sons[p-1].g+1);
		if(p<sons.size()) ff=max(ff,maxf[p]+1);
		if(ff+gg<=maxlen) g[i]=min(g[i],gg);
	}
	
	return f[i]<oo;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(read())
	{		
		maxlen=0;
		for(int i=1;i<=n;i++) maxlen=max(maxlen,dfs(i));
		if(dp(root,-1)) cout<<maxlen+1<<"\n"; 
		else cout<<maxlen+2<<"\n";
	}
	return 0;
}
