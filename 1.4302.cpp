#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,nd[105],f[105][105],pre[105][105],nxt[105][105];
char s[105];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	for(int i=2;i<=9;i++) nd[i]=1;
	for(int i=10;i<=99;i++) nd[i]=2;
	nd[100]=3;
	scanf("%s",s+1); n=strlen(s+1);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=1;
	for(int bg=1;bg<=n;bg++)
	{
		nxt[bg][0]=0;
		for(int i=2,j=0;i<=n-bg+1;i++)
		{
			while(j>0&&s[bg+i-1]!=s[bg+j])
				j=nxt[bg][j-1];
			if(s[bg+i-1]==s[bg+j]) j++;
			nxt[bg][i-1]=j;
		}
	}
	for(int len=2;len<=n;len++)
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			int &p=pre[i][j];
			p=i;
			for(int k=i+1;k<j;k++) if(f[i][p]+f[p+1][j]>f[i][k]+f[k+1][j]) p=k;
			f[i][j]=f[i][p]+f[p+1][j];
			int v=len-nxt[i][len-1];
			if(len%v==0)
				for(int k=1;v*k<=len;k++)
					if(len%(v*k)==0&&len/(v*k)>1&&f[i][i+v*k-1]+2+nd[len/(v*k)]<f[i][j])
					{
						f[i][j]=f[i][i+v*k-1]+2+nd[len/(v*k)];
						p=-v*k;
					}
		}
	printf("%d\n",f[1][n]);
	return 0;
}