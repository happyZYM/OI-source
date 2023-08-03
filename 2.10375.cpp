#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<int> primes;
int e[1300];
bool isp(int n)
{
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false; 
	return true;
}
inline void add_integer(int n,int d)
{
	for(int i=0;i<primes.size();i++)
	{
		while(n%primes[i]==0)
		{
			n/=primes[i];
			e[i]+=d;
		}
		if(n==1) break;
	}
}
inline void add_factorial(int n,int d)
{
	for(int i=1;i<=n;i++)
		add_integer(i,d);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=2;i<=10000;i++)
		if(isp(i)) primes.push_back(i);
	double p,q,r,s;
	while(scanf("%lf%lf%lf%lf",&p,&q,&r,&s)==4)
	{
		memset(e,0,sizeof(e));
		add_factorial(p,1);
		add_factorial(q,-1);
		add_factorial(p-q,-1);
		add_factorial(r,-1);
		add_factorial(s,1);
		add_factorial(r-s,1);
		double ans=1;
		for(int i=0;i<primes.size();i++)
			ans*=pow(primes[i],e[i]);
		printf("%.5lf\n",ans);
	}
	return 0;
}
