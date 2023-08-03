#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
char v[maxn];
int l[maxn],r[maxn];
int n,d;
void solve()
{
	scanf("%s",v+1);
	l[0]=0;r[0]=1;
	for(int i=1;i<=n;i++)
	{
		l[i]=i-1;
		r[i]=i+1;
	}
	int p=1,t=n;
	while(d>0&&p!=t)
	{
		p=r[p];
		while(d>0&&l[p]!=0&&v[l[p]]<v[p])
		{
			r[l[l[p]]]=p;
			l[p]=l[l[p]];
			n--;
			d--;
		}
	}
	p=r[0];
	for(int i=0;i<n-d;i++)
	{
		putchar(v[p]);
		p=r[p];
	}
	printf("\n");
}
int main()
{
#ifdef local
//	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&d)==2&&n&&d)
	{
		solve();
	}
	return 0;
}
/*
7 3
3333114
3334
*/
