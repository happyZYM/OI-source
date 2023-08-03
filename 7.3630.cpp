#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10005;
int T,n;
char buf[15];
int G[maxn*10][10],v[maxn*10],cnt;
inline int insert(char *s)
{
	int len=strlen(s),p=0;
	for(int i=0;i<len;i++)
	{
		if(!G[p][s[i]-'0']) G[p][s[i]-'0']=cnt++;
		p=G[p][s[i]-'0'];
		if(v[p]==2||(i==len-1&&v[p]==1)) return 0;
		v[p]=1;
	}
	v[p]=2;
	return 1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T-->0)
	{
		cnt=1; memset(G,0,sizeof(G)); memset(v,0,sizeof(v));
		scanf("%d",&n);
		bool res=1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",buf);
			res&=insert(buf);
		}
		puts(res?"YES":"NO");
	}
	return 0;
}
