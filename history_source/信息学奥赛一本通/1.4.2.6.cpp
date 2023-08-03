#include<cstdio>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(n%19!=0) printf("NO\n");
	else
	{
		int add=0;
		do
		{
			if(n%10==3) add++;
			n/=10;
		}
		while(n);
		if(add==k) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

