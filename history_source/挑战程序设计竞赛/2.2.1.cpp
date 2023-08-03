#include<cstdio>
const int V[6]={1,5,10,50,100,500};
int C[6],A;
inline int min(int a,int b){return a<b?a:b;}
void solve()
{
	int ans=0;
	for(int i=5;i>=0;i--)
	{
		int t=min(A/V[i],C[i]);
		A-=t*V[i];
		ans+=t;
	}
	printf("%d\n",ans);
}
void init()
{
	for(int i=0;i<6;i++) scanf("%d",C+i);
	scanf("%d",&A);
}
int main()
{
	init();
	solve();
	return 0;
}
