#include<cstdio>
#include<cstring>
char s[105];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%s", s)==1)
	{
		int a=0,b=0,n=strlen(s);
		for(int i=0;i<n;i++)
			if(s[i]=='0')
			{
				b++;
				if(s[(i+1)%n]=='0') a++;
			}
		if(a*n==b*b) printf("EQUAL\n");
		else if(a*n>b*b) printf("SHOOT\n");
		else printf("ROTATE\n");
	}
	return 0;
}
