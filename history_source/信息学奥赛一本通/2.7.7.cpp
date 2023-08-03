#include<cstdio>
#define abs(a) ((a)<0?(-(a)):(a))
int main()
{
	int n,m,ri,le,mi;
	scanf("%d",&n);
	long long a[n],x,ans;
	for(int i=0;i<n;i++) scanf("%lld",a+i);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%lld",&x);
		ri=n;
		le=0;
		while(le<ri)
		{
			mi=(le+ri)/2;
			if(a[mi]==x) 
			{
				le=mi;
				break;
			}
			if(a[mi]>x) ri=mi;
			if(a[mi]<x) le=mi+1;
		}
		if(le>=n) ans=a[n-1];
		else if(le==0) ans=a[0];
		else ans=(abs(a[le-1]-x)<=abs(a[le]-x))?a[le-1]:a[le];
		printf("%d\n",ans);
	}
	return 0;
}
