#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int son[4000010],bro[4000010],l[4010],n,sz;
LL size[4000010];
char ch[4000010],s[4010][1010];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		l[i]=strlen(s[i]+1);
	}
	memset(son,0,sizeof(son));
	memset(bro,0,sizeof(bro));
	sz=0;
}
LL solve()
{
	init();
	int i,j,k,p,tmp;
	bool flag;
	LL res=0,last;
	for(i=1;i<=n;i++)
	{
		p=0;
		last=i-1;
		for(j=1;j<=l[i]+1;j++)
		{
			flag=0;
			for(k=son[p];k;tmp=k,k=bro[k])
				if(ch[k]==s[i][j])
				{
					flag=1;
					break;
				}
			if(flag) p=k;
			else
			{
				if(!son[p]) son[p]=++sz;
				else bro[tmp]=++sz;
				p=sz;
				ch[p]=s[i][j];
				size[p]=0;
			}
			res+=size[p]+last;
			last=size[p];
			size[p]++;
		}
	}
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    int K=0;
    while(scanf("%d",&n)==1&&n)
        printf("Case %d: %lld\n",++K,solve());
    return 0;
}
