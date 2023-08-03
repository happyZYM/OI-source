#include<cstdio>
int os(int n)
{
	static int ans;
	ans=0;
	while(n>0)
	{
		if(n&1) ans++;
		n/=2;
	}
	return ans;
}
int main()
{
	int a,b;
	while(scanf("%d",&a),a!=0)
	{
		b=a+1;
		while(os(a)!=os(b)) b++;
		printf("%d\n",b);
	}
	return 0;
}
