#include<iostream>
#include<string>
#include<map>
using namespace std;
string mor[128];
map<string,string>m;
char c;
string t;
int diff(const string &ta,const string &tb)
{
	string a,b;
	if(ta.size()>tb.size()) a=ta,b=tb;
	else a=tb,b=ta;
	if(a.find(b)==0)
		return a.size()-b.size();
	else return 0x7fffffff;
}
void encode(const string &w)
{
	string y;
	for(int i=0;i<w.size();i++)
		y+=mor[w[i]];
	m[w]=y;
}
void solve(const string &t)
{
	string res=m.begin()->first;
	int d,mdiff=0x7fffffff;
	bool found=false;
	for(auto i=m.begin();i!=m.end();++i)
	{
		d=diff(i->second,t);
		if(d==0&&mdiff==0) found=true;
		if(d<mdiff)
		{
			res=i->first;
			mdiff=d;
		}
	}
	if(mdiff) res+='?';
	else if(found) res+='!';
	cout<<res<<endl;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>c&&c!='*') cin>>mor[c];
	while(cin>>t&&t[0]!='*') encode(t);
	while(cin>>t&&t[0]!='*') solve(t);
	return 0;
}
