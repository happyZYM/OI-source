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
const int maxn=24,P=1e9+7;
int n,m,b[2],f[1<<maxn], dis[1<<maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    read(n);
    for(int i=0;i<n;i++) read(dis[1<<i]);
    read(m); if(m>0) read(b[0]); if(m>1) read(b[1]);
    f[0]=1;
    for(int i=1;i<(1<<n);i++)
	{
        int j=i&-i,k=i;
        dis[i]=dis[i^j]+dis[j];
        if(dis[i]==b[0]||dis[i]==b[1]) continue;
        while(k)
		{
            j=k&-k;
            f[i]+=f[i^j];
            if(f[i]>=P) f[i]-=P;
            k^=j;
        }
    }
    printf("%d\n",f[(1<<n)-1]);
    return 0;
}
