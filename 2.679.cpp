#include<cstdio>
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int D,I,t;
	scanf("%d",&t);
	while(t-->0)
	{
		scanf("%d%d",&D,&I);
		int k=1;
		for(int i=0;i<D-1;i++)
			if(I&1){k=k<<1;I=(I+1)>>1;}
			else{k=(k<<1)+1;I>>=1;}
		printf("%d\n",k);
	}
	return 0;
}
