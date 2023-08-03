#include<cstdio>
#include<cstring>
#include<cassert>
int r,c,kase,cnt;
char mp[15][15];
int ID[15][15];
int main()
{
#define NDEBUG
#ifdef local
	freopen("pro.in","r",stdin);
	#undef NDEBUG
#endif
	while(scanf("%d",&r)==1&&r)
	{
		scanf("%d",&c);
		for(int i=1;i<=r;i++) scanf("%s",&mp[i][1]);
		for(int i=0;i<=r;i++) mp[i][0]=mp[i][c+1]='*';
		for(int i=0;i<=c;i++) mp[0][i]=mp[r+1][i]='*'; 
		if(kase) printf("\n");
		printf("puzzle #%d:\n",++kase);
		printf("Across\n");
		cnt=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if((mp[i][j-1]=='*'||mp[i-1][j]=='*')&&mp[i][j]!='*')
					ID[i][j]=++cnt;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(mp[i][j-1]=='*'&&mp[i][j]!='*')
				{
					printf("%3d.",ID[i][j]);
					for(int k=j;mp[i][k]!='*';k++)
						printf("%c",mp[i][k]);
					printf("\n");
				}
		printf("Down\n");
		cnt=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(mp[i-1][j]=='*'&&mp[i][j]!='*')
				{
					printf("%3d.",ID[i][j]);
					for(int k=i;mp[k][j]!='*';k++)
						printf("%c",mp[k][j]);
					printf("\n");
				}
	}
	return 0;
}
