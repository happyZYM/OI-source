#include<cstdio>
using namespace std;
bool isp[1010];
int size(int n)
{
	int ans=0;
	do
	{
		ans++;
		n/=10;
	}
	while(n);
	return ans;
}
bool ish(int n)
{
	char s[size(n)];
	for(int i=size(n)-1;i>=0;i--)
	{
		s[i]=char('0'+n%10);
		n/=10;
	}
	for(int i=0,j=sizeof(s)-1;i<j;i++,j--)
		if(s[i]!=s[j]) return 0;
	return 1;
}
int main()
{
	for(int i=2;i<1010;i++) isp[i]=1;
	for(int i=2;i<1010;i++)
		for(int j=2;j*i<1010;j++)
			isp[j*i]=0;
	int ans=0;
	int n;
	scanf("%d",&n);
	for(int i=11;i<=n;i++)
		if(ish(i)&&isp[i]) ans++;
	printf("%d\n",ans);
	return 0;
}

