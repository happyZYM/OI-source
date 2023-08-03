#include<cstdio>
int n;
const int full=(1<<10)-1;
void solve()
{
	int b;
	bool flag=1;
	for(int a=0;a<100000;a++)
	{
		b=a/n;
		if(n*b!=a) continue;
		int t=0;
		t|=1<<(a/1%10);
		t|=1<<(a/10%10);
		t|=1<<(a/100%10);
		t|=1<<(a/1000%10);
		t|=1<<(a/10000%10);
		
		t|=1<<(b/1%10);
		t|=1<<(b/10%10);
		t|=1<<(b/100%10);
		t|=1<<(b/1000%10);
		t|=1<<(b/10000%10);
		if(t==full) printf("%05d / %05d = %d\n",a,b,n),flag=0;
	}
	if(flag) printf("There are no solutions for %d.\n",n);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	bool flag=0;
	while(scanf("%d",&n)==1&&n)
	{
		if(flag) printf("\n");
		flag=1;
		solve();
	}
	return 0;
}
