#include<cstdio>
#include<vector>
using namespace std;
int answer(int n)
{
	if(n<1) return 0;
	if(n==1) return 1;
	if(n==2) return 2;
	if(n==3) return 4;
	int a,b,c,d;
	a=1;
	b=2;
	c=4;
	d=0;
	for(int i=4;i<=n;i++)
	{
		d=a+b+c;
		a=b;
		b=c;
		c=d;
	}
	return d;
}
int main()
{
	vector<int>ans;
	int x;
	while(scanf("%d",&x),x!=0) ans.push_back(answer(x));
	for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
	return 0;
}
