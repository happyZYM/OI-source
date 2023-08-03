#include<cstdio>
using namespace std;
char num[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
void zhuan(int n,int m)
{
	if(n==0) return;
	zhuan(n/m,m);
	printf("%c",num[n%m]);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	zhuan(n,m);
	if(n==0) printf("0");
	printf("\n");
	return 0;
}

