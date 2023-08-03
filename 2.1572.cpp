#include<cstdio>
#include<cstring> 
const int N=52;
int g[N][N];
int c[N];
inline int id(char a1, char a2)
{
	return ((a1-'A')<<1)+(a2=='+'?0:1);
}
inline void connect(char a1,char a2,char b1,char b2)
{
	if(a1=='0'||b1=='0') return;
	int u=id(a1,a2)^1,v=id(b1,b2);
	g[u][v] = 1;
}
bool toposort(int u)
{
	c[u]=-1;
	for(int v=0;v<N;v++)
	if(g[u][v])
	{
		if(c[v]<0) return true;
		else if(!c[v]&&toposort(v)) return true;
	}
	c[u]=1;
	return false;
}
inline bool cycle()
{
	memset(c,0,sizeof(c));
	for (int i=0;i<N;i++)
		if(!c[i]&&toposort(i)) return true;
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		memset(g,0,sizeof(g));
		while(n--)
		{
			char s[10];
			scanf("%s",s);
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					if(i!=j)
						connect(s[i<<1],s[(i<<1)+1],s[j<<1],s[(j<<1)+1]);
		}
		printf("%s\n",cycle()?"unbounded":"bounded");
	}
	return 0;
}
