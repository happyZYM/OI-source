#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
inline void pro_addr(const string &s,string &usr,string& mta)
{
	int p=s.find('@');
	usr=s.substr(0,p);
	mta=s.substr(p+1);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int k;
	string s,t,u1,m1,u2,m2;
	set<string> addr;
	while(cin>>s&&s!="*")
	{
		cin>>s>>k;
		while(k--)
		{
			cin>>t;
			addr.insert(t+"@"+s);
		}
	}
	while(cin>>s&&s!="*")
	{
		pro_addr(s,u1,m1);
		vector<string> mta;
		map<string,vector<string>> dest;
		set<string> vis;
		while(cin>>t&&t!="*")
		{
			pro_addr(t,u2,m2);
			if(vis.count(t)) continue;
			vis.insert(t);
			if(!dest.count(m2))
			{
				mta.push_back(m2);
				dest[m2]=vector<string>();
			}
			dest[m2].push_back(t);
		}
		getline(cin,t);
		
		string data;
		while(getline(cin,t)&&t[0]!='*') data+="     "+t+"\n";
		for(int i=0;i<mta.size();i++)
		{
			string mta2=mta[i];
			vector<string> usr=dest[mta2];
			cout<<"Connection between "<<m1<<" and "<<mta2<<endl;
			cout<<"     HELO "<<m1<<"\n";
			cout<<"     250\n";
			cout<<"     MAIL FROM:<"<<s<<">\n";
			cout<<"     250\n";
			bool ok=false;
			for(int i=0;i<usr.size();i++)
			{
				cout<<"     RCPT TO:<"<<usr[i]<<">\n";
				if(addr.count(usr[i]))
				{
					ok=true;
					cout<<"     250\n";
				}
				else cout<<"     550\n";
			}
			if(ok)
			{
				cout<<"     DATA\n";
				cout<<"     354\n";
				cout<<data;
				cout<<"     .\n";
				cout<<"     250\n";
			}
			cout<<"     QUIT\n";
			cout<<"     221\n";
		}
	}
	return 0;
}
