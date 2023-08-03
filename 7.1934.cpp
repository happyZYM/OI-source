#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n,m,f[105][105],na[105][26],nb[105][26];
char a[105],b[105];
string res[1005]; int cnt;
void dfs(int i,int j,string s,int nd)
{
	if(nd==0) { res[cnt++]=s; return; }
	if(i>n||j>m) return;
	if(a[i]==b[j])
	{
		string t=s+a[i];
		dfs(i+1,j+1,t,nd-1);
		return;
	}
	for(int v=0;v<26;v++)
		if(f[na[i-1][v]][nb[j-1][v]]==nd)
			dfs(na[i-1][v]+1,nb[j-1][v]+1,s,nd);
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%s%s",a+1,b+1); n=strlen(a+1); m=strlen(b+1);
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--)
		{
			if(a[i]==b[j]) f[i-1][j-1]=f[i][j]+1;
			else f[i-1][j-1]=max(f[i][j-1],f[i-1][j]);
		}
	for(int j=0;j<26;j++) { na[n][j]=n; nb[m][j]=m; }
	for(int i=n;i>=1;i--)
		for(int j=0;j<26;j++)
			if(a[i]==j+'a') na[i-1][j]=i-1;
			else na[i-1][j]=na[i][j];
	for(int i=m;i>=1;i--)
		for(int j=0;j<26;j++)
			if(b[i]==j+'a') nb[i-1][j]=i-1;
			else nb[i-1][j]=nb[i][j];
	dfs(1,1,"",f[0][0]);
	sort(res,res+cnt);
	for(int i=0;i<cnt;i++) printf("%s\n",res[i].c_str());
	return 0;
}