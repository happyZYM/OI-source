#include<cstdio>
using namespace std;
int run_(int a,int b,char c)
{
	switch(c)
	{
		case '+':return a+b;
		case '-':return a-b;
		case '*':return a*b;
		case '/':return a/b;
		case '%':return a%b;
	}
}
bool can(char a)
{
	if(a=='+') return 0;
	if(a=='-') return 0;
	if(a=='*') return 0;
	if(a=='/') return 0;
	if(a=='%') return 0;
	return 1;
}
int main()
{
	int a=0,b=0;
	char f;
	while(f=getchar(),f>='0'&&f<='9') a=a*10+(f-'0');
	while(can(f)) f=getchar();
	char w=' ';
	while(w==' ') w=getchar();
	b=w-'0';
	while(w=getchar(),w!='\n') b=b*10+w-'0';
	printf("%d\n",run_(a,b,f)); 
	return 0;
}

