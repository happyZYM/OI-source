#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=2005;
int M,N,K,L,D;
struct Data { int id,cnt; };
inline bool cmp1(const Data &a,const Data &b) { return a.cnt>b.cnt; }
inline bool cmp2(const Data &a,const Data &b) { return a.id<b.id; }
Data R[maxn],C[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
	for(int i=1;i<=M;i++) R[i].id=i;
	for(int i=1;i<=N;i++) C[i].id=i;
	for(int i=0;i<D;i++)
	{
		int x,y,p,q; scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x==p) C[min(y,q)].cnt++;
		if(y==q) R[min(x,p)].cnt++;
	}
	sort(R+1,R+1+M,cmp1);
	sort(R+1,R+1+K,cmp2);
	sort(C+1,C+1+N,cmp1);
	sort(C+1,C+1+L,cmp2);
	for(int i=1;i<=K;i++) printf("%d ",R[i].id); puts("");
	for(int i=1;i<=L;i++) printf("%d ",C[i].id); puts("");
	return 0;
}
