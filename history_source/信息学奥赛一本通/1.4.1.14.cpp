#include<cstdio>
using namespace std;
struct L
{
	double a,b,x;
};
int main()
{
	int n;
	scanf("%d",&n);
	L J;
	L G[n-1];
	scanf("%lf%lf",&J.a,&J.b);
	J.x=J.b/J.a;
	for(int i=0;i<n-1;i++)
	{
		scanf("%lf%lf",&G[i].a,&G[i].b);
		G[i].x=G[i].b/G[i].a;
	}
	for(int i=0;i<n-1;i++)
	{
		if(G[i].x-J.x>0.05) printf("better\n");
		else if(J.x-G[i].x>0.05) printf("worse\n");
		else printf("same\n");
	}
	return 0;
}
