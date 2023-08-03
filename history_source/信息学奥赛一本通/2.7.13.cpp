#include<cstdio>
#include<cmath>
double pi=acos(-1),lon,lonn,lonx,le=0,ri,mi,deg,h,ans;
#define d_r(a) (pi/180.0*(a))
#define r_d(a) (180.0/pi*(a))
int main()
{
	scanf("%lf%lf%lf",&lon,&deg,&h);
	lonn=(1+deg*h)*lon;
	ri=d_r(180);
	if(lon*deg*h==0) {printf("0.000\n");return 0;}
	while(ri-le>0.00000000001)
	{
		mi=(le+ri)/2;
		lonx=2*((lon/2)/sin(mi/2))*pi*mi/d_r(360);
		if(lonx>=lonn) ri=mi;
		else le=mi;
	}
	ans=(lon/2)/sin(mi/2)-(lon/2)/tan(mi/2);
	printf("%.3lf\n",ans);
	return 0;
}
