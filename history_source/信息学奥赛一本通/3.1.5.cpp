#include<cstdio>
int top=0,n,*sr,*stack;
void check()
{
	int *p=sr;
	for(int i=1;i<=n;i++)
	{
		if(*p==i)
		{
			p++;
			while(top>0&&stack[top-1]==*p) p++,top--;
			continue;
		}
		else stack[top++]=i;
	}
	while(top>0&&stack[top-1]==*p) p++,top--;
	if(top==0) printf("YES\n");
	else printf("NO\n");
}
int main()
{
	scanf("%d",&n);
	sr=new int[n];
	stack=new int[n+5];
	for(int i=0;i<n;i++) scanf("%d",sr+i);
	check();
	return 0;
}
