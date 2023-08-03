#include<cstdio>
using namespace std;
int main()
{
	bool isp[10010];
	for(int i=0;i<10010;i++) isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2;i<10010;i++)
		if(isp[i])
			for(int j=2;j*i<10010;j++)
				isp[j*i]=0;
	int s;
	scanf("%d",&s);
	for(int a=s/2;a>0;a--)
	{
		if(isp[a]&&isp[s-a])
		{
			printf("%d\n",a*(s-a));
			return 0;
		}
	}
	return 0;
}
