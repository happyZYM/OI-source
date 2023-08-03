
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
struct Edge { int v; Edge *next; };
int n,m;
Edge mem[maxn*2],*ecnt=mem,*G[maxn];
inline void AddEdge(int u,int v) { ecnt->v=v; ecnt->next=G[u]; G[u]=ecnt++; }
int co[maxn],dep[maxn],size[maxn],fa[maxn],son[maxn],id[maxn],cnt,top[maxn];
void InitData(int u,int f)
{
    fa[u]=f; dep[u]=dep[f]+1; size[u]=1;
    for(Edge *it=G[u];it;it=it->next)
    {
        int v=it->v;
        if(v==f) continue;
        InitData(v,u);
        size[u]+=size[v];
        if(size[v]>size[son[u]]) son[u]=v;
    }
}
void AllocId(int u,int tp)
{
    id[u]=++cnt; top[u]=tp;
    if(!son[u]) return;
    AllocId(son[u],tp);
    for(Edge *it=G[u];it;it=it->next)
    {
        int v=it->v;
        if(v==son[u]||v==fa[u]) continue;
        AllocId(v,v);
    }
}
namespace SegmentTree
{
    int tot[maxn<<2],v[maxn<<2],cl[maxn],Rc[maxn<<2],Lc[maxn<<2];
    int Lco,Rco;
    inline void push_up(int o)
    {
        Lc[o]=Lc[o<<1];
        Rc[o]=Rc[o<<1|1];
        tot[o]=tot[o<<1]+tot[o<<1|1]-(Rc[o<<1]==Lc[o<<1|1]);
    }
    void init(int o,int L,int R)
    {
        if(L==R) { Lc[o]=Rc[o]=v[o]=cl[L]; tot[o]=1; return; }
        int M=(L+R)>>1;
        init(o<<1,L,M);
        init(o<<1|1,M+1,R);
        push_up(o);
    }
    void setup()
    {
        for(int i=1;i<=n;i++) cl[id[i]]=co[i];
        init(1,1,n);
    }
    inline void push_down(int o)
    {
        if(!v[o]) return;
        v[o<<1]=v[o<<1|1]=v[o];
        Lc[o<<1]=Rc[o<<1]=Lc[o<<1|1]=Rc[o<<1|1]=v[o];
        tot[o<<1]=tot[o<<1|1]=1;
        v[o]=0;
    }
    void update(int o,int L,int R,int pl,int pr,int c)
    {
        if(pl<=L&&R<=pr) { Lc[o]=Rc[o]=v[o]=c; tot[o]=1; return; }
        push_down(o);
        int M=(L+R)>>1;
        if(pl<=M) update(o<<1,L,M,pl,pr,c);
        if(pr>M) update(o<<1|1,M+1,R,pl,pr,c);
        push_up(o);
    }
    int query(int o,int L,int R,int pl,int pr)
    {
        if(L==pl) Lco=Lc[o];
        if(R==pr) Rco=Rc[o];
        if(pl<=L&&R<=pr) return tot[o];
        push_down(o);
        int M=(L+R)>>1,res=0;
        if(pr<=M) return query(o<<1,L,M,pl,pr);
        else if(pl>M) return query(o<<1|1,M+1,R,pl,pr);
        else return query(o<<1,L,M,pl,pr)+query(o<<1|1,M+1,R,pl,pr)-(Rc[o<<1]==Lc[o<<1|1]);
    }
}
void update(int a,int b,int c)
{
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) swap(a,b);
        SegmentTree::update(1,1,n,id[top[a]],id[a],c);
        a=fa[top[a]];
    }
    if(id[a]>id[b]) swap(a,b);
    SegmentTree::update(1,1,n,id[a],id[b],c);
}
int query(int a,int b)
{
    int res=0,ca=-1,cb=-1;
    using SegmentTree::Lco;
    using SegmentTree::Rco;
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]]) { swap(a,b); swap(ca,cb); }
        res+=SegmentTree::query(1,1,n,id[top[a]],id[a]);
        if(Rco==ca) res--;
        ca=Lco;
        a=fa[top[a]];
    }
    if(id[a]>id[b]) { swap(a,b); swap(ca,cb); }
    res+=SegmentTree::query(1,1,n,id[a],id[b]);
    if(Lco==ca) res--;
    if(Rco==cb) res--;
    return res;
}
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&co[i]);
    for(int i=1;i<=n-1;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        AddEdge(x,y); AddEdge(y,x);
    }
//    dep[0]=1;
    InitData(1,0);
    AllocId(1,1);
    SegmentTree::setup();
    char opt; int a,b,c;
    while(m-->0)
    {
        scanf("%s%d%d",&opt,&a,&b);
        if(opt=='C')
        {
            scanf("%d",&c);
            update(a,b,c); 
        }
        else printf("%d\n",query(a,b)); 
    }
    return 0;
}
