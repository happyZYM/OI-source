#include<cstdio> 
using namespace std;
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	swap(a,b);
	printf("%d %d\n",a,b);
	return 0;
}

