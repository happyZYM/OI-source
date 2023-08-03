#include<cstdio>
int main()
{
	int n,k;
	scanf("%d",&k);
	double cnt=0;
	n=1;
	while(1)
	{
		cnt+=1.0/n;
		if(cnt>k) break;
		n++;
	}
	printf("%d\n",n);
	return 0;
}
