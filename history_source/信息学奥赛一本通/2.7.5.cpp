#include<cstdio>
double a,b,c,d;
double op(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	double le,ri,mid;
	for(int i=-100;i<=100;i++)
	{
		le=i;
		ri=i+1;
		if(op(le)==0) printf("%.2lf ",le);
		else if(op(le)*op(ri)<0)
		{
			while(ri-le>=0.001)
			{
				mid=(le+ri)/2;
				if(op(le)*op(mid)<0) ri=mid;
				else le=mid;
			}
			printf("%.2lf ",le);
		}
	}
	printf("\n");
	return 0;
}
