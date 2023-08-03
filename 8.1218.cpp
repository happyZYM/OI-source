#include<cstdio>
#include<algorithm>
using namespace std;
int n,R,s[5001][5001];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&R);
	for(int i=1;i<=n;i++)
	{
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		s[x][y]+=z;
	}
	for(int i=1;i<=5000;i++) s[0][i]+=s[0][i-1];
	for(int i=1;i<=5000;i++) s[i][0]+=s[i-1][0];
	for(int i=1;i<=5000;i++) for(int j=1;j<=5000;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
	int res=0;
	for(int i=R-1;i<=5000;i++) for(int j=R-1;j<=5000;j++)
		if(i==R-1)
			if(j==R-1)
				res=max(res,s[i][j]);
			else 
				res=max(res,s[i][j]-s[i][j-R]);
		else
			if(j==R-1)
				res=max(res,s[i][j]-s[i-R][j]);
			else 
				res=max(res,s[i][j]-s[i-R][j]-s[i][j-R]+s[i-R][j-R]);
	printf("%d\n",res);
	return 0;
}
