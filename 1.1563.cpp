#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int n,m,pos,a,s;
char name[maxn][15];
int p[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d%s",&p[i],name[i]);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&s);
		if(a^p[pos]) pos=(pos+s)%n;
		else pos=(pos-s+n)%n;
	}
	printf("%s\n",name[pos]);
	return 0;
}
