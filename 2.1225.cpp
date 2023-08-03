#include<cstdio>
#include<cstring>
int hsh[10];
void solve()
{
	int n,t,i;
	scanf("%d",&n);
	memset(hsh,0,sizeof(hsh));
	for(i=1;i<=n;i++)
	{
		t=i;
		while(t>0)
		{
			hsh[t%10]++;
			t/=10;
		}
	}
	printf("%d",hsh[0]);
	for(i=1;i<10;i++) printf(" %d",hsh[i]);
	printf("\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t-->0) solve();
	return 0;
}
/*
Sample Input
2
3
13
Sample Output
0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 1
*/
