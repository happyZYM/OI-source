#include<cstdio>
using namespace std;
int main()
{
	int g;
	bool s;
	scanf("%d%d",&g,&s);
	int ans=8;
	g-=1000;
	if(g>0) ans+=(g/500)*4;
	if(g%500!=0) ans+=4;
	if(s) ans+=5;
	printf("%d\n",ans);
	return 0;
}
