#include<cstdio>
#include<algorithm>
using namespace std;
#define Lc (o<<1)
#define Rc (o<<1|1)
const int maxn=50005;
int n,m,op,a,b,mx[maxn<<2],mxl[maxn<<2],mxr[maxn<<2],tag[maxn<<2],pl,pr,upd;
inline void PushDown(int o,int L,int R)
{
	if(!tag[o]) return;
	tag[Lc]=tag[Rc]=tag[o];
	int M=(L+R)>>1;
	mx[Lc]=mxl[Lc]=mxr[Lc]=(tag[o]>0?M-L+1:0);
	mx[Rc]=mxl[Rc]=mxr[Rc]=(tag[o]>0?R-M:0);
	tag[o]=0;
}
inline void PushUp(int o,int L,int R)
{
	mxl[o]=mxl[Lc];
	mxr[o]=mxr[Rc];
	int M=(L+R)>>1;
	if(mxl[o]==M-L+1) mxl[o]+=mxl[Rc];
	if(mxr[o]==R-M) mxr[o]+=mxr[Lc];
	mx[o]=max(mxr[Lc]+mxl[Rc],max(mx[Lc],mx[Rc]));
}
void update(int o,int L,int R)
{
	if(pl<=L&&R<=pr) { tag[o]=upd; mx[o]=mxl[o]=mxr[o]=(upd>0?R-L+1:0); return; }
	PushDown(o,L,R);
	int M=(L+R)>>1;
	if(pl<=M) update(Lc,L,M);
	if(pr>M) update(Rc,M+1,R);
	PushUp(o,L,R);
}
int find(int o,int L,int R,int len)
{
	if(mxl[o]>=len) return L;
	int M=(L+R)>>1;
	if(mx[Lc]>=len) return find(Lc,L,M,len);
	if(mxr[Lc]+mxl[Rc]>=len) return M-mxr[Lc]+1;
	return find(Rc,M+1,R,len);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	mx[1]=mxl[1]=mxr[1]=n; tag[1]=1;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&op,&a);
		if(op==1)
		{
			if(mx[1]<a) { puts("0"); continue; }
			int p=find(1,1,n,a);
			printf("%d\n",p);
			pl=p; pr=p+a-1; upd=-1;
			update(1,1,n);
		}
		else
		{
			scanf("%d",&b);
			pl=a; pr=a+b-1; upd=1;
			update(1,1,n);
		}
	}
	return 0;
}
