#include<cstdio>
int n;
bool isp(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return n>1;
}
int main()
{
	scanf("%d",&n);
	printf("%s\n",isp(n)?"Yes":"No");
	return 0;
}
