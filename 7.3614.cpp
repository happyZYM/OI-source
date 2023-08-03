#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=2505;
struct Cow { int L,R; };
inline bool operator<(const Cow &a,const Cow &b) { return a.L>b.L; }
int n,m,cnt[1005],res;
Cow cow[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%d",&cow[i].L,&cow[i].R);
	for(int i=0;i<m;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		cnt[a]+=b;
	}
	sort(cow,cow+n);
	for(int i=0;i<n;i++)
		for(int j=cow[i].R;j>=cow[i].L;j--) if(cnt[j])
		{
			res++;
			cnt[j]--;
			break;
		}
	printf("%d\n",res);
	return 0;
}
