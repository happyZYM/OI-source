#include<cstdio>
inline int abs(int a)
{return a<0?-a:a;}
inline int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
int x1,x2,y1,y2;
void solve()
{
	int x=abs(x1-x2),y=abs(y1-y2);
	if(x==0&&y==0) printf("%d\n");
	else printf("%d\n",gcd(x,y)-1);
}
void init()
{
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
}
int main()
{
	init();
	solve();
	return 0;
}
