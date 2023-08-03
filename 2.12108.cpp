#include<cstdio>
#include<cstring>
const int mod=1333331;
int A[150],B[150],c[150],T[150];
bool e[mod];
int n,w,x,kase,t;
inline int hsh()
{
	int y=0;
	for(int i=1;i<=n;i++)
		y=(y*10+(c[i]+t)%T[i])%mod;
	return y;
}
inline int awake()
{
	int y=0;
	for(int i=1;i<=n;i++)
		y+=(c[i]+t)%T[i]<A[i];
	return y;
}
inline void check()
{
	for(int i=1;i<=n;i++)
		if((c[i]+t)%T[i]==A[i]&&w>=n-w)
			c[i]=-t;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&A[i],&B[i],&c[i]);
			c[i]--;
			T[i]=A[i]+B[i];
		}
		memset(e,0,sizeof(e));
		t=0;
		x=hsh();
		while(!e[x])
		{
			e[x]=1;
			w=awake();
			if(w==n) break;
			t++;
			check();
			x=hsh();
		}
		printf("Case %d: ",++kase);
		if(w==n) printf("%d\n",t+1);
		else printf("%d\n",-1);
	}
	return 0;
}
