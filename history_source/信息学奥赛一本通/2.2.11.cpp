#include<cstdio>
using namespace std;
int main()
{
	int t[110]={0};
	int n;
	scanf("%d",&n);
	double f=n/2.0;
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		t[x+50]++;
	}
	for(int i=0;i<110;i++)
	{
		if(t[i]>f)
		{
			printf("%d\n",i-50);
			return 0;
		}
	}
	printf("no\n");
	return 0;
}

