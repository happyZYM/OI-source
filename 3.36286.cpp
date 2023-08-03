#include<cstdio>
#include<cstring>
template<typename T> inline void read(T& t)
{
    t=0; int ch,f=false;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
inline int min(const int &a,const int &b) { return a<b?a:b; }
const int maxn=1005;
const int oo=0x3f3f3f3f;
int dis[maxn][maxn],G[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n,m,a,b,c,res=oo;
	memset(G,0x3f,sizeof(G));
	read(n,m);
	while(m-->0)
	{
		read(a,b,c);
		G[a][b]=G[b][a]=c;
	}
	memcpy(dis,G,sizeof(dis));
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<k;++i)
			for(int j=1;j<i;++j)
				if((dis[i][j]^oo)&&(G[j][k]^oo)&&(G[k][i]^oo))
					res=min(res,dis[i][j]+G[j][k]+G[k][i]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<i;++j)
			{
				int tmp=dis[i][k]+dis[k][j];
				if(tmp<dis[i][j]) dis[i][j]=dis[j][i]=tmp;
			}
	}
	printf("%d\n",res);
	return 0;
}
