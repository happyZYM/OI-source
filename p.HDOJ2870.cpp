#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
/*
a 1
b 2
c 3
w 4
x 5
y 6
z 7
 */
int n,m,a[maxn][maxn],b[maxn][maxn],up[maxn][maxn],id[128],ch[8][8],res,stk[maxn],w[maxn],p;
char s[maxn];
int solve(int co)
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) b[i][j]=ch[a[i][j]][co];
	for(int j=1;j<=m;j++) for(int i=1;i<=n;i++) up[i][j]=b[i][j]?up[i-1][j]+1:0;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res=max(res,up[i][1]);
		p=1; stk[1]=up[i][1]; w[1]=1;
		for(int j=2;j<=m+1;j++)
		{
			if(up[i][j]>stk[p]) { stk[++p]=up[i][j]; w[p]=1; }
			else
			{
				int width=0;
				while(stk[p]>up[i][j])
				{
					width+=w[p];
					res=max(res,width*stk[p]);
					p--;
				}
				stk[++p]=up[i][j]; w[p]=width+1;
			}
		}
	}
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	id['a']=1; id['b']=2; id['c']=3; id['w']=4; id['x']=5; id['y']=6; id['z']=7;
	ch[1][1]=ch[2][2]=ch[3][3]=1;
	ch[4][1]=ch[4][2]=1;
	ch[5][2]=ch[5][3]=1;
	ch[6][1]=ch[6][3]=1;
	ch[7][1]=ch[7][2]=ch[7][3]=1;
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b)); memset(up,0,sizeof(up)); res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) a[i][j]=id[s[j]];
		}
		for(int co=1;co<=7;co++) res=max(res,solve(co));
		printf("%d\n",res);
	}
	return 0;
}