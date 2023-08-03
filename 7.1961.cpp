#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000005;
int n,kase,nxt[maxn]; char s[maxn];
inline void build()
{
	nxt[1]=0;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j>0&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		scanf("%s",s+1);
		build();
		printf("Test case #%d\n",++kase);
		for(int i=2;i<=n;i++) if(i%(i-nxt[i])==0&&i/(i-nxt[i])>1) printf("%d %d\n",i,i/(i-nxt[i]));
		puts("");
	}
	return 0;
}
