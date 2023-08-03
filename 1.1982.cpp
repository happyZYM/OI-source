#include<cstdio>
#include<algorithm>
using namespace std;
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
typedef __int128 LL;
const int maxn=1000005;
LL n,Mod,a[maxn],Max[maxn],tz[maxn],fs[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,Mod,a[1]);
	LL maxx=a[1]; tz[1]=Max[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		read(a[i]);
		Max[i]=max(Max[i-1]+a[i],a[i]);
		maxx=max(maxx,Max[i]);
		tz[i]=maxx; 
	}
	LL res=fs[1]=tz[1];
	maxx=fs[1]*2;
	for(int i=2;i<=n;i++)
	{
		res=max(res,fs[i]=maxx);
		maxx=max(maxx,fs[i]+tz[i]);
	}
	printf("%d\n",int((res<0?-res:res)%Mod*(res>0?1:-1)));
	return 0;
}
