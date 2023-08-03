#include<cstdio>
using namespace std;
void read()
{
	char a=getchar();
	if(a=='!') return;
	read();
	printf("%c",a);
}
int main()
{
	read();
	printf("\n");
	return 0;
}

