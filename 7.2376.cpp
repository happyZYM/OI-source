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
#endif
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=25005;
const int maxm=1000005;
const int oo=0x3f3f3f3f;
int n,m;
struct Node { int a,b; };
inline bool operator<(const Node &a,const Node &b) { return a.b<b.b; }
Node v[maxn];
int f[maxm<<2],pl,pr,val;
#define Lc (o<<1)
#define Rc (o<<1|1)
void build(int o,int L,int R)
{
	if(L==R) { f[o]=(L==0?0:oo); return; }
	int M=(L+R)>>1;
	build(Lc,L,M); build(Rc,M+1,R);
	f[o]=min(f[Lc],f[Rc]);
}
int query(int o,int L,int R)
{
	if(pl<=L&&R<=pr) return f[o];
	int M=(L+R)>>1,res=oo;
	if(pl<=M) res=min(res,query(Lc,L,M));
	if(pr>M) res=min(res,query(Rc,M+1,R));
	return res;
}
void update(int o,int L,int R)
{
	if(L==R) { f[o]=val; return; }
	int M=(L+R)>>1;
	if(pr<=M) update(Lc,L,M);
	else update(Rc,M+1,R);
	f[o]=min(f[Lc],f[Rc]);
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(n,m);
	for(int i=1;i<=n;i++) read(v[i].a,v[i].b);
	sort(v+1,v+1+n);
	build(1,0,m);
	for(int i=1;i<=n;i++)
	{
		pl=v[i].a-1; pr=v[i].b;
		val=query(1,0,m)+1;
		pl=pr=v[i].b;
		if(query(1,0,m)>val) update(1,0,m);
	}
	pl=pr=m;
	val=query(1,0,m);
	write(val!=oo?val:-1,'\n');
	return 0;
}