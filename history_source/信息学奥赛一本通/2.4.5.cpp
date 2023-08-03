#include<cstdio>
#define maxn 1000010
#define mod 32767
int answers[maxn];
int main()
{
	for(int i=0;i<3;i++) answers[i]=i;
	for(int i=3;i<maxn;i++) answers[i]=((2*answers[i-1])%mod+answers[i-2])%mod;
	int n;
	scanf("%d",&n);
	int sr[n];
	for(int i=0;i<n;i++) scanf("%d",sr+i);
	for(int i=0;i<n;i++) printf("%d\n",answers[sr[i]]);
	return 0;
}
