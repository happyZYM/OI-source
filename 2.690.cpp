#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
const int maxn = 20;
const int N = 5;
int tab[N];
int ans;
int ivs[maxn],SZ;
void dfs(int d,int* pre,int len)
{
    if(len+(10-d)*ivs[0]>=ans) return; 
    for(int i=0;i<SZ;i++)
	{
        int iv=ivs[i];
        bool ok=true;
        for(int j=0;j<N;j++)
            if((pre[j]>>iv)&tab[j])
			{
				ok=false;
				break;
			}
        if(ok)
		{
            if(d==9)
			{
                ans=min(ans,len+iv);
                return;
            }
            int now[N];
            for(int j=0;j<N;j++)
                now[j]=(pre[j]>>iv)|tab[j];
            dfs(d+1,now,len+iv);
        }
    }
}
void preJudge(int n)
{
    SZ=0;
    for(int iv=1;iv<=n;iv++)
	{
        bool ok=true;
        for(int i=0;i<N;i++)
            if((tab[i]>>iv)&tab[i])
			{
				ok=false;
				break;
			}
        if(ok) ivs[SZ++]=iv;
    }
}
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    int n;
    char G[maxn+1];
    while(scanf("%d",&n)==1&&n)
	{

        memset(tab,0,sizeof(tab));
        for(int i=0;i<N;i++)
		{
            scanf("%s",G);
            for(int j=0;j<n;j++)
				if(G[j]=='X')
                	tab[i]|=1<<j;
        }
        ans=n*10;
        preJudge(n);
        dfs(1,tab,n);
        printf("%d\n",ans);
    }
    return 0;
}
