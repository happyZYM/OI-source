#include<cstdio>
int n,L,cnt;
char res[100000];
bool dfs(int pos)
{
	if(++cnt==n)
	{
		for(int i=0;i<pos;i++)
		{
			if(i&&!(i&63)) putchar('\n');
			else if(i&&!(i&3)) putchar(' ');
			putchar(res[i]);
		}
		printf("\n%d\n",pos);
		return 1;
	}
	int j,k;
	for(char i='A';i<'A'+L;i++)
	{
		res[pos]=i;
		bool ok=1;
		for(j=1;j*2<=pos+1;j++)
		{
			bool equal=1;
			for(k=0;k<j;k++)
				if(res[pos-k]!=res[pos-k-j]){equal=0;break;}
			if(equal){ok=0;break;}
		}
		if(ok) if(dfs(pos+1)) return 1;
	}
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&L)==2&&n&&L)
	{
		cnt=-1;
		dfs(0);
	}
	return 0;
}
