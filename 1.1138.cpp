#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10005;
int n,k,a[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=-1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]) k--;
		if(!k) { printf("%d\n",a[i]); return 0; }
	}
	puts("NO RESULT");
	return 0;
}
