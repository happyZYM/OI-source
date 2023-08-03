#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[205],word[7][205];
int p,k,n,len_s;
int hav[205][205],len[205],dp[205][45];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&p,&k);
	for(int i=0;i<p;i++) scanf("%s",s+i*20); len_s=strlen(s);
	scanf("%d",&n);
	for(int i=0;i<n;i++) { scanf("%s",word[i]); len[i]=strlen(word[i]); }
	for(int r=0;r<len_s;r++)
		for(int l=r;l>=0;l--)
		{
			hav[l][r]=hav[l+1][r];
			for(int i=0;i<n;i++)
			{
				char* p=strstr(s+l,word[i]);
				if(p!=NULL&&p==s+l&&len[i]<=r-l+1) { hav[l][r]++; break; }
			}
		}
	for(int i=0;i<len_s;i++) dp[i][1]=hav[0][i];
	for(int i=2;i<=k;i++)
		for(int j=0;j<len_s;j++)
			for(int l=j-1;l>=i-1;l--)
				dp[j][i]=max(dp[j][i],dp[l-1][i-1]+hav[l][j]);
	printf("%d\n",dp[len_s-1][k]);
	return 0;
}
