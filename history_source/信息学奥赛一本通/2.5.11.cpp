#include<cstdio>
int put(int m,int n,int x)
{
	if(n==1) return 1;
	int ans=0;
	for(int i=x;i*n<=m;i++) ans+=put(m-i,n-1,i);
	return ans;
} 
int main()
{
	int t;
	scanf("%d",&t);
	int ans[t];
	int m,n;
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&m,&n);
		ans[i]=put(m,n,0);
	}
	for(int i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}

