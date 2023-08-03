#include<cstdio>
int main()
{
	int n,m;
	scanf("%d%d",&m,&n);
	int map[n];
	for(int i=0;i<n;i++) map[i]=1;
	for(int i=2;i<=m;i++)
		for(int j=1;j<n;j++) 
			map[j]+=map[j-1];
	printf("%d\n",map[n-1]);
	return 0;
}

