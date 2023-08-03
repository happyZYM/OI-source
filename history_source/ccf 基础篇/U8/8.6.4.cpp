#include<cstdio>
using namespace std;
int main()
{
	bool x;
	int t;
	int m;
	scanf("%d",&t);
	int sr[t];
	for(int i=0;i<t;i++) scanf("%d",sr+i);
	for(int i=0;i<t;i++)
	{
		x=0;
		for(int j=2;j<=sr[i];j++)
		{
			if(sr[i]%j==0)
			{
				if(x) printf("*");
			    m=0;
			    while(sr[i]%j==0)
			    {
			    	m++;
			    	sr[i]/=j;
				}
				printf("%d",j);
				if(m>1) printf("^%d",m);
				x=1;	
			} 
		}
		printf("\n");
	}
	return 0;
} 
