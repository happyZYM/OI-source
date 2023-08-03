#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10;
int n;
double h[maxn],b[maxn],a[maxn],he[maxn][maxn],height[maxn],res=9005;
int p[maxn];
double get_height(double h1,double a1,double b1,double h2,double a2,double b2)
{
	if(b1>=a2) return h2;
	if((a1-b1)/h1>=(a2-b2)/h2)
	{
		if(a1>=a2) return max(0.0,h2-(a2-b1)/(a1-b1)*h1);
		else return max(0.0,(a1-b2)/(a2-b2)*h2-h1);
	}
	if(b1>=b2) return (b1-b2)/(a2-b2)*h2;
	return 0;
}
double cal()
{
	for(int i=0;i<n;i++) height[i]=0;
	double res=0;
	for(int i=1;i<n;i++)
	{
		double &now=height[p[i]];
		for(int j=0;j<i;j++) now=max(now,height[p[j]]+he[p[i]][p[j]]);
	}
	for(int i=0;i<n;i++) res=max(res,height[i]+h[i]);
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lf%lf%lf",&h[i],&b[i],&a[i]);
	for(int i=0;i<n;i++) p[i]=i;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) he[i][j]=get_height(h[i],a[i],b[i],h[j],a[j],b[j]);
	do
		res=min(res,cal());
	while(next_permutation(p,p+n));
	printf("%.0lf\n",res);
	return 0;
}
