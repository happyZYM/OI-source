#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p;
inline int gcd(int a,int b)
{
	int t;
	while(b) { t=b; b=a%b; a=t; }
	return a;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&p);
	double S=m*p*0.5,I=p+gcd(n,m)+gcd(abs(n-p),m);
//	printf("S=%lf I=%lf\n",S,I);
	printf("%d\n",int(S+1-I*0.5+0.5));
	return 0;
}
