#include<cstdio>
using namespace std;
int main()
{
	char s[1000],*p;
	p=s;
	while(*p=getchar(),*p!='\n') p++;
	p--;
	while(p>=s)
	{
		printf("%c",*p);
		p--;
	}
	printf("\n");
	return 0;
}
