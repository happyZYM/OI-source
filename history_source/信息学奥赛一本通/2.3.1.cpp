#include<cstdio>
using namespace std;
int answer(int n)
{
	int a,b,c;
	c=a=b=1;
	for(int i=3;i<=n;i++)
	{
		c=(a+b)%1000;
		a=b;
		b=c;
	}
	return c;
}
int main()
{
	int n;
	scanf("%d",&n);
	int sr[n];
	for(int i=0;i<n;i++) scanf("%d",sr+i);
	for(int i=0;i<n;i++) printf("%d\n",answer(sr[i]));
	return 0;
}
