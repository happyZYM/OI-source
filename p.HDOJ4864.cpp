//http://acm.hdu.edu.cn/showprobym.php?pid=4864
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100005;
struct Data { int x,y; };
inline bool cmp(const Data &a,const Data &b) { return a.x>b.x||(a.x==b.x&&a.y>b.y); }
int n,m;
Data mac[maxn],wrk[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=0;i<n;i++) scanf("%d%d",&mac[i].x,&mac[i].y);
		for(int i=0;i<m;i++) scanf("%d%d",&wrk[i].x,&wrk[i].y);
		sort(mac,mac+n,cmp); sort(wrk,wrk+m,cmp);
		long long tot=0,money=0;
		int cnt[105]={0};
		for(int i=0,j=0;i<m;i++)
		{
			for(;j<n&&mac[j].x>=wrk[i].x;j++) cnt[mac[j].y]++;
			for(int k=wrk[i].y;k<=100;k++) if(cnt[k])
			{
				cnt[k]--;
				tot++; money+=wrk[i].x*500+wrk[i].y*2;
				break;
			}
		}
		printf("%lld %lld\n",tot,money);
	}
	return 0;
}
/*
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int maxn=100005;
struct Data { int x,y; };
inline bool cmp(const Data &a,const Data &b) { return a.x>b.x||(a.x==b.x&&a.y>b.y); }
int n,m;
Data mac[maxn],wrk[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)==2)
	{
		for(int i=0;i<n;i++) scanf("%d%d",&mac[i].x,&mac[i].y);
		for(int i=0;i<m;i++) scanf("%d%d",&wrk[i].x,&wrk[i].y);
		sort(mac,mac+n,cmp); sort(wrk,wrk+m,cmp);
		long long tot=0,money=0;
		int cnt[105]={0};
		multiset<int> st;
		for(int i=0,j=0;i<m;i++)
		{
			for(;j<n&&mac[j].x>=wrk[i].x;j++) st.insert(mac[j].y);
			multiset<int>::iterator it=st.lower_bound(wrk[i].y);
			if(it==st.end()) continue;
			st.erase(it);
			tot++; money+=wrk[i].x*500+wrk[i].y*2;
		}
		printf("%lld %lld\n",tot,money);
	}
	return 0;
}
*/
