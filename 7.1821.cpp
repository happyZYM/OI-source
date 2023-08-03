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
struct Data { int l,p,s; };
inline bool operator<(const Data &a,const Data &b) { return a.s<b.s; }
const int maxn=16005;
const int maxm=105;
int n,m,f[maxm][maxn],q[maxn];
Data w[maxm];
inline int cal(int i,int k) { return f[i-1][k]-w[i].p*k; }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(n,m);
	for(int i=1;i<=m;i++) read(w[i].l,w[i].p,w[i].s);
	sort(w+1,w+1+m);
	for(int i=1;i<=m;i++)
	{
		int l=1,r=0;
		for(int k=max(0,w[i].s-w[i].l);k<=w[i].s-1;k++)
		{
			while(l<=r&&cal(i,q[r])<=cal(i,k)) r--;
			q[++r]=k;
		}
		for(int j=1;j<=n;j++)
		{
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if(j>=w[i].s)
			{
				while(l<=r&&q[l]<j-w[i].l) l++;
				if(l<=r) f[i][j]=max(f[i][j],cal(i,q[l])+w[i].p*j);
			}
		}
	}
	write(f[m][n],'\n');
	return 0;
}