//http://contest-hunter.org:83/contest/0x00%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E4%BE%8B%E9%A2%98/0701%20%E5%9B%BD%E7%8E%8B%E6%B8%B8%E6%88%8F
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
struct DC { int a,b; };
inline bool operator<(const DC &a,const DC &b) { return a.a*a.b<b.a*b.b; }
int n; DC p[maxn];
int x[maxn*4],y[maxn*4],res[maxn*4];
inline void times(int *a,int b)
{
	int jw=0;
	for(int i=1;i<=a[0];i++)
	{
		a[i]=a[i]*b+jw;
		jw=a[i]/10;
		a[i]%=10;
	}
	while(jw)
	{
		a[++a[0]]=jw%10;
		jw/=10;
	}
}
inline void div(int *a,int b,int *c)
{
	c[0]=a[0];
	int lst=0;
	for(int i=a[0];i>=1;i--)
	{
		c[i]=(lst*10+a[i])/b;
		lst=(lst*10+a[i])%b;
	}
	while(c[0]>1&&c[c[0]]==0) c[0]--;
}
inline bool LessThan(int *a,int *b)
{
	if(a[0]<b[0]) return true;
	if(a[0]>b[0]) return false;
	for(int i=a[0];i>=1;i--)
		if(a[i]<b[i]) return true;
		else if(a[i]>b[i]) return false;
	return false;
}
inline void CheckMax(int *a,int *b)
{
	if(LessThan(a,b)) memcpy(a,b,maxn<<4);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	int aa,bb; scanf("%d%d",&aa,&bb);
	for(int i=0;i<n;i++) scanf("%d%d",&p[i].a,&p[i].b);
	sort(p,p+n);
	while(aa>0) { x[++x[0]]=aa%10; aa/=10; }
	x[0]=max(x[0],1);
	res[0]=1; res[1]=1;
	for(int i=0;i<n;i++)
	{
		div(x,p[i].b,y);
		CheckMax(res,y);
		times(x,p[i].a);
	}
	for(int i=res[0];i>=1;i--) printf("%d",res[i]); puts("");
	return 0;
}
