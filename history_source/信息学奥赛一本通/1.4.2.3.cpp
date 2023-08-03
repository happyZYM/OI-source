#include<cstdio>
using namespace std;
int main()
{
	double add=0;
	int ans=1,n;
	scanf("%d",&n);
	while(add<=n) add+=1.0/ans,ans++;
	printf("%d\n",ans-1);
	return 0;
}

