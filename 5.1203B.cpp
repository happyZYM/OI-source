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
#include<map>
using namespace std;
int T,n,a[205],cnt;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	read(T);
	while(T-->0)
	{
		read(n);
		map<int,int> mp;
		for(int i=0;i<n*4;i++)
		{
			int x; read(x);
			mp[x]++;
		}
		cnt=0;
		for(auto v:mp)
		{
			if(v.second&1) { puts("NO"); goto ed; }
			for(int i=0;i<v.second/2;i++) a[cnt++]=v.first;
		}
		// printf("a: "); for(int i=0;i<cnt;i++) printf("%d ",a[i]); puts("");
		for(int i=1,j=cnt-2;i<j;i++,j--)
			if(a[i]*a[j]!=a[0]*a[cnt-1]) { puts("NO"); goto ed; }
		puts("YES");
		ed:;
	}
	return 0;
}