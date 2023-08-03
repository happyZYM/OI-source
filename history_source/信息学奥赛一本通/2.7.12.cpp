#include<cstdio>
#include<algorithm>
using std::sort;
int n,a[100001];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	sort(a,a+n);
	printf("%d ",a[0]);
	for(int i=1;i<n;i++) if(a[i]!=a[i-1]) printf("%d ",a[i]);
	printf("\n");
	return 0;
}
