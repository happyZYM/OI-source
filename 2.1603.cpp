#include<cstdio>
#include<cstring>
int n,m,maxd,cnt,sum;
int FullSize[625],Size[625];
bool sti[65],in[625][65];
inline int getc(int r,int c)// |
{
	return r*(2*n+1)+c+n+1;
}
inline int getr(int r,int c)//--
{
	return r*(2*n+1)+c+1;
}
inline int FindNext()
{
	for(int i=1;i<=cnt;i++)
		if(Size[i]==FullSize[i])
			return i;
	return 0;
}
void dfs(int d)
{
	if(d>=maxd) return;
	int next=FindNext();
	if(next==0)
	{
//		for(int i=0;i<d;i++) printf("\t");
//		printf("update to %d\n",d);
		maxd=d;
		return;
	}
//	for(int i=0;i<d;i++) printf("\t");
//	printf("find square %d\n",next);
	for(int i=1;i<=sum;i++)
		if(in[next][i])
		{
//			for(int i=0;i<d;i++) printf("\t");
//			printf(">>>>delete stick %d\n",i);
			for(int j=1;j<=cnt;j++)
				if(in[j][i]) Size[j]--;
			dfs(d+1);
			for(int j=1;j<=cnt;j++)
				if(in[j][i]) Size[j]++;
//			for(int i=0;i<d;i++) printf("\t");
//			printf(">>>>back stick %d\n",i);
		}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
//	freopen("pro.out","w",stdout);
#endif
	int kase;
	scanf("%d",&kase);
	while(kase-->0)
	{
		memset(in,0,sizeof(in));
		memset(sti,1,sizeof(sti));
		cnt=0;
		scanf("%d%d",&n,&m);
		int a,b,e,f;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			sti[a]=0;
		}
		for(int len=1;len<=n;len++)
			for(int r=0;r+len<=n;r++)
				for(int c=0;c+len<=n;c++)
				{
					cnt++;
					FullSize[cnt]=len*4;
					Size[cnt]=0;
//					printf("%d (%d,%d,%d)\n",cnt,r,c,len);
					for(int i=0;i<len;i++)
					{
						a=getr(r,c+i);
						b=getr(r+len,c+i);
						e=getc(r+i,c);
						f=getc(r+i,c+len);
						in[cnt][a]=true;
						in[cnt][b]=true;
						in[cnt][e]=true;
						in[cnt][f]=true;
						Size[cnt]+=sti[a]+sti[b]+sti[e]+sti[f];
//						printf("\t[%d,%d,%d,%d]\n",a,b,e,f);
					}
//					printf("\tsize=%d\n",Size[cnt]);
				}
		maxd=n*n;
		sum=2*n*(n+1);
		dfs(0);
		printf("%d\n",maxd);
	}
	return 0;
}
