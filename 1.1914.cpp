#include<cstdio>
#include<cstring>
int n;
char s[60];
int main()
{
	scanf("%d%s",&n,s);
	int len=strlen(s);
	for(int i=0;i<len;i++) putchar((s[i]-'a'+n)%26+'a');
	return 0;
}
