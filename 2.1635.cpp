#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=100005;
int useable[maxn];
void get_primes(int n,vector<int> &primes)
{
	int m=int(sqrt(n)+0.5);
	for(int i=2;i<=m;i++)
		if(n%i==0)
		{
			primes.push_back(i);
			while(n%i==0) n/=i;
		}
	if(n>1) primes.push_back(n);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n,m,kase=0;
	while(cin>>n>>m)
	{
		vector<int> primes;
		get_primes(m,primes);
		memset(useable,0,sizeof(useable));
		n--;
		for(int i=0;i<primes.size();i++)
		{
			int p=primes[i],e=0;//C(n,0) = p^e
			int min_e=0,x=m;
			while(x%p==0) {x/=p; min_e++;}
			//C(n,k)=C(n,k-1)*(n-k+1)/k
			for(int k=1;k<n;k++)
			{
				x=n-k+1;
				while(x%p==0) {x/=p; e++;}
				x=k;
				while(x%p==0) {x/=p; e--;}
				if(e<min_e) useable[k]=1;
			}
		}
		vector<int> res;
		for(int k=1;k<n;k++)
			if(!useable[k]) res.push_back(k+1);
		cout<<res.size()<<"\n";
		if(!res.empty())
		{
			cout<<res[0];
			for(int i=1;i<res.size();i++) cout<<' '<<res[i];
		}
		cout<<"\n";
	}
	return 0;
}
