#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1000005;
char T[maxn],P[maxn];
int n,m,f[maxn],j;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s%s",T+1,P+1); n=strlen(T+1); m=strlen(P+1);
	for(int i=2;i<=m;i++)
	{
		while(j&&P[j+1]!=P[i]) j=f[j];
		if(P[j+1]==P[i]) j++;
		f[i]=j;
	}
	j=0;
	for(int i=1;i<=n;i++)
	{
		while(j&&P[j+1]!=T[i]) j=f[j];
		if(P[j+1]==T[i]) j++;
		if(j==m) printf("%d\n",i-m+1);
	}
	for(int i=1;i<=m;i++) printf("%d ",f[i]); printf("\n");
	return 0;
}
