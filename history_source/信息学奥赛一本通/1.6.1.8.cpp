#include<cstdio>
using namespace std;
/*
x¼Ò,×¡yºÅ;
x*(x+1)/2-2*y=n; 
2*y+n=x*(x+1)/2;
2*y=x*(x+1)/2-n;
y=(x*(x+1)/2-n)/2; 
*/
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;;i++)
	{
		if((i*(i+1)/2-n)%2==0)
		{
			int y=(i*(i+1)/2-n)/2;
			if(y>0&&y<=i)
			{
				printf("%d %d\n",y,i);
				return 0;
			}
		}
	}
	return 0;
}

