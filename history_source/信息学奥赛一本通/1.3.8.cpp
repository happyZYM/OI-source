#include<cstdio>
using namespace std;
int abs(int n)
{
	if(n<0) n=-n;
	return n;
}
int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	if(abs(x)<=1&&abs(y)<=1) printf("yes\n");
	else printf("no\n");
	return 0;
}

