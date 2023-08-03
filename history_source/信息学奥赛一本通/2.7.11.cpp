#include<cstdio>
#include<algorithm>
using std::sort;
int main()
{
	int n,m;
	scanf("%d",&n);
	int a[n],*p;
	for(int i=0;i<n;i++) scanf("%d",a+i);
	sort(a,a+n);
	scanf("%d",&m);
	int le=0,ri=n-1;
	while(le<ri)
	{
		if(a[le]+a[ri]==m)
		{
			printf("%d %d\n",a[le],a[ri]);
			return 0;
		}
		if(a[le]+a[ri]<m) le++;
		else ri--;
	}
	printf("No\n");
	return 0;
}
