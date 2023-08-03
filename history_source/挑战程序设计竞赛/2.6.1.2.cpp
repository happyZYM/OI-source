#include<cstdio>
int egcd(int a,int b,int &x,int &y)
{
	static int d;
	d=a;
	if(b!=0)
	{
		d=egcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	else x=1,y=0;
	return d;
}
int a,b;
void solve()
{
	int x,y;
	if(egcd(a,b,x,y)>1) printf("-1\n");
	else printf("%d %d %d %d\n",x>=0?x:0,x<0?-x:0,y>=0?y:0,y<0?-y:0);
}
void init()
{
	scanf("%d%d",&a,&b);
}
int main()
{
	init();
	solve();
	return 0;
}
