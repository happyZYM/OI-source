#include<cstdio>
int main()
{
	int a[2001]={6},n,c[]={6,2,5,5,4,5,6,3,7,6},s=0;
	scanf("%d",&n);
	for(int i=1;i<=2000;i++)
	{
		int j=i;
		while(j>0)
		{
			a[i]+=c[j%10];
			j/=10;
		}
	}
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
			if(a[i]+a[j]+a[i+j]+4==n) s++;
	}
	printf("%d",s);
	return 0;
}
