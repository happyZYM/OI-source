#include<cstdio>
using namespace std;
int main()
{
	char s[1200],w;
	int len=0,add=0,num;
	while(w=getchar(),w!='\n') s[len++]=w;
	num=s[0]-'0';
	add=1;
	for(int i=1;i<len;i++)
	{
		if(s[i]-'0'==num) add++;
		else
		{
			printf("%d%d",add,num);
			add=1;
			num=s[i]-'0';
		}
	}
	printf("%d%d\n",add,num);
	return 0;
}

