#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool e[26][26];
char str[1000];
int a[10],b[10],cnt,vis[26];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s",str)==1&&str[0]!='#')
	{
		memset(e,0,sizeof(e));
		memset(vis,0,sizeof(vis));
		cnt=0;
		char *c=str,f;
		while(*c!=0)
		{
			f=*c;
			if(!vis[f-'A'])
			{
				vis[f-'A']=1;
				a[cnt++]=f-'A';
			}
			c+=2;
			while(*c!=0&&*c!=';')
			{
				if(!vis[*c-'A'])
				{
					vis[*c-'A']=1;
					a[cnt++]=*c-'A';
				}
				e[f-'A'][*c-'A']=e[*c-'A'][f-'A']=1;
				c++;
			}
			if(*c==';') c++;
		}
		sort(a,a+cnt);
		int res=1<<30,now;
		do
		{
			now=0;
			for(int i=0;i<cnt;i++)
				for(int j=i+1;j<cnt;j++)
					if(e[a[i]][a[j]]) now=max(now,j-i);
			if(now<res)
			{
				res=now;
				memcpy(b,a,sizeof(b));
			}
		}
		while(next_permutation(a,a+cnt));
		for(int i=0;i<cnt;i++) printf("%c ",b[i]+'A');
		printf("-> %d\n",res);
	}
	return 0;
}
