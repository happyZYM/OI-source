#include<cstdio>
int n,res,last,x;
int main()
{
	scanf("%d%d",&n,&last);
	res=last;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>last) res+=x-last;
		last=x;
	}
	printf("%d\n",res);
	return 0;
}
