#include<cstdio>
#include<cstring>
bool can(char n)
{
	if(n>='a'&&n<='z') return 1;
	if(n>='A'&&n<='Z') return 1;
	if(n>='0'&&n<='9') return 1;
	if(n=='_') return 1;
	return 0;
}
int main()
{
    char s[25];
    gets(s);
    int len=strlen(s);
    if(can(s[0]))
    {
    	if(s[0]>='0'&&s[0]<='9') goto error;
    	for(int i=1;i<len;i++)
    		if(!can(s[i])) goto error;
    	printf("yes\n");
    	return 0;
	}
	error:{printf("no\n");return 0;}
}
