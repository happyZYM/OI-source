#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1005;
bool ish[maxn][maxn];
char str[maxn];
int len,d[maxn],i,j;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%s",str+1);
		len=strlen(str+1);
		memset(ish,0,sizeof(ish));
		for(i=1;i<=len;i++)
			for(j=1;j+i-1<=len;j++)
			{
				if(i==1) ish[j][j]=true;
				else if(i==2) ish[j][j+1]=(str[j]==str[j+1]);
				else ish[j][j+i-1]=(str[j]==str[j+i-1]&&ish[j+1][j+i-2]);
			}
		for(i=1;i<=len;i++)
		{
			d[i]=1<<30;
			if(ish[1][i]) d[i]=1;
			for(j=1;j<i;j++)
				if(ish[j+1][i]) d[i]=min(d[i],d[j]+1);
		}
		printf("%d\n",d[len]);
	}
	return 0;
}
