#include<cstdio>
char s[1050];
void dfs(int L,int R)
{
	if(L<R) dfs(L,(L+R)/2),dfs((L+R+1)/2,R);
	int B=1,I=1;
	for(int i=0;i<=R-L;i++)
		if(s[L+i]=='1') B=false;
		else if(s[L+i]=='0') I=false;
	if(B) putchar('B');
	else if(I) putchar('I');
	else putchar('F');
}
int main()
{
	int n;
	scanf("%d%s",&n,s);
	dfs(0,(1<<n)-1);
	return 0;
}
