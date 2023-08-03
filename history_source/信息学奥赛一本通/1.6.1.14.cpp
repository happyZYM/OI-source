#include<cstdio>
using namespace std;
bool isp[5010];
int maxn(int n)
{
	for(int i=n;i>=2;i--)
		if(n%i==0&&isp[i]) return i;
}
int main()
{
	for(int i=0;i<5010;i++) isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2;i<5010;i++)
		for(int j=2;j*i<5010;j++)
			isp[j*i]=0;
	bool flag=0;
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=m;i<=n;i++)
	{
		if(flag) printf(",");
		flag=1;
		printf("%d",maxn(i));
	}
	printf("\n");
	return 0;
}

