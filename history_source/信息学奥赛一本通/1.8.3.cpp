#include<cstdio>
using namespace std;
char* find(char *front,char *last,char n)
{
	while(front<last)
	{
		if(*front==n) return front;
		front++;
	}
	return NULL;
}
int main()
{
	char s[1000],n;
	int len=-1;
	while(s[++len]=getchar(),s[len]!='\n');
	n=getchar();
	char *p=find(s,s+len,n);
	if(p==NULL) printf("no\n");
	else printf("%d\n",p-s+1);
	return 0;
}

