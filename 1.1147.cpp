#include<cstdio>
int l,r,sum,M;
int main()
{
	scanf("%d",&M);
	l=r=sum=1;
	while(r<M)
	{
		while(sum+r+1<=M) sum+=++r;
		if(sum==M) printf("%d %d\n",l,r);
		sum-=l++;
		if(l>r) r=sum=l;
	}
	return 0;
}
