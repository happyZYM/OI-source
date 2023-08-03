#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn=3e5+5;
struct MODI { int id,L,R,A; } modi[maxn*2],tl[maxn*2],tr[maxn*2];
int N,M,K,P[maxn],res[maxn],q[maxn];
vector<int> bl[maxn],ql,qr;
LL c[maxn];
void add(int p,LL v)
{
	for(;p<=M;p+=(p&-p)) c[p]+=v;
}
LL sum(int p)
{
	LL s=0;
	for(;p;p-=(p&-p)) s+=c[p];
	return s;
}
inline void opt(const MODI &md,int flg)
{
	if(md.L<=md.R) { add(md.L,flg*md.A); add(md.R+1,-flg*md.A); }
	else
	{
		add(md.L,flg*md.A); add(M+1,-flg*md.A);
		add(1,flg*md.A); add(md.R+1,-flg*md.A);
	}
}
void solve(int ML,int MR,int QL,int QR)//ML,QL:id,country
{
	if(QL>QR) return;//no need to do any more
	if(ML==MR)
	{
		for(int i=QL;i<=QR;i++) res[q[i]]=modi[ML].id;
		return;
	}
	int MM=(ML+MR)>>1;
	for(int i=ML;i<=MM;i++) opt(modi[i],1);
	ql.clear(); qr.clear();
	for(int i=QL;i<=QR;i++)
	{
		long double tot=0;
		for(int j=0;j<bl[q[i]].size();j++) tot+=sum(bl[q[i]][j]);
		if(tot>=P[q[i]]) ql.push_back(q[i]);
		else qr.push_back(q[i]);
	}
	for(int i=0;i<ql.size();i++) q[QL+i]=ql[i];
	for(int i=0;i<qr.size();i++) q[QL+ql.size()+i]=qr[i];
	int sz=ql.size();
	solve(MM+1,MR,QL+sz,QR);
	for(int i=ML;i<=MM;i++) opt(modi[i],-1);
	solve(ML,MM,QL,QL+sz-1);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++)
	{
		int x; scanf("%d",&x);
		bl[x].push_back(i);
	}
	for(int i=1;i<=N;i++) scanf("%d",&P[i]);
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
	{
		scanf("%d%d%d",&modi[i].L,&modi[i].R,&modi[i].A);
		modi[i].id=i;
	}
	K++;
	modi[K].L=1; modi[K].R=M; modi[K].A=1e9; modi[K].id=K;
	for(int i=1;i<=N;i++) q[i]=i;
	solve(1,K,1,N);
	for(int i=1;i<=N;i++)
	{
		if(res[i]==K) puts("NIE");
		else printf("%d\n",res[i]);
	}
	return 0;
}
