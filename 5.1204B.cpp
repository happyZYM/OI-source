#include<cstdio>
struct char_reader
{
	FILE* f;
	char *buf,*p1,*p2;
	int size;
	char_reader(FILE* fin,int bufsize=1000000)
	{
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
struct char_writer
{
	FILE* f;
	char *buf,*p,*end;
	char_writer(FILE* fout,int bufsize=1000000)
	{
		f=fout;
		buf=new char[bufsize];
		p=buf;
		end=buf+bufsize;
	}
	~char_writer()
	{
		fwrite(buf,p-buf,1,f);
	}
	inline char operator()(char ch)
	{
		return end==p&&(fwrite(buf,end-buf,1,f),p=buf),*p++=ch;
	}
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
#endif
#include<cstring>
#include<algorithm>
using namespace std;
int n,l,r;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(n,l,r);
	write(n-l+(1<<l)-1,' ',(1<<r)-1+(n-r)*(1<<(r-1)),'\n');
	return 0;
}