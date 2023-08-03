#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int n,nxt[maxn]; char a[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%s",&n,a+1);
	nxt[1]=0;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&a[i]!=a[j+1]) j=nxt[j];
		if(a[i]==a[j+1]) j++;
		nxt[i]=j;
	}
	printf("%d\n",n-nxt[n]);
	return 0;
}
