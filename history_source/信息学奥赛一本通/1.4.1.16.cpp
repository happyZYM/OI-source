#include<cstdio>
using namespace std;
int main()
{
	int y[12];
	for(int i=0;i<12;i++) scanf("%d",y+i);
	int add=0,c=0;
	for(int i=0;i<12;i++)
	{
		add+=300;
		add-=y[i];
		if(add<0)
		{
			printf("-%d\n",i+1);
			return 0;
		}
		c+=add/100;
		add=add%100;
	}
	printf("%d\n",c*120+add);
	return 0;
}

