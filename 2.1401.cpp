#include<cstdio>
#include<cstring>
const int mod=20071027;
const int maxL=300000;
int L,S,d[maxL+5],kase;
char str[maxL+5],tmp[105];
const int maxnode=4000*105;
const int sigma_size=26;
struct Trie
{
	int ch[maxnode][sigma_size];
	bool val[maxnode];
	int sz;
	Trie() { sz=1; }
	inline void clear()
	{
		sz=1;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
	}
	inline void insert(char *s)
	{
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++)
		{
			int c=s[i]-'a';
			if(!ch[u][c])
				ch[u][c]=sz++;
			u=ch[u][c];
		}
		val[u]=1;
	}
}trie;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s",str)==1)
	{
		L=strlen(str);
		scanf("%d",&S);
		memset(d,0,sizeof(d));
		trie.clear();
		for(int i=0;i<S;i++)
		{
			scanf("%s",tmp);
			trie.insert(tmp);
		}
		d[L]=1;
		for(int i=L-1;i>=0;i--)
			for(int j=0,u=0;i+j<L&&trie.ch[u][str[i+j]-'a'];j++)
			{
				u=trie.ch[u][str[i+j]-'a'];
				if(trie.val[u]) d[i]=(d[i]+d[i+j+1])%mod;
			}
		printf("Case %d: %d\n",++kase,d[0]);
	}
	return 0;
}
