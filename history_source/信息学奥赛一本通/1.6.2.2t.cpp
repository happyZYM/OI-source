#include<cstdio>
using namespace std;
long long f(int n)
{
	if(n==1) return 0;
	if(n==2) return 1;
	return f(n-2)+f(n-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",f(n));
	return 0;
}

