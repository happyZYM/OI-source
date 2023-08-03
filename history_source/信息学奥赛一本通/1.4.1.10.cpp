#include<cstdio>
using namespace std;
int main()
{
	int ans=0,n,k,x;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x==k) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

