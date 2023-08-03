#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
string word[50005],str;
int n;
int sh[27][27];//< -1   > 1
stack<int> stk;
char hsh[27];
int du[27];
bool hs[27];
string mp;
bool op(string &a,string &b)
{
	int max_len=min(a.size(),b.size());
	for(int i=0;i<max_len;i++)
	{
		if(a[i]!=b[i])
			switch(sh[a[i]-'a'][b[i]-'a'])
			{
				case 1:
					return 1;
				case -1:
					return 0;
				case 0:
					sh[a[i]-'a'][b[i]-'a']=-1;
					sh[b[i]-'a'][a[i]-'a']=1;
					return 0;
			}
	}
	return 0;
}
int main()
{
	freopen("virus.in","r",stdin);
	freopen("virus.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>word[i];
		for(int j=0;j<word[i].size();j++)
			if(!hs[word[i][j]-'a'])
			{
				hs[word[i][j]-'a']=1;
				mp+=word[i][j];
			}
	}
	cin>>str;
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(op(word[j],word[i]))
			{
				cout<<0<<endl;
//				cout<<"break in place 1!\n"<<endl;
				return 0;
			}
	sort(mp.begin(),mp.end());
	for(int i=0;i<mp.size();i++)
		for(int j=0;j<mp.size();j++)
			if(j!=i&&sh[mp[j]-'a'][mp[i]-'a']==-1)
				du[mp[i]-'a']++;
//	cout<<"du: "<<endl;
//	for(int i=0;i<mp.size();i++)
//		cout<<mp[i]<<" "<<du[mp[i]-'a']<<endl;
	for(int i=0;i<mp.size();i++)
		if(!du[mp[i]-'a'])
			stk.push(mp[i]-'a');
	if(stk.size()>=2)
	{
		cout<<0<<endl;
//		cout<<"break in place 2!\n"<<endl;
		return 0;
	}
	int now=0;
	memset(hsh,-1,sizeof(hsh));
//	cout<<"stack:";
	while(stk.size())
	{
		hsh[stk.top()]=now++;
		du[stk.top()]=-1;
//		cout<<char(stk.top()+'a');
		for(int i=0;i<mp.size();i++)
			if(stk.top()!=mp[i]-'a'&&sh[stk.top()][mp[i]-'a']==-1)
			{
				sh[stk.top()][mp[i]-'a']=0;
				du[mp[i]-'a']--;
			}
		stk.pop();
		for(int i=0;i<mp.size();i++)
			if(!du[mp[i]-'a'])
				stk.push(mp[i]-'a');
		if(stk.size()>=2)
		{
//			cout<<endl;
//			cout<<"du: "<<endl;
//			for(int i=0;i<mp.size();i++)
//				 cout<<mp[i]<<" "<<du[mp[i]-'a']<<endl;
			cout<<0<<endl;
//			cout<<"break in place 3!\n"<<endl;
			return 0;
		}
	}
//	cout<<endl;
	for(int i=0;i<str.size();i++)
		if(hsh[str[i]-'a']>-1)
			str[i]=hsh[str[i]-'a']+'a';
		else
		{
			cout<<0<<endl;
//			cout<<"break in place 4!\n"<<endl;
			return 0;
		}
	cout<<str<<endl;
	return 0;
}
/*
c -> a
e -> b
d -> c
a -> d
b -> e

6
cebdbac
cac
ecd
dca
aba
bac
cedab


abeceda
ada
bac
cad
ded
eda
*/
