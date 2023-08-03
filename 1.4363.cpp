#include<cstdio>
#include<map>
using namespace std;
#define For(i,a,b) for(int i=a;i<=b;i++)
typedef long long ST;
const int maxn=15,base=12;
const int oo=1e9+7;
map<ST,int> mp;
int n,m,a[maxn][maxn],b[maxn][maxn];
int lbp[maxn];
inline ST zip()
{
	ST res=0;
	For(i,1,n) res=res*base+lbp[i];
	return res;
}
inline void unzip(ST t) { for(int i=n;i>=1;i--) lbp[i]=t%base,t/=base; }
inline int getnxt()
{
	int res=0;
	For(i,1,n) res+=lbp[i];
	return res&1;
}
//inline int dfs(ST st,int player,int alpha,int beta)
//{
//	if(mp.count(st)) return mp[st];
//	unzip(st);
//	alpha=-oo; beta=oo;
//	For(i,1,n)
//		if(lbp[i-1]>lbp[i])
//		{
//			++lbp[i];
//			ST h=zip();
//			if(!player) alpha=max(alpha,dfs(h,player^1,alpha,beta)+a[i][lbp[i]]);
//			else beta=min(beta,dfs(h,player^1,alpha,beta)-b[i][lbp[i]]);
//			--lbp[i];
//			if(beta<=alpha) break;
//		}
//	return mp[st]=(!player)?alpha:beta;
//}
int dfs(ST st,int player)
{
	if(mp.count(st)) return mp[st];
	unzip(st);
	int res=(!player)?-oo:oo;
	For(i,1,n)
		if(lbp[i-1]>lbp[i])
		{
			++lbp[i];
			ST nt=zip();
			if(!player) res=max(res,dfs(nt,player^1)+a[i][lbp[i]]);
			else res=min(res,dfs(nt,player^1)-b[i][lbp[i]]);
			--lbp[i];
		}
	return mp[st]=res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
	scanf("%d%d",&n,&m); lbp[0]=m;
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,1,m) scanf("%d",&b[i][j]);
	For(i,1,n) lbp[i]=m;
	ST full=zip(); mp[full]=0;
//	printf("%d\n",dfs(0,0,-oo,+oo));
	printf("%d\n",dfs(0,0));
	return 0;
}
/*
2 3
4 2 2 
1 5 3 
1 5 3 
4 3 3 
*/
