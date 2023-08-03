#include<cstdio>
#include<cmath>
char* out[3]={"Killed by the impact.","Stuck in the air.","James Bond survives."};
const double g=9.81;
double a,b,c,cc,x,y,k,l,s,w;
int res;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w)==4&&(k!=0.0||l!=0.0||s!=0.0||w!=0.0))
	{
		a=k/2, b=-w*g, c=50*w-w*g*l, cc=-w*g*l;
		x=0.0;
		if(b*b-4*a*c >= 0.0) x=(-b+sqrt(b*b-4*a*c))/2.0/a;
		y=(-b+sqrt(b*b-4*a*cc))/2.0/a;
		res = 0; // bad
		if (s > l+y) res = 1; // ugly
		else if (s >= l+x || s <= 50/g) res = 2; // good
		printf("%s\n",out[res]);
	}
    return 0;
}
