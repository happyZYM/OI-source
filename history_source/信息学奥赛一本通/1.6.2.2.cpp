#include<cstdio>
using namespace std;
short digit(int n,int k)
{
	for(int i=1;i<k;i++) n/=10;
	return n%10;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",digit(n,k));
	return 0;
}

