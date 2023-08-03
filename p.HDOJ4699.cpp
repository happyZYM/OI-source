//http://acm.hdu.edu.cn/showproblem.php?pid=4699
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int stka[maxn],stkb[maxn],la,lb,Q,s[maxn],f[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	f[0]=-0x3f3f3f3f;
	while(scanf("%d",&Q)==1)
	{
		la=lb=0;
		while(Q-->0)
		{
			char a[2]; int b; scanf("%s",a);
			if(a[0]=='I')
			{
				scanf("%d",&stka[++la]);
				s[la]=s[la-1]+stka[la];
				f[la]=max(f[la-1],s[la]);
			}
			else if(a[0]=='D'&&la) la--;
			else if(a[0]=='L'&&la) stkb[++lb]=stka[la--];
			else if(a[0]=='R'&&lb)
			{
				stka[++la]=stkb[lb--];
				s[la]=s[la-1]+stka[la];
				f[la]=max(f[la-1],s[la]);
			}
			else if(a[0]=='Q') { scanf("%d",&b); printf("%d\n",f[b]); }
		}
	}
	return 0;
}
