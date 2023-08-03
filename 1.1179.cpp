#include<cstdio>
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int L,R,res=0; scanf("%d%d",&L,&R);
	for(int i=L;i<=R;i++)
	{
		int x=i;
		while(x)
		{
			if(x%10==2) res++;
			x/=10;
		}
	}
	printf("%d\n",res);
	return 0;
}
