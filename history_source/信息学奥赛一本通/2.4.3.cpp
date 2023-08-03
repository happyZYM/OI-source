#include<cstdio>
long long ans;
void anss(int n,int x)
{
	ans++;
	for(int i=x;i*i<=n;i++) if(n%i==0) anss(n/i,i);
}
int main()
{
	int n;
	scanf("%d",&n);
	long long answer[n];
	int x;
	for(int i=0;i<n;i++)
	{
		ans=0;
		scanf("%d",&x);
		anss(x,2);
		answer[i]=ans;
	}
	for(int i=0;i<n;i++) printf("%lld\n",answer[i]);
	return 0;
}
