#include<cstdio>
inline int abs(int a){return a<0?-a:a;}
int k,n,a[10003][150],x,i,j;
int main()
{
	scanf("%d%d%d",&n,&k,&x);
	x%=k;
	a[1][x]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&x);
		x%=k;
		for(j=0;j<k;j++)
			if(a[i-1][j])
			{
				a[i][abs(j+x)%k]=1;
				a[i][abs(j-x)%k]=1;
			}
	}
	if(a[n][0]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
