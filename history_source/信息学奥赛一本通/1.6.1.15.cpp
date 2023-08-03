#include<cstdio>
using namespace std;
int fan(int n)
{
	int ans=0;
	do
	{
		ans=ans*10+n%10;
		n/=10;
	}
	while(n);
	return ans;
}
bool isp(int n)
{
	if(n<=1) return 0;
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
int main()
{
	bool f=0;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		if(isp(i)&&isp(fan(i)))
		{
			if(f) printf(",");
			else f=1;
			printf("%d",i);
		}
	}
	if(!f) printf("No");
	printf("\n");
	return 0;
}

