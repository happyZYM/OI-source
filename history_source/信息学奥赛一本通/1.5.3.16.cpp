#include<cstdio>
#include<cstring>
int main()
{
	int len=0;
	char w,s[600],a[600];
	gets(a);
	int lenn=strlen(a);
	for(int i=0;i<lenn;i++)
	{
		w=a[i];
		if(w!=' ') s[len++]=w;
		else
		{
			for(int i=len-1;i>=0;i--) printf("%c",s[i]);
			printf(" ");
			len=0;
		}
	}
	for(int i=len-1;i>=0;i--)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}
