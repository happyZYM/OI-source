#include<cstdio>
#include<initializer_list>
const int maxn=1000;
char str[55][maxn+5],res;
int hsh[128],max;
int n,m;
int cnt;
//ACGT
int main()
{
#define NDEBUG
#ifdef local
	freopen("pro.in","r",stdin);
	#undef NDEBUG
#endif
	int t;
	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++) scanf("%s",&str[i][0]);
		cnt=0;
		for(int i=0;i<n;i++)
		{
			hsh['A']=hsh['C']=hsh['G']=hsh['T']=0;
			for(int j=0;j<m;j++)
				hsh[str[j][i]]++;
			max=0;
			for(char j:{'A','C','G','T'})
				if(hsh[j]>max) res=j,max=hsh[j];
			printf("%c",res);
			for(int j=0;j<m;j++)
				if(str[j][i]!=res) cnt++;
		}
		printf("\n%d\n",cnt);
	}
	return 0;
}
