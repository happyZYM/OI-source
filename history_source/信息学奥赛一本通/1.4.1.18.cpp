#include<cstdio>
using namespace std;
int main()
{
	int n,a,b;
	scanf("%d",&n);
	bool ans[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		ans[i]=(a>=90&&a<=140&&b>=60&&b<=90);
	}
	int answer,max;
	answer=max=0;
	for(int i=0;i<n;i++)
	{
		if(ans[i]) max++;
		else
		{
			if(max>answer) answer=max;
			max=0;
		}
	}
	if(max>answer) answer=max;
	printf("%d\n",answer);
	return 0;
}
