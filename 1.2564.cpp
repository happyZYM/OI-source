#include<cstdio>
#include<algorithm>
using namespace std;
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
const int maxn=1000010;
struct Node { int kind,p; };
inline bool operator<(const Node &a,const Node &b) { return a.p<b.p; }
Node a[maxn];
int hsh[70],ans=1e9+7,Ti,n,l=0,k,sum=0;
int que[maxn],head,tail;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    read(n,k);
    for(int i=1;i<=k;i++) 
    {
        read(Ti);
        while(Ti-->0)
        {
            int p; read(p);
            a[++l].p=p; a[l].kind=i;
        }    
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        que[tail++]=i;
        hsh[a[i].kind]++;
        if(hsh[a[i].kind]==1) sum++;
        while(sum==k)
        {
            Node &e=a[que[tail-1]],&s=a[que[head]];
            if(ans>e.p-s.p) ans=e.p-s.p;
            head++;
            hsh[s.kind]--;
            if(hsh[s.kind]==0) sum--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
