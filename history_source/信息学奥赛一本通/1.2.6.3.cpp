#include<cstdio>
using namespace std;
int num(char a,char b,char c)
{
	return (a-'0')*100+(b-'0')*10+c-'0';
}
int main()
{
	char a,b,c;
	scanf("%c%c%c",&a,&b,&c);
	printf("%d\n",num(c,b,a));
	return 0;
}

