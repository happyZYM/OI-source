#include<cstdio>
using namespace std;
int answer(int a,int b,int x)
{
	if(b==1) return 1;
	int ans=0;
	for(int i=x;i*b<=a;i++) ans+=answer(a-i,b-1,i);
	return ans;
}
int main()
{
	int n,a,b;
	scanf("%d",&n);
	int ans[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		ans[i]=answer(a,b,0);
	}
	for(int i=0;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}
