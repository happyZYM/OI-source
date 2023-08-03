#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
const int P=50005;
struct Data
{
	int a,b,s,f;
	Data() { }
	Data(int _a,int _b,int _s,int _f):a(_a),b(_b),s(_s),f(_f) { }
};
inline bool operator<(const Data &a,const Data &b) { return a.s+a.f>b.s+b.f; }
priority_queue<Data> Q;
set<int> vis;
int n; Data u;
inline int gcd(int a,int b) { return b?gcd(b,a%b):a; }
inline void Ext(int a,int b)
{
	if(a==0&&b==0) return;
	if(a<b) swap(a,b);
	if(b>170) return;
	if(a>2*n) return;
	if(b==0&&a>n) return;
	if(n%gcd(a,b)) return;
	if(vis.find(a*P+b)!=vis.end()) return;
	int h=0,t=a;
	while(t<n) t<<=1,h++;
	Q.push(Data(a,b,u.s+1,h));
//	printf("push %d %d %d %d\n",a,b,u.s+1,h);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
//	freopen("pro.out","w",stdout);
#endif
	scanf("%d",&n);
	Q.push(Data(1,0,0,0));
	while(Q.size())
	{
		u=Q.top(); Q.pop();
		if(vis.find(u.a*P+u.b)!=vis.end()) continue;
//		printf("dis[%d,%d]=%d\n",u.a,u.b,u.s);
		if(u.a==n) { printf("%d\n",u.s); return 0; }
		vis.insert(u.a*P+u.b);
		Ext(u.a+u.a,u.b); Ext(u.a,u.a+u.a);
		Ext(u.b+u.b,u.b); Ext(u.a,u.b+u.b);
		Ext(u.a+u.b,u.b); Ext(u.a,u.a+u.b);
		Ext(u.a-u.b,u.b); Ext(u.a,u.a-u.b);
	}
	return 0;
}
