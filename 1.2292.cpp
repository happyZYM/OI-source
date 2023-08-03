#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=25;
const int maxmem=11*maxn;
const int maxlen=1024*1024+10;
int n,m,G[maxmem][26],v[maxmem],dp[maxlen],cnt=1;
char s[maxlen];
void insert(char *s,int len)
{
	int p=0;
	for(int i=0;i<len;i++)
	{
		if(!G[p][s[i]-'a']) G[p][s[i]-'a']=cnt++;
		p=G[p][s[i]-'a'];
	}
	v[p]=1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) { scanf("%s",s); insert(s,strlen(s)); }
	while(m-->0)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),res=0;
		memset(dp,0,sizeof(dp)); dp[0]=1;
		for(int i=0;i<len;i++)
		{
			if(!dp[i]) continue;
			int p=0,l=1;
			do
			{
				p=G[p][s[i+l]-'a'];
				if(v[p]) dp[i+l]=1;
				l++;
			}
			while(p);
		}
		for(int i=1;i<=len;i++) if(dp[i]) res=i;
		printf("%d\n",res);
	}
	return 0;
}
