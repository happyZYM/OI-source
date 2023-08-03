#include<cstdio>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	n-=y/x;
	if(y%x!=0) n--;
	if(n<0) n=0;
	printf("%d\n",n); 
	return 0;
}
