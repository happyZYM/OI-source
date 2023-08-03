#include<cstdio>
using namespace std;
int main()
{
	int ans=1,a,n;
	scanf("%d%d",&a,&n);
	for(int i=0;i<n;i++) ans*=a;
	printf("%d\n",ans);
	return 0;
}

