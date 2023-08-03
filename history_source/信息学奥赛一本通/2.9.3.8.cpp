#include<cstdio>
int f(int n,int k,int minn)
{
	if(k==1) return 1;
	int ans=0;
	for(int i=minn;i*k<=n;i++) ans+=f(n-i,k-1,i);
	return ans;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d\n",f(n,k,1));
	return 0;
}
