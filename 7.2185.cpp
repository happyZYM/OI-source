#include<cstdio>
#include<algorithm>
using namespace std;
int R,C;
char a[10005][80],buf[10005];
inline int gcd(int a,int b) { return b?gcd(b,a%b):a; }
inline int lcm(int a,int b) { return a/gcd(a,b)*b; }
inline int Get(char *s,int n)
{
	static int nxt[10005];
	nxt[1]=0;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
	return n-nxt[n];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&R,&C);
	int clen=1,rlen=1;
	for(int i=0;i<R;i++) scanf("%s",a[i]);
	for(int i=0;i<R;i++)
	{
		clen=lcm(clen,Get(a[i]-1,C));
		if(clen>=C) { clen=C; break; }
	}
	for(int i=0;i<C;i++)
	{
		for(int j=0;j<R;j++) buf[j]=a[j][i];
		rlen=lcm(rlen,Get(buf-1,R));
		if(rlen>=R) { rlen=R; break; }
	}
	printf("%d\n",rlen*clen);
	return 0;
}
