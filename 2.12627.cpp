#include<cstdio>
long long m3[40];
long long f(int k,int i)
{
	if(i<=0) return 0;
	if(k<=0) return 1;
	if(i<=(1<<k-1)) return f(k-1,i)*2;
	return m3[k-1]*2+f(k-1,i-(1<<k-1));
}
int K,A,B;
int main()
{
	m3[0]=1;
	for(int i=1;i<40;i++) m3[i]=m3[i-1]*3;
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d%d",&K,&A,&B);
		printf("Case %d: %lld\n",i,f(K,B)-f(K,A-1));
	}
	return 0;
}
