//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0503%20%E5%A5%87%E6%95%B0%E7%A0%81%E9%97%AE%E9%A2%98
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=250005;
int n,x,a[maxn],b[maxn]; long long tot;
void GB(int *a,int *b,int len)
{
	if(len<=1) return;
	int M=len>>1,p1=0,p2=M,p=0;
	GB(a,b,M); GB(a+M,b+M,len-M);
	while(p1<M&&p2<len)
	{
		if(a[p1]<=a[p2]) b[p++]=a[p1++];
		else { b[p++]=a[p2++]; tot+=M-p1; }
	}
	while(p1<M) b[p++]=a[p1++];
	while(p2<len) b[p++]=a[p2++];
	memcpy(a,b,len<<2);
}
int nxd()
{
	tot=0;
	int cnt=0;
	for(int i=0;i<n*n;i++)
	{
		scanf("%d",&x);
		if(!x) continue;
		a[cnt++]=x;
	}
	GB(a,b,cnt);
	return tot;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		long long t1,t2;
		t1=nxd()&1;
		t2=nxd()&1;
		puts(t1==t2?"TAK":"NIE");
	}
	return 0;
}
