#include<cstdio>
int n,stk[50],top;
int main()
{
	scanf("%d",&n);
	while(n) stk[top++]=(n+1)>>1,n>>=1;
	printf("%d\n",top);
	while(top) printf("%d ",stk[--top]);
	printf("\n");
	return 0;
}
