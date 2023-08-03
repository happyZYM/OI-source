#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int fa[30];
int ff(int x)
{
	int a,b;
	a=x;
	while(x!=fa[x]) x=fa[x];
	while(a!=x)
	{
		b=fa[a];
		fa[a]=x;
		a=b;
	}
	return x;
}
int rd[30],cd[30],n;
char str[1005];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	bool f1,f2;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		memset(rd,0,sizeof(rd));
		memset(cd,0,sizeof(cd));
		for(int i=0;i<26;i++) fa[i]=i;
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			int len=strlen(str);
			rd[str[len-1]-'a']++;
			cd[str[0]-'a']++;
			if(ff(str[0]-'a')!=ff(str[len-1]-'a'))
				fa[ff(str[0]-'a')]=ff(str[len-1]-'a');
		}
		for(int i=1;i<26;i++)
			if((rd[i]||cd[i])&&ff(i)!=ff(0))
			{
				printf("The door cannot be opened.\n");
				goto next;
			}
		f1=f2=0;
		for(int i=0;i<26;i++)
			if(rd[i]||cd[i])
			{
				if(abs(rd[i]-cd[i]>1))
				{
					printf("The door cannot be opened.\n");
					goto next;
				}
				if(rd[i]-cd[i]==1) f1=1;
				if(cd[i]-rd[i]==1) f2=1;
			}
		if(f1==f2)
		{
			printf("Ordering is possible.\n");
			goto next;
		}
		
next:
		continue;
	}
	return 0;
}
/*
The door cannot be opened.
Ordering is possible.
The door cannot be opened.
*/
