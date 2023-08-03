#include<iostream>
#include<string>
#include<map>
#define maxn 50000
using namespace std;
map<string,int> s_i;
map<int,string> i_s;
int fa[maxn+1],n,id=1,a,b;
string str,faname;
char mode;
int findf(int aa)
{
	while(fa[aa]!=aa) aa=fa[aa];
	return aa;
}
int main()
{
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	for(int i=1;i<=maxn;i++) fa[i]=i;
	while(mode!='$')
	{
		mode=getchar();
		switch(mode)
		{
			case '#':
				cin>>str;
				if(s_i[str]==0)
				{
					a=id;
					s_i[str]=id;
					i_s[id++]=str;
				}
				else a=s_i[str];
				break;
			case '+':
				cin>>str;
				if(s_i[str]==0)
				{
					b=id;
					s_i[str]=id;
					i_s[id++]=str;
					fa[b]=a;
				}
				else fa[s_i[str]]=a;
				break;
			case '?':
				cin>>str;
				cout<<str<<" "<<i_s[findf(s_i[str])]<<endl;
				break;
		}
		getchar();
	}
	return 0;
}
