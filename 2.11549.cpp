#include<cstdio>
int T,n,k,res,k1,k2;
int buf[100];
inline int next(int n,int k)
{
	if(!k) return 0;
	long long k2=(long long)k*k;
	int L=0;
	while(k2>0) { buf[L++]=k2%10; k2/=10; }
	if(n>L) n=L;
	int res=0;
	for(int i=0;i<n;i++)
		res=res*10+buf[--L];
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
		scanf("%d%d",&n,&k);
		res=k1=k2=k;
		do
		{
			k1=next(n,k1);
			k2=next(n,k2); if(k2>res) res=k2;
			k2=next(n,k2); if(k2>res) res=k2;
		}
		while(k1!=k2);
		printf("%d\n",res);
	}
	return 0;
}
