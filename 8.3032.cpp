#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
int n,m,T,r[maxn],c[maxn];
long long s[maxn];
long long cal(int *a,int len)
{
	int x=T/len;
	for(int i=1;i<=len;i++) a[i]-=x;
	memset(s,0,sizeof(s));
	for(int i=1;i<=len;i++) s[i]=a[i]+s[i-1];
	sort(s+1,s+1+len); int zws=s[1+len/2];
	long long res=0;
	for(int i=1;i<=len;i++) res+=abs(s[i]-zws);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&T);
	for(int i=0;i<T;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		r[x]++; c[y]++;
	}
	if(T%n)
	{
		if(T%m) puts("impossible");
		else printf("column %lld\n",cal(c,m));
	}
	else
	{
		if(T%m) printf("row %lld\n",cal(r,n));
		else printf("both %lld\n",cal(r,n)+cal(c,m));
	}
	return 0;
}
