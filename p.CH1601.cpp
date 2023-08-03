//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1601%20%E5%89%8D%E7%BC%80%E7%BB%9F%E8%AE%A1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxmem=1e6+5;
int G[maxmem][26],tot[maxmem],cnt,n,m;
char s[maxmem];
inline void insert(char *s)
{
	int len=strlen(s),p=0;
	for(int i=0;i<len;i++)
	{
		if(!G[p][s[i]-'a']) G[p][s[i]-'a']=++cnt;
		p=G[p][s[i]-'a'];
	}
	tot[p]++;
}
inline int query(char *s)
{
	int len=strlen(s),p=0,res=0;
	for(int i=0;i<len&&G[p][s[i]-'a'];i++)
	{
		p=G[p][s[i]-'a'];
		res+=tot[p];
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		insert(s);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		printf("%d\n",query(s));
	}
	return 0;
}
