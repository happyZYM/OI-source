#include<cstdio>
#include<cstring>
typedef long long LL;
const int maxn=500005;
int n,a[maxn],b[maxn]; LL tot;
void GB(int *a,int *b,int len)
{
	if(len<=1) return;
	int M=len/2,p1=0,p2=M,p=0;
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
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		tot=0;
		GB(a,b,n);
		printf("%lld\n",tot);
	}
	return 0;
}
