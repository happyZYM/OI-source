#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=205;
struct TwoSAT
{
	int n,stk[maxn*2],mark[maxn*2],c;
	vector<int> G[maxn*2];
	void init(int nn)
	{
		n=nn;
		for(int i=0;i<n*2;i++) G[i].clear();
		memset(mark,0,sizeof(mark));
	}
	void Add(int x,int xval,int y,int yval)
	{
//		printf("a[%d] equals to %d  or  a[%d] equals to %d\n",x,xval,y,yval);
		x=x*2+xval; y=y*2+yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	bool dfs(int u)
	{
		if(mark[u^1]) return false;
		if(mark[u]) return true;
		mark[u]=1;
		stk[c++]=u;
		for(int v:G[u]) if(!dfs(v)) return false;
		return true;
	}
	bool solve()
	{
		for(int i=0;i<n*2;i+=2) if(!mark[i]&&!mark[i+1])
		{
			c=0;
			if(!dfs(i))
			{
				while(c>0) mark[stk[--c]]=0;
				if(!dfs(i+1)) return false;
			}
		}
		return true;
	}
}alg;
int T,n,m,hsh[128];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	hsh['m']=0; hsh['h']=1;
	while(T-->0)
	{
		scanf("%d%d",&n,&m);
		alg.init(n);
		while(m-->0)
		{
			char a[10],b[10]; scanf("%s%s",a,b);
			int x,y; sscanf(a+1,"%d",&x); sscanf(b+1,"%d",&y);
			x--; y--;
			alg.Add(x,hsh[a[0]],y,hsh[b[0]]);
		}
		puts(alg.solve()?"GOOD":"BAD");
	}
	return 0;
}
