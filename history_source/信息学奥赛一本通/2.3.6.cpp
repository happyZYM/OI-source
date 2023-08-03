#include<cstdio> 
int main()
{
	int n;
	scanf("%d",&n);
	if(n<=2){
		printf("%d\n",n);
		return 0;
	}
	int a=1,b=2,c;
	for(int i=3;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	printf("%d\n",c);
	return 0;
}

