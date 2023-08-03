#include<iostream>
#include<string>
using namespace std;
string s1,s2;
int dp[1001][1001];
inline int max(int a,int b){return a>b?a:b;}
void solve()
{
	int i,j;
	for(i=1;i<s1.size();i++)
		for(j=1;j<s2.size();j++)
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	printf("%d\n",dp[s1.size()-1][s2.size()-1]);
}
void init()
{
	cin>>s1>>s2;
	s1=" "+s1;
	s2=" "+s2;
}
int main()
{
	init();
	solve();
	return 0;
}
