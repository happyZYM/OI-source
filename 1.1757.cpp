#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
template<typename T> inline void read(T& t)
{
    t=0; int ch,f=false;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+(ch^48);
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
int n,m,t,a,b,c;
vector<int> v[105],w[105];
int f[1005];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(m,n);
	while(n-->0)
	{
		read(a,b,c);
		w[c].push_back(a); v[c].push_back(b); t=max(c,t);
	}
	for(int i=1;i<=t;i++)
		for(int j=m;j>=0;j--)
			for(int k=0;k<v[i].size();k++)
				if(j>=w[i][k])
					f[j]=max(f[j],f[j-w[i][k]]+v[i][k]);
	printf("%d\n",f[m]);
	return 0;
}
