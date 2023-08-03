#include<cstdio>
int main()
{
	char stack[260]={'s','\0'},li;
	int top=1;
	while(li=getchar(),li!='\n')
	{
		switch(li)
		{
			case '(':stack[top++]=li;break;
			case ')':
				if(stack[top-1]=='(') top--;
				else
				{
					printf("Wrong\n");
					return 0;
				}
				break;
			case '[':stack[top++]=li;break;
			case ']':
				if(stack[top-1]=='[') top--;
				else
				{
					printf("Wrong\n");
					return 0;
				}
		}
	}
	if(top==1) printf("OK\n");
	else printf("Wrong\n");
	return 0;
}
