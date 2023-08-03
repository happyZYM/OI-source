#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[15];
long long ans=1LL<<62;
void test(int pos)
{
	vector<int> b;
	b.reserve(a[0]-2);
	long long v1=a[pos],v2=a[pos+1];
}
void solve()
{
	a[0]=0;
	while(a[a[0]+1]=getchar()-'0',a[a[0]+1]!='\n'-'0')
		if(a[a[0]+1]>=0&&a[a[0]+1]<=9) a[0]++;
	sort(a+1,a+a[0]+1);
	int m=100;
	for(int i=1;i<a[0];i++)
		m=min(m,a[i+1]-a[i]);
	if(a[0]%2==0)
	{
		for(int i=1;i<a[0];i++)
			if(a[i+1]-a[i]==m) test(i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n-->0) solve();
	return 0;
}
