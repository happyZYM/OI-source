#include<cstdio>
template<typename T> inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
const int maxn=10005;
int n,m;
int fa[maxn],dep[maxn];
inline int ff(int x)
{
	int a=x,b;
	while(x!=fa[x]) x=fa[x];
	while(a!=x)
	{
		b=fa[a];
		fa[a]=x;
		a=b;
	}
	return x;
}
inline void Union(int x,int y)
{
	int fx=ff(x),fy=ff(y); if(fx==fy) return;
	if(dep[fx]<dep[fy]) fa[fx]=fy;
	else
	{
		fa[fy]=fx;
		if(dep[fx]==dep[fy]) dep[fx]++;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	for(int i=1;i<=n;i++) fa[i]=i;
	int opt,x,y;
	while(m-->0)
	{
		read(opt,x,y);
		if(opt==1) Union(x,y);
		else puts(ff(x)==ff(y)?"Y":"N");
	}
	return 0;
}
