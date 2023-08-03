#include<cstdio>
typedef long long LL;
int A,B,Q[40007],cnt,head,tail;
void dfs(int x,LL y,int p10)
{
	if(y>B) return;
	if(!x)
	{
		int last=y/(p10/10);
		if(!last) return;
		dfs(x,y+(LL)last*p10,p10*10);
		if(y>=A&&y<=B) ++cnt;
		if(p10<B) Q[tail++]=y;
		return;
	}
	int last=y/(p10/10),nxt=x%10;
	x/=10;
	if(last-nxt>=0) dfs(x,y+p10*(last-nxt),p10*10);
	if(nxt&&last+nxt<10) dfs(x,y+p10*(last+nxt),p10*10);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&A,&B);
	Q[tail++]=7; if(A<=7&&7<=B) ++cnt;
	do
		for(int i=0;i<10;i++) dfs(Q[head],i,10);
	while(++head<tail);
	printf("%d\n",cnt);
	return 0;
}
