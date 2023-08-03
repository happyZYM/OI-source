#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int M=1e3+10;
const int N=1e2+10;
const int K=1e4+10;
int T,n,m,X,Y,res,sz,count[M][M],f[N];
char s[M][M];
string d[N];
struct ACmachine
{
    int fl,e[26],val;
    bool isw[101];
}ac[K];
void build_Trie(int val)
{
    int h=0,len=d[val].size();
    for(int i=0;i<len;i++)
	{
        if(ac[h].e[d[val][i]-'a']==0) ac[h].e[d[val][i]-'a']=++sz;
        h=ac[h].e[d[val][i]-'a'];
    }
    ac[h].isw[val]=true;
    ac[h].val=val;
}
void getFail()
{
    queue<int>q;
    for(int i=0;i<26;i++)
        if(ac[0].e[i]!=0) q.push(ac[0].e[i]);
    while(!q.empty())
	{
        int u=q.front();q.pop();
        for(int i=0;i<26;i++)
		{
            if(ac[u].e[i]!=0)
			{
                ac[ac[u].e[i]].fl=ac[ac[u].fl].e[i];
                q.push(ac[u].e[i]);
            }
            else ac[u].e[i]=ac[ac[u].fl].e[i];
        }
    }
}
void cmp()
{
    for(int i=1;i<=n;i++)
	{
        int h=0;
        for(int j=1;j<=m;j++)
		{
            h=ac[h].e[s[i][j-1]-'a'];
            while(count[i-1][j]!=0&&!ac[h].isw[count[i-1][j]+1])
				count[i-1][j]=f[count[i-1][j]];
            if(ac[h].isw[count[i-1][j]+1])
			{
                count[i][j]=count[i-1][j]+1;
                if(count[i][j]==X) res++;
            }
        }
    }
}
void kgf()
{
    int k=1,now=2;
    while(now<=n)
	{
        if(d[now]==d[k]||k==0)
		{
            if(d[now]==d[k]) f[now]=k++;
            else f[now]=k++;
            now++;
        }
        else k=f[k];
    }
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
	{
        memset(ac,0,sizeof(ac));
        memset(count,0,sizeof(count));
        memset(f,0,sizeof(f));
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&m);
		res=sz=0;
        for(int j=1;j<=n;j++) scanf("%s",s[j]);
        scanf("%d%d",&X,&Y);
        for(int j=1;j<=X;j++) cin>>d[j];
        for(int j=1;j<=X;j++) build_Trie(j);
        getFail();
        kgf();
        cmp();
        printf("%d\n",res);
    }
    return 0;
}
