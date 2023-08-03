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
template<typename T> inline int read(T& t)
{
	t=0; bool f=false; int ch; while(ch=gch(),!((ch>='0'&&ch<='9')||ch=='-')) { if(ch==EOF) return 0; }
	if(ch=='-') f=true,ch=gch(); t=ch-'0'; while(ch=gch(),ch>='0'&&ch<='9') t=t*10+ch-'0';
	if(f) t=-t;
	return 1;
}
inline int read(char &c)
{
	c=0; int ch; while(ch=gch(),(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')) { if(ch==EOF) return 0; } c=ch;
	return 1;
}
inline int read(char *s)
{
	int ch; while(ch=gch(),(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')) { if(ch==EOF) return 0; }
	*s++=ch; while(ch=gch(),!(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')&&ch!=EOF) *s++=ch;
	return 1;
} inline int read(const char *s) { return read((char*)s); }
inline int readline(char *s)
{
	int ch; while(ch=gch(),(ch==' '||ch=='\n'||ch=='\r'||ch=='\t')) { if(ch==EOF) return 0; }
	*s++=ch; while(ch=gch(),!(ch=='\n'||ch=='\r')&&ch!=EOF) *s++=ch;
	return 1;
} inline int readline(const char *s) { return readline((char*)s); }
template<typename T> inline void write(T t)
{
	int stk[20],cnt=0;
	if(t==0) { wch('0'); return; } if(t<0) { wch('-'); t=-t; }
	while(t>0) { stk[cnt++]=t%10; t/=10; } while(cnt) wch(stk[--cnt]+'0');
}
inline void write(char t) { wch(t); }
inline void write(char *s) { while(*s) wch(*s++); } inline void write(const char *s) { write((char*)s); }
#if __cplusplus >= 201103L
template<typename T,typename... Args> inline int read(T& t,Args&... args) { return read(t)+read(args...); }
template<typename T,typename... Args> inline void write(T t,Args... args) { write(t); write(args...); }
#else
template<typename A_t,typename B_t> inline int read(A_t &a,B_t &b) { return read(a)+read(b); }
template<typename A_t,typename B_t,typename C_t> inline int read(A_t &a,B_t &b,C_t &c) { return read(a)+read(b)+read(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline int read(A_t &a,B_t &b,C_t &c,D_t &d) { return read(a)+read(b)+read(c)+read(d); }
template<typename A_t,typename B_t> inline void write(A_t a,B_t b) { write(a); write(b); }
template<typename A_t,typename B_t,typename C_t> inline void write(A_t a,B_t b,C_t c) { write(a); write(b); write(c); }
template<typename A_t,typename B_t,typename C_t,typename D_t> inline void write(A_t a,B_t b,C_t c,D_t d) { write(a); write(b); write(c); write(d); }
#endif
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m; long long f[21][4];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	f[0][0]=1;
	for(int i=1;i<=20;i++)
	{
		f[i][0]=9*(f[i-1][0]+f[i-1][1]+f[i-1][2]);
		f[i][1]=f[i-1][0]; f[i][2]=f[i-1][1];
		f[i][3]=f[i-1][2]+10*f[i-1][3];
	}
	read(T);
	while(T-->0)
	{
		read(n);
		for(m=3;f[m][3]<n;m++);
		for(int i=m,k=0;i;i--)
		{
			for(int j=0;j<=9;j++)
			{
				long long cnt=f[i-1][3];
				if(j==6||k==3)
					for(int l=max(3-k-(j==6),0);l<3;l++)
						cnt+=f[i-1][l];
				if(cnt<n) n-=cnt;
				else
				{
					if(k<3) j==6?k++:k=0;
					write(j);
					break;
				}
			}
		}
		write("\n");
	}
	return 0;
}