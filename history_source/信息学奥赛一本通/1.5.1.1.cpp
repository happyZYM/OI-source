#include<cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",a+i);
	int m;
	scanf("%d",&m);
	int ans=0;
	for(int i=0;i<n;i++) ans+=(a[i]==m);
	printf("%d\n",ans);
	return 0;
}

