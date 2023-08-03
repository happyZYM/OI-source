#include<cstdio>
using namespace std;
bool isp(int n)
{
	if(!n&1) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main()
{
	int ans=1;
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n;i++) ans+=isp(i);
	printf("%d\n",ans);
	return 0;
}

