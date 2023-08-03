#include<cstdio>
using namespace std;
int main()
{
	int n,j=0,y=0,t=0,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		j+=x;
		scanf("%d",&x);
		y+=x;
		scanf("%d",&x);
		t+=x;
	}
	printf("%d %d %d %d\n",j,y,t,j+y+t);
	return 0;
}

