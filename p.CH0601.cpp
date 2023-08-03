//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0601%20Genius%20ACM
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=5e5+5;
int T,n,m,w; LL k,a[maxn],b[maxn],c[maxn];
inline void gb(int L,int M,int R)
{
	int i=L,j=M+1;
	for(int k=L;k<=R;k++)
		if(j>R||(i<=M&&b[i]<=b[j])) c[k]=b[i++];
		else c[k]=b[j++];
}
inline LL f(int L,int R)
{
	if(R>n) R=n;
	int gs=min(m,(R-L+1)>>1);
	for(int i=w+1;i<=R;i++) b[i]=a[i];
	sort(b+w+1,b+R+1);
	gb(L,w,R);
	LL res=0;
	for(int i=0;i<gs;i++) res+=(c[R-i]-c[L+i])*(c[R-i]-c[L+i]);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%lld",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int res=0,L=1,R=1;
		w=1;
		b[1]=a[1];
		while(L<=n)
		{
			int p=1;
			while(p)
			{
				LL val=f(L,R+p);
				if(val<=k)
				{
					w=R=min(R+p,n);
					for(int i=L;i<=R;i++) b[i]=c[i];
					if(R==n) break;
					p<<=1;
				}
				else p>>=1;
			}
			res++;
			L=R+1;
		}
		printf("%d\n",res);
	}
	return 0;
}
