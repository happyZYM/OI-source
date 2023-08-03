#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=125,maxs=8,oo=1000000000;
int m,n,s,c[maxn],st[maxn],d[maxn][1<<maxs][1<<maxs],x;
int dp(int i,int s0,int s1,int s2)
{
	if(i>=m+n) return s2==(1<<s)-1?0:oo;
	int &res=d[i][s1][s2];
	if(res>=0) return res;
	res=oo;
	if(i>=m) res=dp(i+1,s0,s1,s2);
	int m0=st[i]&s0,m1=st[i]&s1;
	s0^=m0;
	s1=(s1^m1)|m0;
	s2|=m1;
	res=min(res,c[i]+dp(i+1,s0,s1,s2));
  	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	string str;
	while(getline(cin,str))
	{
		stringstream ss(str);
		ss>>s>>m>>n;
		if(s==0) break;
		for(int i=0;i<m+n;i++)
		{
			getline(cin,str);
			stringstream ss(str);
			ss>>c[i];
			st[i]=0;
			while(ss>>x) st[i]|=(1<<(x-1));
		}
		memset(d,-1,sizeof(d));
		cout<<dp(0,(1<<s)-1,0,0)<<endl;
	}
	return 0;
}
