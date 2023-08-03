#include<cstdio>
int k;
int res[20005];
void solve()
{
	int cnt=0;
	for(int y=k+1;y<=2*k;y++)
	{
		int x=k*y/(y-k);
		if(x*y==k*y+k*x) res[cnt++]=y;
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("1/%d = 1/%d + 1/%d\n",k,k*res[i]/(res[i]-k),res[i]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&k)==1) solve();
	return 0;
}
