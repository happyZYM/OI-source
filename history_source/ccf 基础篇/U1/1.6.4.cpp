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
	int t;
	scanf("%d",&t);
	int a,b,ans[t];
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&a,&b);
		ans[i]=answer(a,b,0);
	}
	for(int i=0;i<t;i++) printf("%d\n",ans[i]);
	return 0;
}
