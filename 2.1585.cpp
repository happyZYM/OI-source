#include<cstdio>
void solve()
{
	int sum=0,cnt=0;
	char t;
	while(t=getchar(),t!='\n'&&t!='\r')
		if(t=='O')
		{
			cnt++;
			sum+=cnt;
		}
		else cnt=0;
	printf("%d\n",sum);
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n-->0) solve(); 
	return 0;
}
