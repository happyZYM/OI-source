#include<iostream>
using namespace std;
int t;
int n;
typedef unsigned long long ULL;
const int maxn=1005;
int f[maxn][maxn*6],p[maxn];
int PowMod(ULL a,ULL b,int n)
{
	if(!b) return 1;
	int k=PowMod(a,b>>1,n);
	k=k*k%n;
	if(b&1) k=k*a%n;
	return k;
}
int solve(ULL a,ULL b,int n)
{
	if(a==0||n==1) return 0;
	int t=PowMod(a%p[n],b,p[n]);
    return f[n][t];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int n=2;n<=1000;++n)
	{
		f[n][0]=0;
		f[n][1]=1;
		for(int i=2;;i++)
		{
			f[n][i]=(f[n][i-1]+f[n][i-2])%n;
			if(f[n][i-1]==0&&f[n][i]==1)
			{
				p[n]=i-1;
				break;
			}
		}
	}
	cin>>t;
	ULL a,b;
	while(t-->0)
	{
		cin>>a>>b>>n;
		cout<<solve(a,b,n)<<endl;
	}
	return 0;
}
