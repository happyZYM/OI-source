#include<cstdio>
#include<cstring>
int main()
{
	int x,y,ans=0;
	bool isp[100010];
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0;
	for(int i=2;i*i<100010;i++)
		if(isp[i])
			for(int j=2;j*i<100010;j++)
				isp[j*i]=0;
	scanf("%d%d",&x,&y);
	if(x<=y) for(int i=x;i<=y;i++) ans+=isp[i];
	else for(int i=y;i<=x;i++) ans+=isp[i];
	printf("%d\n",ans);
	return 0;
}
