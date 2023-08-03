#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50005;
struct Data { int L,R,id; };
struct Ti { int lst,id; };
inline bool operator<(const Data &a,const Data &b) { return a.L<b.L; }
inline bool operator<(const Ti &a,const Ti &b) { return a.lst>b.lst; }
int n,res[maxn];
Data cow[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&cow[i].L,&cow[i].R);
		cow[i].id=i+1;
	}
	sort(cow,cow+n);
	priority_queue<Ti> Q;
	Q.push((Ti){cow[0].R,1});
	res[cow[0].id]=1;
	for(int i=1;i<n;i++)
	{
		if(Q.top().lst>=cow[i].L) { int tmp=Q.size(); Q.push((Ti){-1,tmp+1}); }
		Ti ch=Q.top(); Q.pop();
		res[cow[i].id]=ch.id;
		Q.push((Ti){cow[i].R,ch.id});
	}
	printf("%d\n",Q.size());
	for(int i=1;i<=n;i++) printf("%d\n",res[i]);
	return 0;
}
