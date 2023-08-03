#include<cstdio>
#include<cmath>
using namespace std;
long double solve(int a,int b,int c,int d)
{
	static long double x,y;
	x=abs(a-c);
	y=abs(b-d);
	return sqrt(x*x+y*y)/10000;
}
int mround(long double inp)
{
	if(inp-floor(inp)>=0.5) return floor(inp)+1;
	else return floor(inp);
}
int startx,starty,endx,endy;
unsigned int h,m;
long double tot=0;
int main()
{
	freopen("snow.in","r",stdin);
	freopen("snow.out","w",stdout);
	scanf("%d%d",&startx,&starty);
	while(scanf("%d%d%d%d",&startx,&starty,&endx,&endy)==4)
		tot+=solve(startx,starty,endx,endy);
	h=floor(tot)-1;
	m=mround(60*(tot-h));
	if(m>=60)
	{
		m-=60;
		h++;
	}
	printf("%d:",h);
	if(m<10) printf("0");
	printf("%d\n",m);
	return 0;
}
/*
人为优化:必然不走“冤枉路”
若本身就是“欧拉回路”，走两边即可；否则用“来回绕一遍”的办法消除多余“奇点” 
*/
