#include<cstdio>
#include<cstring>
int main()
{
	char s[110];
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++) printf("%c",s[i]+s[(i+1)%len]);
	printf("\n");
	return 0;
}
