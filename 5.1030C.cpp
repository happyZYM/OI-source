#include<cstdio>
int n;
char s[105];
bool check(int val)
{
	int sum=0,cnt=0;;
	for(int i=0;i<n;i++)
	{
		if(sum+s[i]<=val)
		{
			sum+=s[i];
			if(sum==val) sum=0,cnt++;
		}
		else return false;
	}
	return sum==0&&cnt>=2;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%s",&n,s);
	for(int i=0;i<n;i++) s[i]-='0';
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=s[i];
		if(check(sum))
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
