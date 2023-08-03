#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	bool light[n+1]={0};
	for(int i=1;i<=n;i++) light[i]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j*i<=n;j++)
			light[j*i]=!light[j*i];
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!light[i])
		{
			if(flag) printf(",%d",i);
			else{
				flag=1;
				printf("%d",i);
			}
		}
	}
	return 0;
}

