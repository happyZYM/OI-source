#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int R,C,f[205][205];
int SG(int R,int C)
{
	if(R>C) swap(R,C);
	if(f[R][C]>-1) return f[R][C];
	bool cnt[205]={0};
	for(int i=2;i<=R-i;i++) cnt[SG(i,C)^SG(R-i,C)]=1;
	for(int i=2;i<=C-i;i++) cnt[SG(R,i)^SG(R,C-i)]=1;
	int &t=f[R][C]; t=0;
	while(cnt[t]) t++;
	return t;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	memset(f,-1,sizeof(f));
	f[2][3]=f[3][2]=f[2][2]=0; for(int i=1;i<205;i++) f[i][1]=f[1][i]=0;
	while(scanf("%d%d",&R,&C)==2) puts(SG(R,C)?"WIN":"LOSE");
	return 0;
}
