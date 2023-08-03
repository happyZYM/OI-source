#include<cstdio>
using namespace std;
int main()
{
	int m,n,ans=0;
	scanf("%d%d",&m,&n);
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(x>m) ans++;
		else m-=x;
	}
	printf("%d\n",ans);
	return 0;
}

