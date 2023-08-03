#include<cstdio>
using namespace std;
int answer(int n)
{
	int a,b,c;
	a=1;
	b=2;
	c=0;
	if(n==1) return 1;
	if(n==2) return 2;
	for(int i=3;i<=n;i++)
	{
		c=(a+2*b)%32767;
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
