#include<cstdio>
int n,now,cnt,x;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	while(n-->0)
	{
		scanf("%d",&x);
		if(now==x) cnt++;
		if(cnt==0) now=x,cnt=1;
		if(now!=x) cnt--;
	}
	printf("%d\n",now);
	return 0;
}
