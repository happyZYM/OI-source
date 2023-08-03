#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxw=35;
LL L,R,a[maxw],tot,f[maxw][maxw*2+1],C[maxw][maxw],g[maxw][maxw*2+1];
LL cal(int R)
{
	if(R==0) return 1;
	LL res=0,delta=0;
	tot=0;
	while(R) { a[++tot]=R&1; R>>=1; }
	res=f[tot-1][maxw];
	for(int i=tot;i>=1;i--)
	{
		if(a[i]&&i!=tot) res+=g[i-1][delta-1+maxw];
		delta+=(a[i]?1:-1);
	}
	return res+f[0][delta+maxw];
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	for(int i=-maxw;i<=0;i++) f[0][i+maxw]=g[0][i+maxw]=1;
	C[1][0]=C[1][1]=1;
	for(int i=2;i<maxw;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(int i=1;i<maxw;i++)
		for(int j=-maxw;j<=maxw;j++)
		{
			if(j>i) continue; // 无解
			f[i][j+maxw]=f[i-1][j+maxw];
			for(int tot0=max((i+j+1)/2,0);tot0<=i;tot0++)
				f[i][j+maxw]+=C[i-1][tot0];
			for(int tot0=max((i+j+1)/2,0);tot0<=i;tot0++)
				g[i][j+maxw]+=C[i][tot0];
		}
	scanf("%lld%lld",&L,&R);
	printf("%lld\n",cal(R)-cal(L-1));
	return 0;
}