#include<cstdio>
int main()
{
	char stack[25]={'s','\0'},li;
	int top=1;
	while(li=getchar(),li!='@')
	{
		if(li=='(') stack[top++]=li;
		if(li==')')
		{
			if(stack[top-1]=='(') top--;
			else
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	if(top==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
