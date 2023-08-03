#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<set>
using namespace std;
map<string,int> h_si;
map<pair<int,int>,int> hsh;
string h_is[100005];
int mp[10005][15],m,n;
int ID(const string& s)
{
	if(h_si.count(s)) return h_si[s];
	int t=h_si.size();
	h_si[s]=t;
	h_is[t]=s;
	return t;
}
void solve()
{
	string s;
	int i,j,k,la;
	for(i=1;i<=n;i++)
	{
		getline(cin,s);
		s+=',';
//		cout<<'\t'<<s<<endl<<'\t'<<s.size()<<endl;
		k=la=0;
		for(j=1;j<=m;j++)
		{
			for(;k<s.size()&&s[k]!=',';k++); 
			mp[i][j]=ID(s.substr(la,k-la));
			k++;
			la=k;
		}
	}
	pair<int,int> t;
	for(i=1;i<m;i++)
		for(j=i+1;j<=m;j++)
		{
			hsh.clear();
			for(k=1;k<=n;k++)
			{
				t=make_pair(mp[k][i],mp[k][j]);
				if(hsh.count(t))
				{
					cout<<"NO\n"<<hsh[t]<<' '<<k<<'\n'<<i<<' '<<j<<endl;
					return;
				}
				else hsh[t]=k;
			}
		}
	cout<<"YES"<<endl;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>n>>m)
	{
		h_si.clear();
		cin.get();
		solve();
	}
	return 0;
}
/*
NO
2 3
2 3
YES
*/
