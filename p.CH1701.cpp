//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1701%20%E5%90%88%E5%B9%B6%E6%9E%9C%E5%AD%90
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long LL;
int n; LL res;
priority_queue<LL,vector<LL>,greater<LL> > Q;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) { int x; scanf("%d",&x); Q.push(x); }
	while(Q.size()>1)
	{
		LL a=Q.top(); Q.pop(); LL b=Q.top(); Q.pop();
		res+=a+b;
		Q.push(a+b);
	}
	printf("%lld\n",res);
	return 0;
}
