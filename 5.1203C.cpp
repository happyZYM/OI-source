#include<cstdio>
struct char_reader
{
	FILE* f;
	char *buf,*p1,*p2;
	int size;
	char_reader(FILE* fin,int bufsize=100000)
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
	char_writer(FILE* fout,int bufsize=100000)
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
#if __cplusplus >= 201103L
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
#endif
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,x,g,res;
LL gcd(LL a,LL b) { return b?gcd(b,a%b):a; }
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	g=0;
	read(n);
	for(int i=0;i<n;i++) { read(x); g=gcd(g,x); }
	for(LL i=1;i*i<=g;i++)
		if(g%i==0)
		{
			res+=2;
			if(i*i==g) res--;
		}
	printf("%I64d\n",res);
	return 0;
}