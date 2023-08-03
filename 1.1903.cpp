#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T& t)
{
	t=0; int ch,f=false;
	while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
	if(ch=='-') f=true,ch=getchar();
	t=ch^48;
	while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
	if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
const int maxn=2e6+7;
int n,m;
int a[maxn],bid[maxn];
struct Query
{
	int l,r,pre,id;
}Q[maxn];
int Qcnt=0;
struct Change
{
	int pos,val;
}C[maxn];
int Ccnt=0;
int cnt[maxn],ans=0,blo,res[maxn];
inline bool cmp(const Query &a,const Query &b)
{ return bid[a.l]!=bid[b.l]?a.l<b.l:((bid[a.l]&1)?a.r<b.r:a.r>b.r); }
inline void Work(int ti,int i)
{
	if(Q[i].l<=C[ti].pos&&C[ti].pos<=Q[i].r)
	{
		ans-=(--cnt[a[C[ti].pos]]==0);
		ans+=(++cnt[C[ti].val]==1);
	}
	swap(C[ti].val,a[C[ti].pos]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	blo=sqrt(n);
	for(int i=1;i<=n;i++) read(a[i]),bid[i]=(i-1)/blo+1;
	while(m--)
	{
		char opt[5];
		scanf("%s",opt);
		if(opt[0]=='Q')
		{
			Qcnt++; read(Q[Qcnt].l,Q[Qcnt].r);
			Q[Qcnt].pre=Ccnt;
			Q[Qcnt].id=Qcnt;
		}
		else if(opt[0]=='R') Ccnt++,read(C[Ccnt].pos,C[Ccnt].val);
	}
	sort(Q+1,Q+Qcnt+1,cmp);
	int l=1,r=0,ti=0;
	for(int i=1;i<=Qcnt;i++)
	{
		while(l<Q[i].l) ans-=(--cnt[a[l++]]==0);
		while(l>Q[i].l) ans+=(++cnt[a[--l]]==1);
		while(r<Q[i].r) ans+=(++cnt[a[++r]]==1);
		while(r>Q[i].r) ans-=(--cnt[a[r--]]==0);
		while(ti<Q[i].pre) Work(++ti,i);
		while(ti>Q[i].pre) Work(ti--,i);
		res[Q[i].id]=ans;
	}
	for(int i=1;i<=Qcnt;i++) printf("%d\n",res[i]);
	return 0;
}
