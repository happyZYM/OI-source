#include<cstdio>
#include<cassert>
using namespace std;
const int maxn=1000010;
char p[maxn];
int f[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int n,kase=0;
	while(scanf("%d",&n)==1&&n)
	{
		scanf("%s",p);
		for(int i=1;i<n;i++)
		{
			int j=f[i];
			while(j&&p[i]!=p[j]) j=f[j];
			f[i+1]=(p[i]==p[j]?j+1:0);
		}
		printf("Test case #%d\n",++kase);
		for(int i=2;i<=n;i++)
			if(f[i]>0&&i%(i-f[i])==0)
				printf("%d %d\n",i,i/(i-f[i]));
		printf("\n");
	}
	return 0;
}
