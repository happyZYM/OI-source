#include<cstdio>
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%10-(x/10)%10-(x/100)%10-x/1000>0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

