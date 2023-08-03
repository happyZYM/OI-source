#include<cstdio>
using namespace std;
int main()
{
	bool isc[1001]={0};
	int x,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		isc[x]=1;
	}
	int ans=0;
	for(int i=0;i<1001;i++) ans+=isc[i];
	printf("%d\n",ans);
	for(int i=0;i<1001;i++) if(isc[i]) printf("%d ",i);
	printf("\n");
	return 0;
}

