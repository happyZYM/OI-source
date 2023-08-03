#include<cstdio>
int main()
{
	int m,n;
	bool flag=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			n/=i;
			m=1;
			while(n%i==0) m++,n/=i;
			if(flag) printf("*");
			flag=1;
			if(m==1) printf("%d",i);
			else printf("%d^%d",i,m); 
		}
	}
	printf("\n");
	return 0;
}

