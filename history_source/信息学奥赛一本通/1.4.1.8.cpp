#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=n;i<=m;i++) if(i%17==0) ans+=i;
	printf("%d\n",ans);
	return 0;
}

