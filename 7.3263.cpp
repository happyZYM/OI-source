#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,p,h,m,d[10005];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&p,&h,&m);
	set<pair<int,int> > st;
	for(int i=0;i<m;i++)
	{
		int L,R; scanf("%d%d",&L,&R);
		if(L>R) swap(L,R);
		if(st.find(make_pair(L,R))!=st.end()) continue;
		st.insert(make_pair(L,R));
		d[L+1]--; d[R]++;
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		printf("%d\n",d[i]+h);
	}
	return 0;
}
