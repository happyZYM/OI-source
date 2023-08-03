#include<cstdio>
using namespace std;
void xiao(char *x)
{
	if(*x>='A'&&*x<='Z') *x+=32;
}
char turn(char key,char w)
{
	xiao(&key);
	int x=key-'a';
	if(w>='A'&&w<='Z')
	{
		int m=w-'A';
		m-=x;
		m+=26;
		m=m%26;
		return char('A'+m);
	}
	if(w>='a'&&w<='z')
	{
		int m=w-'a';
		m-=x;
		m+=26;
		m=m%26;
		return char('a'+m);
	}
}
int main()
{
	char k[110],m[1000],x;
	int lenK=0,lenM=0;
	while(x=getchar(),x!='\n') k[lenK++]=x;
	while(x=getchar(),x!='\n') m[lenM++]=x;
	char c[lenM];
	for(int i=0;i<lenM;i++)
		c[i]=turn(k[i%lenK],m[i]);
	for(int i=0;i<lenM;i++)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}

