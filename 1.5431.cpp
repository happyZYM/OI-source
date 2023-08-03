#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long LL;
struct char_reader
{
	FILE* f;
	char *buf,*p1,*p2;
	int size;
	char_reader(FILE* fin,int bufsize=100000)
	{
		assert(bufsize>0);
		f=fin;
		size=bufsize;
		p1=p2=0;
		buf=new char[bufsize];
	}
	inline int operator()()
	{
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,size,f),p1==p2)?EOF:*p1++;
	}
};
char_reader gch(stdin);
inline void read(LL& t)
{
	t=0; bool f=false; char ch;
	while(ch=gch(),!((ch>='0'&&ch<='9')||ch=='-'));
	if(ch=='-') f=true,ch=gch();
	t=ch-'0';
	while(ch=gch(),ch>='0'&&ch<='9') t=t*10+ch-'0';
	if(f) t=-t;
}
const int maxn=5e6+5;
LL n,p,k,a[maxn],s[maxn];
LL ksm(LL a,LL b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p) b&1?res=res*a%p:0;
	return res;
}
int main()
{
#ifdef local
	// freopen("pro.in","r",stdin);
	freopen("testdata.in","r",stdin);
#endif
	read(n); read(p); read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	s[0]=1;
	for(int i=1;i<=n;i++) s[i]=s[i-1]*a[i]%p;
	s[n]=ksm(s[n],p-2);
	LL res,d=ksm(k,p-2);
	k=ksm(k,n);
	res=k*ksm(a[n],p-2)%p;
	for(int i=n-1;i>=1;i--)
	{
		s[i]=s[i+1]*a[i+1]%p;
		k=k*d%p;
		res=(res+k*s[i-1]%p*s[i]%p)%p;
	}
	printf("%lld\n",res);
	return 0;
}