#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s1[maxn],s2[maxn];
int h1[128],h2[128];
int n;
bool ok()
{
	n=strlen(s1);
	map<char,int> mp1,mp2;
	for(int i=0;i<n;i++) mp1[s1[i]]++,mp2[s2[i]]++;
	vector<pair<int,char>> v1,v2;
	for(auto it=mp1.begin();it!=mp1.end();++it)
		v1.push_back(make_pair(it->second,it->first));
	for(auto it=mp2.begin();it!=mp2.end();++it)
		v2.push_back(make_pair(it->second,it->first));
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1.size()!=v2.size()) return false;
	int sz=v1.size();
	for(int i=0;i<sz;i++)
		if(v1[i].first!=v2[i].first) return false;
	memset(h1,-1,sizeof(h1));
	memset(h2,-1,sizeof(h2));
	for(int i=0;i<sz;i++)
	{
		if(h1[v1[i].second]==-1) h1[v1[i].second]=v2[i].second;
		else if(h1[v1[i].second]!=v2[i].second) return false;
		if(h2[v2[i].second]==-1) h2[v2[i].second]=v1[i].second;
		else if(h2[v2[i].second]!=v1[i].second) return false;
	}
	return true;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s%s",s1,s2)==2) printf("%s\n",ok()?"YES":"NO");
	return 0;
}
