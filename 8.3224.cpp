#include<cstdio>
#include<cstdlib>
#include<ctime>
const int maxn=100005;
int n,rt,x,y,z,op,a,ch[maxn][2],val[maxn],rd[maxn],sz[maxn],cnt;
inline void PushUp(int x) { sz[x]=sz[ch[x][0]]+1+sz[ch[x][1]]; }
inline int NewNode(int v) { val[++cnt]=v; sz[cnt]=1; rd[cnt]=rand(); return cnt; }
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	if(rd[x]<rd[y]) { ch[x][1]=merge(ch[x][1],y); PushUp(x); return x; }
	else { ch[y][0]=merge(x,ch[y][0]); PushUp(y); return y; }
}
void split(int o,int v,int &x,int &y)
{
	if(!o) x=y=0;
	else
	{
		if(val[o]<=v) { x=o; split(ch[o][1],v,ch[o][1],y); }
		else { y=o; split(ch[o][0],v,x,ch[o][0]); }
		PushUp(o);
	}
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
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	srand(1022);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&op,&a);
		if(op==1)
		{
			split(rt,a,x,y);
			rt=merge(merge(x,NewNode(a)),y);
		}
		else if(op==2)
		{
			split(rt,a,x,z);
			split(x,a-1,x,y);
			y=merge(ch[y][0],ch[y][1]);
			rt=merge(merge(x,y),z);
		}
		else if(op==3)
		{
			split(rt,a-1,x,y);
			printf("%d\n",sz[x]+1);
			rt=merge(x,y);
		}
		else if(op==4) printf("%d\n",val[kth(rt,a)]);
		else if(op==5)
		{
			split(rt,a-1,x,y);
			printf("%d\n",val[kth(x,sz[x])]);
			rt=merge(x,y);
		}
		else if(op==6)
		{
			split(rt,a,x,y);
			printf("%d\n",val[kth(y,1)]);
			rt=merge(x,y);
		}
	}
	return 0;
}
