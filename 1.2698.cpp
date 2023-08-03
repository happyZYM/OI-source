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
const int maxn=100005;
int n,d,l,r,h1=1,h2=1,t1,t2,ans=1e9;
int q1[maxn],q2[maxn];
struct node { int x,y; } a[maxn];
inline bool operator<(const node &a,const node &b) { return a.x<b.x; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    read(n,d);
    for(int i=1;i<=n;++i) read(a[i].x,a[i].y);
    sort(a+1,a+n+1);
    for(l=1,r=0;l<=n;++l)
	{
        while(h1<=t1&&q1[h1]<l) ++h1;
        while(h2<=t2&&q2[h2]<l) ++h2;
        while(a[q1[h1]].y-a[q2[h2]].y<d&&r<n)
		{
            ++r;
            while(a[q1[t1]].y<a[r].y&&h1<=t1) --t1; q1[++t1]=r;
            while(a[q2[t2]].y>a[r].y&&h2<=t2) --t2; q2[++t2]=r; 
        }
        if(a[q1[h1]].y-a[q2[h2]].y>=d) ans=min(ans,a[r].x-a[l].x);
    }
    printf("%d",ans>=1e9?-1:ans);
    return 0;
}
