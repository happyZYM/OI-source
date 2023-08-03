#include<cstdio>
long long f(int* P,int i,int final)
{
	if(i==0) return 0;
	if(P[i]==final) return f(P,i-1,final);
	return f(P,i-1,6-P[i]-final)+(1LL<<(i-1));
}
const int maxn=70;
int n,start[maxn],finish[maxn];
int kase;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",start+i);
		for(int i=1;i<=n;i++) scanf("%d",finish+i);
		int k=n;
		while(k>=1&&start[k]==finish[k]) k--;
		
		long long res=0;
		if(k>=1)
		{
			int other=6-start[k]-finish[k];
			res=f(start,k-1,other)+f(finish,k-1,other)+1;
		}
		printf("Case %d: %lld\n",++kase,res);
	}
	return 0;
}
