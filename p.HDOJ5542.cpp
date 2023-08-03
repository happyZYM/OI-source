//http://acm.hdu.edu.cn/showproblem.php?pid=5542
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
inline void write(const char *&s) { while(*s) wch(*s++); }
#if __cplusplus >= 201103L
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
template<typename T,typename... Args> inline void write(T t,Args... args) { write(t); write(args...); }
#else
template<typename A_t,typename B_t> inline void read(A_t &a,B_t &b) { read(a); read(b); }
template<typename A_t,typename B_t,typename C_t> inline void read(A_t &a,B_t &b,C_t &c) { read(a); read(b); read(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline void read(A_t &a,B_t &b,C_t &c,D_t &d) { read(a); read(b); read(c); read(d); }
template<typename A_t,typename B_t> inline void write(A_t a,B_t b) { write(a); write(b); }
template<typename A_t,typename B_t,typename C_t> inline void write(A_t a,B_t b,C_t c) { write(a); write(b); write(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline void write(A_t a,B_t b,C_t c,D_t d) { write(a); write(b); write(c); write(d); }
template<typename A_t,typename B_t,typename C_t,typename D_t,typename E_t> inline void write(A_t a,B_t b,C_t c,D_t d,E_t e) { write(a); write(b); write(c); write(d); write(e); }
#endif
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
const int mod=1e9+7;
const int oo=0x3f3f3f3f;
int T,n,m,a[1005],f[1005][1005],c[1005],b[1005],kase;
inline void add(int p,int v)
{
	assert(p);
	for(;p<=n;p+=(p&-p)) (c[p]+=v)%=mod;
}
inline int ask(int p)
{
	assert(p);
	int res=0;
	for(;p;p-=(p&-p)) (res+=c[p])%=mod;
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(T);
	while(T-->0)
	{
		read(n,m);
		for(int i=1;i<=n;i++) { read(a[i]); b[i]=a[i]; }
		sort(b+1,b+1+n);
		for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+n,a[i])-b+1;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i=1;i<=m;i++)
		{
			memset(c,0,sizeof(c));
			add(1,f[i-1][0]);
			for(int j=1;j<=n;j++)
			{
				f[i][j]=ask(a[j]-1);
				add(a[j],f[i-1][j]);
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) res=(res+f[m][i])%mod;
		write("Case #",++kase,": ",res,'\n');
	}
	return 0;
}