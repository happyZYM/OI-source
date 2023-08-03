#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
const int maxn=150;
set<string> emmm;
int n,f[maxn][maxn][maxn];
string t,a,b[maxn];
inline void LOW(string &s)
{
	for(int i=0;i<s.size();i++) if('A'<=s[i]&&s[i]<='Z') s[i]=s[i]+32;
}
inline int low(char a) { return 'A'<=a&&a<='Z'?a+32:a; }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	cin>>n;
	for(int i=0;i<n;i++) { cin>>t; emmm.insert(t); }
	getline(cin,t);
	while(getline(cin,t))
	{
		if(t=="LAST CASE"||t=="LAST CASE\r") return 0;
		stringstream ss(t);
		ss>>a;
		a="#"+a;
		n=0;
		b[++n]="#";
		while(ss>>t)
		{
			LOW(t);
			if(emmm.find(t)!=emmm.end()) continue;
			n++;
			b[n]=t;
		}
		memset(f,0,sizeof(f));
		f[1][1][0]=1;
		for(int i=2;i<=a.size();i++)
			for(int j=2;j<=n;j++)
				for(int k=0;k<b[j].size();k++)
				{
					if(low(a[i-1])!=b[j][k]) continue;
					int &v=f[i][j][k];
					char c=low(a[i-2]);
					for(int l=0;l<b[j-1].size();l++) if(b[j-1][l]==c) v+=f[i-1][j-1][l];
					for(int l=0;l<k;l++) if(b[j][l]==c) v+=f[i-1][j][l];
				}
		int tot=0;
		for(int i=0;i<b[n].size();i++) tot+=f[a.size()][n][i];
		if(tot) cout<<a.substr(1)<<" can be formed in "<<tot<<" ways"<<endl;
		else cout<<a.substr(1)<<" is not a valid abbreviation"<<endl;
	}
	return 0;
}