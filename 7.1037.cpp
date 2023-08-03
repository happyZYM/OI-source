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
typedef long long LL;
int T,n; LL m,f[21][21][2];
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	f[1][1][0]=f[1][1][1]=1;
	for(int i=2;i<=20;i++)
	{
		for(int j=1;j<=i;j++)
		{
			for(int k=j;k<=i-1;k++) f[i][j][0]+=f[i-1][k][1];
			for(int k=1;k<=j-1;k++) f[i][j][1]+=f[i-1][k][0];
		}
	}
	read(T);
	while(T-->0)
	{
		read(n,m);
		bool flg[21]={0};
		int lst,k;
		for(int j=1;j<=n;j++)
		{
			if(f[n][j][1]>=m) { lst=j; k=1; break; }
			else m-=f[n][j][1];
			if(f[n][j][0]>=m) { lst=j; k=0; break; }
			else m-=f[n][j][0];
		}
		flg[lst]=1; write(lst);
		for(int i=2;i<=n;i++)
		{
			k^=1;
			int j=0;
			for(int v=1;v<=n;v++)
			{
				if(flg[v]) continue;
				j++;
				if((k==0&&v<lst)||(k==1&&v>lst))
				{
					if(f[n-i+1][j][k]>=m) { lst=v; break;}
					else m-=f[n-i+1][j][k];
				}
			}
			flg[lst]=1;
			write(" ",lst);
		}
		write("\n");
	}
	return 0;
}