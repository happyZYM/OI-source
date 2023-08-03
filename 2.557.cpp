#include <stdio.h>
#include <string.h>
const int N = 50005;
double p[N];
void init()
{
	p[1]=1;
	for(int i=1;i<50000;i++)
		p[i+1]=p[i]*(2*i-1)/(2*i);
}
int main()
{
	init();
	int cas,n;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d",&n);
		printf("%.4lf\n",1-p[n/2]);
	}
	return 0;
}
