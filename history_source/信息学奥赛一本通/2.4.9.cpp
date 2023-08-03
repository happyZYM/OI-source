#include<cstdio>
struct Sr
{
	int m,n;
};
long long p(int m,int n,int x)
{
	if(n==1) return 1;
	int ans=0;
	for(int i=x;i*n<=m;i++) ans+=p(m-i,n-1,i);
	return ans;
}
int answer(Sr sr)
{
	printf("%lld\n",p(sr.m,sr.n,0));
}
int main()
{
	int t;
	scanf("%d",&t);
	Sr sr[t];
	for(int i=0;i<t;i++) scanf("%d%d",&sr[i].m,&sr[i].n);
	for(int i=0;i<t;i++) answer(sr[i]);
	return 0;
}

