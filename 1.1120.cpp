#include<cstdio>
#include<cstring>
const int N=70;
int n,cnt,tot,maxn,minn,tm[N]; 
bool ok;
void dfs(int need,int sum,int goal,int maxlen)
{
	if(need==0)
	{
		printf("%d\n",goal);
		ok=true;
	}
	if(sum==goal)//拼完了一根 
	{
		dfs(need-1,0,goal,maxn);
		return;
	}
	for(int i=maxlen;i>=minn;i--)//用单调性确保不重复 
		if(tm[i]&&i+sum<=goal)
		{
			tm[i]--;
			dfs(need,sum+i,goal,i);
			if(ok) return;
			tm[i]++;
			if(sum==0||sum+i==goal) break;
		}
	return;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		minn=N ;
		int x;
		cnt=tot=maxn=0;
		memset(tm,0,sizeof(tm));
		while(n--)
		{
			scanf("%d",&x);
			if(x<=50)
			{
				cnt++;
				tm[x]++;//用桶更方便 
				tot+=x;
				maxn=maxn>x?maxn:x;
				minn=minn<x?minn:x;
			}
		}
		x=tot/2;
		ok=false;
		for(int i=maxn;i<=x;i++)
			if(tot%i==0)
			{
				dfs(tot/i,0,i,maxn);
				if(ok) break;
			}
		if(!ok) printf("%d\n",tot);
	}
	return 0;
}
