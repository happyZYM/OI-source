#include<cstdio>
using namespace std;
bool isr(int n)
{
	if(n%400==0) return 1;
	if(n%100==0) return 0;
	if(n%4==0) return 1;
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%c\n",isr(n)?'Y':'N');
	return 0;
}

