#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node { int a,b; };
inline bool operator<(const Node &a,const Node &b) { return a.b>b.b; }
int n,s[205],f[205][40005]; Node p[205];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&p[i].a,&p[i].b);
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+p[i].a;
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=s[i];j++)
		{
			if(j>=p[i].a) f[i][j]=max(f[i-1][j-p[i].a],j+p[i].b);
			f[i][j]=min(f[i][j],max(f[i-1][j],s[i]-j+p[i].b));
		}
	int res=0x3f3f3f3f;
	for(int i=0;i<=s[n];i++) res=min(res,f[n][i]);
	printf("%d\n",res);
	return 0;
}
