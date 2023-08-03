#include<cstdio>
bool cnt[1005];
int res,a1,a2,a3,a5,a10,a20;
int a[6],w[6]={1,2,3,5,10,20};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=0;i<6;i++) scanf("%d",&a[i]);
	cnt[0]=1;
	for(int i=0;i<6;i++)
		for(int j=0;j<a[i];j++)
			for(int k=1000;k>=w[i];k--)
				cnt[k]|=cnt[k-w[i]];
	for(int i=1;i<=1000;i++) res+=cnt[i];
	printf("Total=%d\n",res);
	return 0;
}
