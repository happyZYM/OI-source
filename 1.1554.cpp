#include<cstdio>
int cnt[10],a,b;
int main()
{
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		int x=i;
		while(x) ++cnt[x%10],x/=10;
	}
	for(int i=0;i<10;i++) printf("%d ",cnt[i]); puts("");
	return 0;
}
