#include<cstdio>
#include<cstring>
int n,r,kase;
bool buy[25];
double p[25],s[25];;
void dfs(int depth,int bought,double res)
{
	if(bought>r||depth-bought>n-r) return;
	if(depth>=n)
	{
		s[n]+=res;
		for(int i=0;i<n;i++)
			if(buy[i]) s[i]+=res;
		return;
	}
	buy[depth]=0;
	dfs(depth+1,bought,res*(1-p[depth]));
	buy[depth]=1;
	dfs(depth+1,bought+1,res*p[depth]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&r)==2&&n)
	{
		for(int i=0;i<n;i++) scanf("%lf",p+i);
		memset(s,0,sizeof(s));
		dfs(0,0,1.0);
		printf("Case %d:\n",++kase);
		for(int i=0;i<n;i++)
			printf("%.6lf\n",s[i]/s[n]);
	}
	return 0;
}
