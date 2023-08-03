#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
	int pos,st,step,pre;
	node(){}
	node(int _p,int _st,int _step)
	{
		pos=_p;
		st=_st;
		step=_step;
	}
};
bool had_answer,G[20][20],vis[20][1<<17];
int n,m,s,t,res,head,tail,kase;
node st;
node que[20<<17];
void init()
{
	memset(&st,0,sizeof(st));
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	head=tail=1;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	int x,y;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&x);
		st.st|=1<<x;
	}
	st.pos=s;
	st.st|=1<<s;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		G[x][y]=G[y][x]=1;
	}
}
int stk[10000],top;
inline int lowbit(int n)
{
	return n&(-n);
}
inline int count(int n)
{
	int res=0;
	while(n)
	{
		res++;
		n>>=1;
	}
	return res;
}
void print(int n)
{
	top=0;
	while(n!=0)
	{
		stk[top++]=que[n].st;
		n=que[n].pre;
	}
	while(top>1)
	{
		int x=stk[top-1]^stk[top-2],a=count(lowbit(x))-1,b=count(lowbit(x&~lowbit(x)))-1;
		if(stk[top-1]&1<<a) printf("%d %d\n",a,b);
		else printf("%d %d\n",b,a);
		top--;
	}
}
void solve()
{
	if(s==t)
	{
		printf("Case %d: 0\n\n",++kase);
		return;
	}
	que[tail++]=st;
	vis[st.pos][st.st]=1;
	while(tail-head>0)
	{
		int st=que[head].st;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&G[i][j]&&((st&1<<i)>>i)&&!((st&1<<j)>>j))
				{
					que[tail].pos=(i==que[head].pos?j:que[head].pos);
					que[tail].pre=head;
					que[tail].step=que[head].step+1;
					que[tail].st=(st&(~(1<<i)))|1<<j;
					if(vis[que[tail].pos][que[tail].st]) continue;
					vis[que[tail].pos][que[tail].st]=1;
					if(que[tail].pos==t)
					{
						printf("Case %d: %d\n",++kase,que[tail].step);
						print(tail);
						printf("\n");
						return;
					}
					tail++;
				}
		head++;
	}
	printf("Case %d: -1\n\n",++kase);
}
int main()
{
//	printf("%d %d %d\n",count(0),count(1),count(2));return 0;
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int t,kase=0;
	scanf("%d",&t);
	while(t-->0)
	{
		init();
		solve();
	}
	return 0;
}
