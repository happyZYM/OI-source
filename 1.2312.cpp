#include<cstdio>
#include<algorithm>
using namespace std;
const int p1=1217,p2=182375393;
const int maxn=105;
int n,m,a[maxn],b[maxn],cnt,res[1000000]; bool ok[p1];
inline char gc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline void read(int i)
{
	int ch,x=0,y=0,f=1;
	while(ch=gc(),ch<'0'||ch>'9') if(ch=='-') f=-1;
	x=y=ch-'0';
	while(ch=gc(),ch>='0'&&ch<='9') x=(x*10+ch-'0')%p1,y=(y*10+ch-'0')%p2;
	a[i]=(x*f%p1+p1)%p1; b[i]=(y*f%p2+p2)%p2;
}
bool check(int *a,int p,int v)
{
	long long val=0;
	for(int i=n;i>=0;i--) val=(val*v+a[i])%p;
	return val==0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) read(i);
	for(int i=0;i<p1;i++) ok[i]=check(a,p1,i);
	for(int i=1;i<=m;i++) if(ok[i%p1]&&check(b,p2,i)) res[cnt++]=i;
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++) printf("%d\n",res[i]);
	return 0;
}
