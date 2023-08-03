#include<cstdio> 
using namespace std;
int main()
{
	int x=1,y=1,n;
	scanf("%d",&n);
	bool f=1;
	for(int i=1;i<n;i++)
	{
		if(f)
		{
			if(y>1) y--,x++;
			else
			{
				f=0;
				x++;
			}
		}
		else
		{
			if(x>1) x--,y++;
			else
			{
				f=1;
				y++;
			}
		}
	}
	printf("%d/%d\n",y,x);
	return 0;
}

