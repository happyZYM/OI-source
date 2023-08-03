#include<cstdio>
using namespace std;
int main()
{
	int a[3];
	for(int i=0;i<3;i++) scanf("%d",a+i);
	int ans=a[0];
	for(int i=1;i<3;i++) if(a[i]>ans) ans=a[i];
	printf("%d\n",ans);
	return 0;
}

