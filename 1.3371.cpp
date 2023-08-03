#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=10005;
const int maxm=500005;
const ll oo=2147483647;
struct char_reader
{
	FILE* f;
	char *buf,*p1,*p2;
	int size;
	char_reader(FILE* fin,int bufsize=65536)
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
	char_writer(FILE* fout,int bufsize=65536)
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
inline void read(int &x)
{
	bool f=true;int ch;
	x=0;
	while(ch=gch(),!(ch=='-'||ch>='0'&&ch<='9'));
	if(ch=='-') f=false,ch=gch();
	x=ch-'0';
	while(ch=gch(),ch>='0'&&ch<='9') x=x*10+ch-'0';
	if(!f) x=-x;
}
inline int write(ll x)
{
	if(x==0) return wch('0');
	if(x<0) wch('-'),x=-x;
	static char buf[20],top;
	top=0;
	while(x>0) buf[top++]=x%10+'0',x/=10;
	while(top>0) wch(buf[--top]);
}
struct Edge
{
	int to;
	ll dist;
	Edge *next;
};
ll d[maxn];
bool vis[maxn];
Edge *e[maxn],mem[maxm],*ecnt=mem;
int n,m,s;
inline void AddEdge(int from,int to,ll dist)
{
	ecnt->to=to; ecnt->dist=dist; ecnt->next=e[from];
	e[from]=ecnt++;
}
class deque
{
	private:
		int Size;
		int Q[maxn];
		int head,tail;
	public:
		inline int size() { return Size; }
		inline int front() { return Q[head]; }
		inline void pop_front()
		{
			Size--;
			head=(head+1)%maxn;
		}
		inline void push_front(int v)
		{
			Size++;
			head=(head-1+maxn)%maxn;
			Q[head]=v;
		}
		inline void push_back(int v)
		{
			Size++;
			Q[tail]=v;
			tail=(tail+1)%maxn;
		}
	deque() { Size=head=tail=0; }
};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
//	scanf("%d%d%d",&n,&m,&s);
	read(n);read(m);read(s);
	for(int i=1;i<=n;i++) d[i]=oo;
	d[s]=0;
	int f,t,dist;
	ll sum=0;
	for(int i=0;i<m;i++)
	{
//		scanf("%d%d%lld",&f,&t,&dist);
		read(f);read(t);read(dist);
		AddEdge(f,t,dist);
	}
	deque Q;
	Q.push_back(s);
	vis[s]=true;
	while(Q.size())
	{
		int u;
		while(true)
		{
			u=Q.front();Q.pop_front();
			if(d[u]*Q.size()<=sum) break;
			Q.push_back(u);
		}
		vis[u]=false;
		sum-=d[u];
		for(Edge *it=e[u];it;it=it->next)
			if(d[it->to]>d[u]+it->dist)
			{
				if(!vis[it->to])
				{
					d[it->to]=d[u]+it->dist;
					if(Q.size()>0&&d[Q.front()]>d[it->to]) Q.push_front(it->to);
					else Q.push_back(it->to);
					vis[it->to]=true;
					sum+=d[it->to];
				}
				else
				{
					sum-=d[it->to];
					d[it->to]=d[u]+it->dist;
					sum+=d[it->to];
				}
			}
	}
	for(int i=1;i<=n;i++)
		write(d[i]),wch(' ');
	wch('\n');
	return 0;
}
