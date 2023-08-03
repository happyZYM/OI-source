#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int L=1,R=2000000000,M,res=2000000000,n;
int main()
{
	scanf("%d",&n); n--;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(M*log10(M)>=(double)n) res=M,R=M-1;
		else L=M+1;
	}
	printf("%d\n",res);
	return 0;
}
