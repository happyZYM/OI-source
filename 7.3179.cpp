#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int maxn=505;
int N,C,x[maxn],y[maxn],tx[maxn],ty[maxn],lx,ly;
int a[maxn][maxn],s[maxn][maxn];
inline int sum(int xx,int yy,int len)
{
	int ax=tx[xx-1],ay=ty[yy-1];
	int ox=upper_bound(tx,tx+lx,ax+len-1)-1-tx+1,oy=upper_bound(ty,ty+ly,ay+len-1)-1-ty+1;
	assert(ox>=xx&&oy>=yy);
	return s[ox][oy]-s[ox][yy-1]-s[xx-1][oy]+s[xx-1][yy-1];
}
inline bool ok(int len)
{
	for(int i=1;i<=lx;i++) for(int j=1;j<=ly;j++)
		if(sum(i,j,len)>=C) return true;
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&C,&N);
	for(int i=0;i<N;i++) scanf("%d %d",&x[i],&y[i]);
	memcpy(tx,x,sizeof(tx)); memcpy(ty,y,sizeof(ty));
	sort(tx,tx+N); lx=unique(tx,tx+N)-tx;
	sort(ty,ty+N); ly=unique(ty,ty+N)-ty;
	for(int i=0;i<N;i++) a[lower_bound(tx,tx+lx,x[i])-tx+1][lower_bound(ty,ty+ly,y[i])-ty+1]++;
	for(int i=1;i<=lx;i++) for(int j=1;j<=ly;j++) s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
	int L=1,R=10000,M,res=10000;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(ok(M)) res=M,R=M-1;
		else L=M+1;
	}
	printf("%d\n",res);
	return 0;
}
