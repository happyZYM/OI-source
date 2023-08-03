#include<cstdio>
using namespace std;
bool isp(int n)
{
	if(n==2) return 1;
	if(n<=1) return 0;
	if(!n&1) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main()
{
	for(int i=1;i<=9;i++)
		for(int j=0;j<=9;j++)
			if(isp(i*100+j*10+i))
				printf("%d\n",i*100+j*10+i);
	return 0;
}

