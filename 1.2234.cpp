#include<cstdio>
#include<cstdlib>
const int maxn=32800;
inline int min(const int &a,const int &b) { return a<b?a:b; }
int n,res,x,a,b,rt,val[maxn],rd[maxn],ch[maxn][2],sz[maxn],cnt;
inline int NewNode(int v) { val[++cnt]=v; sz[cnt]=1; rd[cnt]=rand(); return cnt; }
inline void PushUp(int o) { sz[o]=sz[ch[o][0]]+1+sz[ch[o][1]]; }
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	if(rd[x]<rd[y]) { ch[x][1]=merge(ch[x][1],y); PushUp(x); return x; }
	else { ch[y][0]=merge(x,ch[y][0]); PushUp(y); return y; }
}
void split(int o,int v,int &x,int &y)
{
	if(!o) { x=y=0; return; }
	if(val[o]<=v) { x=o; split(ch[o][1],v,ch[o][1],y); }
	else { y=o; split(ch[o][0],v,x,ch[o][0]); }
	PushUp(o);
}
inline int kth(int o,int k)
{
	while(true)
	{
		if(k<=sz[ch[o][0]]) o=ch[o][0];
		else if(k==sz[ch[o][0]]+1) return o;
		else { k-=sz[ch[o][0]]+1; o=ch[o][1]; }
	}
}
inline int Rank(int &o,int v)
{
	int a,b;
	split(o,v-1,a,b);
	int r=sz[a]+1;
	rt=merge(a,b);
	return r;
}
inline void insert(int &o,int v)
{
	int a,b;
	split(o,v,a,b);
	rt=merge(merge(a,NewNode(v)),b);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&x);
	insert(rt,-10000000);
	insert(rt,10000000);
	insert(rt,x);
	res=x;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		int p=Rank(rt,x);
		res+=min(abs(val[kth(rt,p-1)]-x),abs(val[kth(rt,p)]-x));
		insert(rt,x);
	}
	printf("%d\n",res);
	return 0;
}
