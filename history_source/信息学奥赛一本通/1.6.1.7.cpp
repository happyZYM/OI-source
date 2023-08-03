#include<cstdio>
using namespace std;
int main()
{
	bool isp[10010];
	for(int i=0;i<10010;i++) isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2;i<10010;i++)
		for(int j=2;j*i<10010;j++)
			isp[j*i]=0;
	int n;
	bool flag=1;
	scanf("%d",&n);
	for(int i=2;i+2<=n;i++)
	{
		if(isp[i]&&isp[i+2])
		{
			flag=0;
			printf("%d %d\n",i,i+2);
		}
	}
	if(flag) printf("empty\n");
	return 0;
}

