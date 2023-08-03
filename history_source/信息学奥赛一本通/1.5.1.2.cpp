#include<cstdio>
using namespace std;
int main()
{
	int h[10];
	for(int i=0;i<10;i++) scanf("%d",h+i);
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=0;i<10;i++) if(h[i]<=n+30) ans++;
	printf("%d\n",ans);
	return 0;
}

