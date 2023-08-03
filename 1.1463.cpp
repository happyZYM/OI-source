#include<cstdio>
typedef long long LL;
inline int K(int x)
{
	int k=0; for(;(1<<k)<=x;++k);
	return k;
}
LL n,res,mxgs;
const int p[16]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int limit_p[16],p1;
void dfs(LL i,LL gs,LL num,LL mxq)
{
	if(num>n) return;
	if(i>1) limit_p[i]=p1/(K(p[i])-1)+1;//ceil((p1+1)/(K(p[i])-1))
	LL val=num*p[i],q=1,ngs=gs;
	while(q<limit_p[i]&&q<=mxq&&val<=n)
	{
		ngs=gs*(q+1);
		if(ngs>mxgs) mxgs=ngs,res=val;
		if(ngs==mxgs&&val<res) res=val;
		if(i==1) p1=q;
		dfs(i+1,ngs,val,q);
		val*=p[i],++q;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld",&n);
	if(n==1) { printf("1\n"); return 0; }
	
	res=mxgs=1;
	LL x=1,t=0;
	for(int i=1;i<16&&x<=n;++i) x*=p[i],t=i;
	t=K(p[t])*2-1;
	limit_p[1]=t;
	
	dfs(1,1,1,20);
	
	printf("%lld\n",res);
	return 0;
}
