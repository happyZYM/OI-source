#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,a[110][110],num;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		a[i][num%k]=num;
		for(int j=0;j<k;j++)
		{
			if(a[i-1][j])
				a[i][(j+num)%k]=a[i-1][j]+num;//È¡ 
			a[i][j]=max(a[i][j],a[i-1][j]);//²»È¡ 
		}
	}
	printf("%d\n",a[n][0]);
	return 0;
}
