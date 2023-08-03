#include<cstdio>
#include<cstring>
bool isp[20005];
int p[20000],cnt;
int main()
{
	memset(isp,true,sizeof(isp));
	for(int i=2;i<=20000;i++)
	{
		if(isp[i]) p[cnt++]=i;
		for(int j=0;j<cnt&&i*p[j]<=20000;j++)
		{
			isp[i*p[j]]=false;
			if(i%p[j]==0) break;
		}
	}
	isp[0]=isp[1]=false;
	int n;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
		for(int j=i;i+j<n;j++)
			if(isp[i]&&isp[j]&&isp[n-i-j])
				return printf("%d %d %d\n",i,j,n-i-j),0;
	return 0;
}
