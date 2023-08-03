#include<cstdio>
using namespace std;
int f(int n,int k)
{
	if(n>1) return (k-1)*f(n-1,2)+f(n-1,3);
	return k;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n,3));
	return 0;
}
