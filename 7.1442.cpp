#include<cstdio>
#include<algorithm>
#include<queue>
#include<cassert>
using namespace std;
const int maxn=30005;
int m,n,a[maxn],gt[maxn];
priority_queue<int> S; priority_queue<int,vector<int>,greater<int> > B;
inline void insert(int x)
{
	if(S.empty()&&B.empty()) { B.push(x); return; }
	if((B.size()&&B.top()<=x)||(S.size()&&S.top()<x)) { B.push(x); return; }
	S.push(x);
}
void show()
{
	printf("S:");
	static int buf[maxn]; int cnt=0;
	while(S.size()) { buf[cnt++]=S.top(); S.pop(); }
	for(int i=0;i<cnt;i++) { printf(" %d",buf[i]); S.push(buf[i]); }
	cnt=0;
	printf("\nB:");
	while(B.size()) { buf[cnt++]=B.top(); B.pop(); }
	for(int i=0;i<cnt;i++) { printf(" %d",buf[i]); B.push(buf[i]); }
	printf("\n");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&gt[i]);
	int p=1;
	for(int i=1;i<=n;i++)
	{
		while(p<=gt[i]) insert(a[p]),p++;
		while(S.size()<i) { S.push(B.top()); B.pop(); }
		while(S.size()>i) { B.push(S.top()); S.pop(); }
		//show();
		printf("%d\n",S.top());
		//assert(S.top()<=B.top());
	}
	return 0;
}
