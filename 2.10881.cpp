#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10005;
struct Ant
{
	int id,p,d;
	inline bool operator<(const Ant &b) const
	{ return p<b.p; }
} bef[maxn],aft[maxn];
char* st[]={"L","Turning","R"};
int rnk[maxn];
int K;
int L,T,n;
int p,d,id;
char c;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&K);
	for(int kase=1;kase<=K;kase++)
	{
		scanf("%d%d%d",&L,&T,&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d %c",&p,&c);
			d=(c=='L'?-1:1);
			bef[i]=(Ant){i,p,d};
			aft[i]=(Ant){0,p+T*d,d};
		}
		sort(bef,bef+n);
		for(int i=0;i<n;i++)
			rnk[bef[i].id]=i;
		sort(aft,aft+n);
		for(int i=0;i<n-1;i++)
			if(aft[i].p==aft[i+1].p)
				aft[i].d=aft[i+1].d=0;
		printf("Case #%d:\n",kase);
		for(int i=0;i<n;i++)
		{
			id=rnk[i];
			if(aft[id].p<0||aft[id].p>L) printf("Fell off\n");
			else printf("%d %s\n",aft[id].p,st[aft[id].d+1]);
		}
		printf("\n");
	}
	return 0;
}
