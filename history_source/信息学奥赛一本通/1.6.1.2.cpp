#include<cstdio>
using namespace std;
int sum(int letter)
{
	int ans=letter/70;
	if(letter%70!=0) ans++;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	int add=0,x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		add+=sum(x); 
	}
	printf("%.1lf\n",(double)add/10.0);
	return 0;
}

