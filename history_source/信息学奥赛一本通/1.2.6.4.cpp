#include<cstdio>
using namespace std;
#define pi 3.1415926535897
int main()
{
	double v,r,h;
	scanf("%lf%lf",&h,&r);
	v=h*pi*r*r;
	int ans=0;
	double k=20;
	while(k>0) k-=v,ans++;
	printf("%d\n",ans);
	return 0;
}
