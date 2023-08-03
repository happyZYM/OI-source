#include<cstdio>
inline bool isp(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return false;
	return n>=2;
}
int n,k,res;
int x[25];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	for(int i=0;i<(1<<n);i++)
		if(__builtin_popcount(i)==k)
		{
			int s=0;
			for(int j=0;j<n;j++) if(i&(1<<j)) s+=x[j];
			if(isp(s)) res++;
		}
	printf("%d\n",res);
	return 0;
}
