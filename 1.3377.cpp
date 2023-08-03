#include<cstdio>
const int maxn=100010;
template<typename T> inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }
int n,m;
int ch[maxn][2],val[maxn],fa[maxn],dist[maxn];
#define swap(a,b) a^=b^=a^=b
int merge(int a,int b)
{
	if(a==0||b==0) return a+b;
	if(val[a]>val[b]||(val[a]==val[b]&&a>b)) swap(a,b);
	ch[a][1]=merge(ch[a][1],b);
	fa[ch[a][1]]=a;
	if(dist[ch[a][0]]<dist[ch[a][1]]) swap(ch[a][0],ch[a][1]);
	dist[a]=dist[ch[a][1]]+1;
	return a;
}
inline int getf(int a) { while(fa[a]) a=fa[a]; return a; }
inline void pop(int a)
{
	val[a]=-1;
	fa[ch[a][0]]=fa[ch[a][1]]=0;
	merge(ch[a][0],ch[a][1]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m);
	dist[0]=-1;
	for(int i=1;i<=n;i++) read(val[i]);
	while(m-->0)
	{
		int opt,x,y; read(opt);
		if(opt==1)
		{
			read(x,y);
			if(val[x]==-1||val[y]==-1) continue;
			int fx=getf(x),fy=getf(y);
			if(fx==fy) continue;
			merge(fx,fy);
		}
		else
		{
			read(x);
			if(val[x]==-1) printf("-1\n");
			else
			{
				int fx=getf(x);
				printf("%d\n",val[fx]);
				pop(fx);
			}
		}
	}
	return 0;
}
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int maxn=100005;
//template<typename T>
//inline void read(T& t)
//{
//    t=0; bool f=false; char ch;
//    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
//    if(ch=='-') f=true,ch=getchar();
//    t=ch-'0';
//    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
//    if(f) t=-t;
//}
//template<typename T,typename... Args>
//inline void read(T& t,Args&... args) { read(t); read(args...); }
//struct Item { int v,idx; };
//inline bool operator<(const Item &a,const Item &b)
//{ return a.v<b.v||(a.v==b.v&&a.idx<b.idx); }
//struct Node
//{
//	Item v;
//	Node *ch[2],*fa;
//	int dist;
//};
//Node *o[maxn],*null=new Node(),mem[maxn],*mcnt=mem;
//bool deleted[maxn];
//inline Node* GetFa(Node* o)
//{
//	while(o->fa!=null) o=o->fa;
//	return o;
//}
//int n,m;
//Node* merge(Node* a,Node* b)
//{
//	if(a==null) return b;
//	if(b==null) return a;
//	if(b->v<a->v) swap(a,b);
//	a->ch[1]=merge(a->ch[1],b);
//	if(a->ch[1]!=null) a->ch[1]->fa=a;
//	if(a->ch[0]!=null) a->ch[0]->fa=a;
//	if(a->ch[0]->dist<a->ch[1]->dist) swap(a->ch[0],a->ch[1]);
//	a->dist=a->ch[1]->dist+1;
//	return a;
//}
//int main()
//{
//#ifdef local
//	freopen("pro.in","r",stdin);
//#endif
//	null->ch[0]=null->ch[1]=null; null->dist=-1;
//	read(n,m);
//	for(int i=1;i<=n;i++)
//	{
//		int x; read(x);
//		mcnt->dist=0; mcnt->v.v=x; mcnt->v.idx=i; mcnt->ch[0]=mcnt->ch[1]=mcnt->fa=null;
//		o[i]=mcnt++;
//	}
//	int opt,x,y;
//	while(m-->0)
//	{
//		read(opt);
//		if(opt==1)
//		{
//			read(x,y);
//			if(deleted[x]||deleted[y]) continue;
//			Node *fx=GetFa(o[x]),*fy=GetFa(o[y]);
//			if(fx==fy) continue;
//			merge(fx,fy);
//		}
//		else
//		{
//			read(x);
//			if(deleted[x]) { printf("-1\n"); continue; }
//			Node *fx=GetFa(o[x]);
//			printf("%d\n",fx->v.v);
//			deleted[fx->v.idx]=true;
//			fx->ch[0]->fa=fx->ch[1]->fa=null;
//			merge(fx->ch[0],fx->ch[1]);
//		}
//	}
//	return 0;
//}
/*
5 5
1 5 4 2 3
1 1 5
1 2 5
2 2
1 4 2
2 2

{1}{5}{4}{2}{3}
{1,3}{5}{4}{2}
{1,3,5}{4}{2}
*/
