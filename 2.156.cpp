#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> cnt;
vector<string> res,words;
string repr(const string& s)
{
	string ans=s;
	for(int i=0;i<ans.size();i++)
		ans[i]=tolower(ans[i]);
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n=0;
	string s;
	while(cin>>s)
	{
		if(s=="#") break;
		words.push_back(s);
		s=repr(s);
		if(!cnt.count(s)) cnt[s]=0;
		cnt[s]++;
	}
	for(int i=0;i<words.size();i++)
		if(cnt[repr(words[i])]==1) res.push_back(words[i]);
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;
	return 0;
}
