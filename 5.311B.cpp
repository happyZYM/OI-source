#include<cstdio>
struct char_reader
{
	FILE* f; char *buf,*p1,*p2; int size;
	char_reader(FILE* fin,int bufsize=1000000) { f=fin; size=bufsize; p1=p2=0; buf=new char[bufsize]; }
	inline int operator()() { return p1==p2&&(p2=(p1=buf)+fread(buf,1,size,f),p1==p2)?EOF:*p1++; }
};
struct char_writer
{
	FILE* f; char *buf,*p,*end;
	char_writer(FILE* fout,int bufsize=1000000) { f=fout; buf=new char[bufsize]; p=buf; end=buf+bufsize; }
	~char_writer() { fwrite(buf,p-buf,1,f); }
	inline char operator()(char ch) { return end==p&&(fwrite(buf,end-buf,1,f),p=buf),*p++=ch; }
};
char_reader gch(stdin);
char_writer wch(stdout);
template<typename T> inline void read(T& t)
{
	t=0; bool f=false; char ch;
	while(ch=gch(),!((ch>='0'&&ch<='9')||ch=='-'));
	if(ch=='-') f=true,ch=gch();
	t=ch-'0';
	while(ch=gch(),ch>='0'&&ch<='9') t=t*10+ch-'0';
	if(f) t=-t;
}
template<typename T> inline void write(T t)
{
	int stk[20],cnt=0;
	if(t==0) { wch('0'); return; }
	if(t<0) { wch('-'); t=-t; }
	while(t>0) { stk[cnt++]=t%10; t/=10; }
	while(cnt) wch(stk[--cnt]+'0');
}
inline void write(char t) { wch(t); }
inline void write(char *s) { while(*s) wch(*s++); }
#if __cplusplus >= 201103L
inline void write(const char *s) { write((char*)s); }
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
template<typename T,typename... Args> inline void write(T t,Args... args) { write(t); write(args...); }
#else
template<typename A_t,typename B_t> inline void read(A_t &a,B_t &b) { read(a); read(b); }
template<typename A_t,typename B_t,typename C_t> inline void read(A_t &a,B_t &b,C_t &c) { read(a); read(b); read(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline void read(A_t &a,B_t &b,C_t &c,D_t &d) { read(a); read(b); read(c); read(d); }
template<typename A_t,typename B_t> inline void write(A_t a,B_t b) { write(a); write(b); }
template<typename A_t,typename B_t,typename C_t> inline void write(A_t a,B_t b,C_t c) { write(a); write(b); write(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline void write(A_t a,B_t b,C_t c,D_t d) { write(a); write(b); write(c); write(d); }
#endif
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
const int maxp=105;
int n,m,p,q[maxn],l,r;
LL d[maxn],a[maxn],s[maxn],f[maxp][maxn],g[maxn];
#define F f[i&1]
#define G f[(i-1)&1]
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(n,m,p);
	for(int i=2;i<=n;i++) { read(d[i]); d[i]+=d[i-1]; }
	for(int i=1;i<=m;i++)
	{
		LL h,t; read(h,t);
		a[i]=t-d[h];
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++) s[i]=s[i-1]+a[i];
	memset(f,0x3f,sizeof(f)); f[0][0]=0;
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=m;j++) g[j]=f[i-1][j]+s[j];
		q[l=r=1]=0;
		for(int j=1;j<=m;j++)
		{
			while(l<r&&g[q[l+1]]-g[q[l]]<=a[j]*(q[l+1]-q[l])) l++;
			f[i][j]=min(f[i-1][j],g[q[l]]+a[j]*(j-q[l])-s[j]);
			if(g[j]>=0x3f3f3f3f3f3f3f3fll) continue;
			while(l<r&&(g[j]-g[q[r]])*(q[r]-q[r-1])<=(g[q[r]]-g[q[r-1]])*(j-q[r])) r--;
			q[++r]=j;
		}
	}
	write(f[p][m],'\n');
	return 0;
}