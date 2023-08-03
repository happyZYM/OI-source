#include<cstdio>
#include<cstring>
char turn(char n)
{
	if((n>='a'&&n<='y')||(n>='A'&&n<='Y')) return n+1;
	if(n=='Z'||n=='z') return n-25;
	return n;
}
int main()
{
	char a[85];
	gets(a);
	int len=strlen(a);
	for(int i=0;i<len;i++) printf("%c",turn(a[i]));
	printf("\n");
	return 0;
}
