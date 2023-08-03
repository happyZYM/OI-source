#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1026;
char s[maxn][maxn];
int st[maxn];
int n;
void solve()
{
	memset(st,0,sizeof(st));
	int i,j;
	vector<int> black,gray;
	int size=n,match;
	while(size>1)
	{
		black.clear();gray.clear();
		for(i=0;i<n;i++) st[i]=(st[i]==-1?-1:0);
		for(i=1;i<n;i++)
			if(!st[i]&&s[0][i]=='0')
			{
				black.push_back(i);
				continue;
			}
		for(i=1;i<n;i++)
			if(!st[i]&&s[0][i]=='1')
				for(j=1;j<n;j++)
					if(!st[j]&&j!=i&&s[0][j]=='0'&&s[i][j]=='1')
					{
						gray.push_back(i);
						break;
					}
		
		for(i=0;i<black.size();i++)
			for(j=0;j<gray.size();j++)
				if(!st[gray[j]]&&s[gray[j]][black[i]]=='1')
				{
					st[black[i]]=-1;
					st[gray[j]]=1;
					printf("%d %d\n",black[i]+1,gray[j]+1);
					break;
				}
		
		for(i=1;i<n;i++)
			if(s[0][i]=='1'&&!st[i])
			{
				printf("1 %d\n",i+1);
				st[i]=-1;
				st[0]=1;
				break;
			}
		
		match=-1;
		for(i=0;i<black.size();i++)
			if(!st[black[i]])
			{
				if(match==-1) match=black[i];
				else
				{
					printf("%d %d\n",match+1,black[i]+1);
					if(s[match][black[i]]=='1')
					{
						st[match]=1;
						st[black[i]]=-1;
					}
					else
					{
						st[match]=-1;
						st[black[i]]=1;
					}
					match=-1;
				}
			}
		
		match=-1;
		for(i=0;i<n;i++)
			if(!st[i])
			{
				if(match==-1) match=i;
				else
				{
					printf("%d %d\n",match+1,i+1);
					if(s[match][i]=='1')
					{
						st[match]=1;
						st[i]=-1;
					}
					else
					{
						st[match]=-1;
						st[i]=1;
					}
					match=-1;
				}
			}
		size=size/2;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		fgets(s[0],maxn,stdin);
		for(int i=0;i<n;i++)
			fgets(s[i],maxn,stdin);
		solve();
	}
	return 0;
}
