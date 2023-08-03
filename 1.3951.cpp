#include<cstdio>
#include<algorithm>
using namespace std;
long long a,b;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",a*b-a-b);
	return 0;
}
