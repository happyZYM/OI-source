#include<cstdio>
using namespace std;
int main()
{
	int num[101]={0};
	int x;
	for(int i=0;i<10;i++)
	{
		scanf("%d",&x);
		num[x]++;
	}
	for(int i=99;i>=1;i-=2)
	{
		while(num[i])
		{
			printf("%d ",i);
			num[i]--;
		}
	}
	for(int i=0;i<=100;i+=2)
	{
		while(num[i])
		{
			printf("%d ",i);
			num[i]--;
		}
	}
	printf("\n");
	return 0;
}

