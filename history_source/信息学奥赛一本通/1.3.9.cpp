#include<cstdio>
using namespace std;
int main()
{
	int a,b;
	char f;
	scanf("%d%c%d",&a,&f,&b);
	switch(f)
	{
		case '+':printf("%d\n",a+b);break;
		case '-':printf("%d\n",a-b);break;
		case '*':printf("%d\n",a*b);break;
		case '/':
			if(b==0) printf("Divided by zero!\n");
			else printf("%d\n",a/b);
			break;
		default:printf("Invalid operator!\n");j
	}
	return 0;
}

