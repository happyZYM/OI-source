#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;
const double eps=1e-5;
struct OBJ { int x,y,w; };
int n,dx,dy; OBJ a[maxn];
double x,y,step=20000,tx,ty;
void move()
{
	double mx=0,my=0,len;
	for(int i=1;i<=n;i++)
	{
		len=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y));
		if(fabs(len)<eps) continue;
		mx+=a[i].w*(a[i].x-x)/len;
		my+=a[i].w*(a[i].y-y)/len;
	}
	len=sqrt(mx*mx+my*my);
	x+=step*mx/len;
	y+=step*my/len;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
	while(step>=eps)
	{
		tx=x,ty=y;
		move();
		if(fabs(tx-x)<eps&&fabs(ty-y)<eps) break;
		if(dx!=(x>tx)||dy!=(y>ty))
		{
			dx=x>tx;
			dy=y>ty;
			step=step*0.5;
		}
//		printf(">>> %.3lf %.3lf\n",x,y);
	}
	printf("%.3lf %.3lf\n",x,y);
	return 0;
}
