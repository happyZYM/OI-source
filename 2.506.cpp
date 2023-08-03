#include<bits/stdc++.h>
using namespace std;
const int MAXN=1024000;
map<string,int> name2id;
string id2name[MAXN];
vector<int> depend[MAXN],depended[MAXN];
int status[MAXN];
vector<int> installed;
int id(const string &s)
{
    if(name2id.count(s)) return name2id[s];
    else
	{
        int d=name2id.size();
        name2id[s]=d;
        id2name[d]=s;
        return d;
    }
}
inline string& name(const int &id) {return id2name[id];}
inline bool needed(const int &item)
{
    for(int i=0;i!=depended[item].size();++i)
		if(status[depended[item][i]]) return true;
    return false;
}
inline void ins(const int &item, const bool &toplevel)
{
    if(!status[item])
	{
        for(int i=0;i!=depend[item].size();++i)
			ins(depend[item][i], false);
        cout<<"   Installing "<<name(item)<<'\n';
        status[item]=toplevel?1:2;
        installed.push_back(item);
    }
	else if(toplevel)
		cout<<"   "<<name(item)<<" is already installed."<<'\n';
}
inline void del(const int &item, const bool &toplevel)
{
    if(toplevel && !status[item])
		cout<<"   "<<name(item)<<" is not installed."<<'\n';
    else if(toplevel && needed(item))
		cout<<"   "<<name(item)<<" is still needed."<<'\n';
    else if((toplevel||status[item]==2)&&!needed(item))
	{
        status[item]=0;
		installed.erase(find(installed.begin(),installed.end(),item));
		cout<<"   Removing "<<name(item)<<endl;
		for(int i=0;i<depend[item].size();i++)
			del(depend[item][i],false);
    }
}
inline void List()
{
	for(int i=0;i!=installed.size();++i)
		cout<<"   "<<name(installed[i])<<'\n';
}
inline void setdepend(istringstream &ss)
{
    string s1,s2;
    ss>>s1;
    int id1=id(s1);
    while(ss>>s2)
	{
        int id2=id(s2);
        depend[id1].push_back(id2);
        depended[id2].push_back(id1);
    }
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    ios::sync_with_stdio(false);
    string cmd;
    while(getline(cin,cmd))
	{
        cout<<cmd<<endl;
        istringstream line(cmd);
        line>>cmd;
        if(cmd=="END") break;
        if(cmd[0]=='L') List();
        else if(cmd[0]=='D') setdepend(line);
        else if(cmd[0]=='I')
		{
            string s;
            line>>s;
            ins(id(s),true);
        }
        else if(cmd[0]='R')
		{
            string s;
            line>>s;
            del(id(s),true);
        }
    }
    return 0;
}
