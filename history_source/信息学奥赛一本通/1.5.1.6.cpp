#include<cstdio>
using namespace std;
int main()
{
	int l,m;
	scanf("%d%d",&l,&m);
	bool road[l+1];
	for(int i=0;i<=l;i++) road[i]=1;
	int a,b,ans=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		for(int j=a;j<=b;j++) road[j]=0;
	}
	for(int i=0;i<=l;i++) ans+=road[i];
	printf("%d\n",ans);
	return 0;
}

