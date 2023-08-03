#include<cstdio>
const int maxn=50;
char chs[60]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int n;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		printf("2 %d %d\n",n,n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) printf("%c",chs[j]);
			printf("\n");
		}
		printf("\n");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) printf("%c",chs[i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
