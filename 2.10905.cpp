#include<bits/stdc++.h>
using namespace std;
string s[55];
int n;
int idx[55];
inline bool cmp(int a,int b)
{
	return s[a]+s[b]>s[b]+s[a];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>n,n!=0)
	{
		for(int i=0;i<n;i++)
		{
			idx[i]=i;
			cin>>s[i];
		}
		sort(idx,idx+n,cmp);
		for(int i=0;i<n;i++) cout<<s[idx[i]];
		cout<<endl;
	}
	return 0;
}
