#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+7;
int n,q,a[maxn],b[maxn],l[maxn],r[maxn],bid[maxn],add[maxn],blo,tts;
void reset(int x)
{
    for(int i=l[bid[x]];i<=r[bid[x]];i++) b[i]=a[i];
    sort(b+l[bid[x]],b+r[bid[x]]+1);
}
void update(int ll,int rr,int w)
{
    if(bid[ll]==bid[rr]) { for(int i=ll;i<=rr;i++) a[i]+=w; reset(ll); }
    for(int i=ll;i<=r[bid[ll]];i++) a[i]+=w;
    for(int i=l[bid[rr]];i<=rr;i++) a[i]+=w;
    reset(ll); reset(rr);
    for(int i=bid[ll]+1;i<bid[rr];i++) add[i]+=w;
}
int lb(int x,int w)
{
    int ll=l[x],rr=r[x],mid;
    while(ll<=rr)
	{
        mid=(ll+rr)/2;
        if(b[mid]<w) ll=mid+1;
        else rr=mid-1;
    }
    return r[x]-ll+1;
}
int query(int ll,int rr,int w)
{
    int res=0;
    if(bid[ll]==bid[rr])
	{
        for(int i=ll;i<=rr;i++) if(a[i]+add[bid[ll]]>=w) res++;
        return res;
    }
    for(int i=ll;i<=r[bid[ll]];i++) if(a[i]+add[bid[i]]>=w) res++;
    for(int i=l[bid[rr]];i<=rr;i++) if(a[i]+add[bid[i]]>=w) res++;
    for(int i=bid[ll]+1;i<bid[rr];i++) res+=lb(i,w-add[i]);
    return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    blo=sqrt(n);
    tts=(n-1)/blo+1;
    for(int i=1;i<=n;i++) bid[i]=(i-1)/blo+1,b[i]=a[i];
    for(int i=1;i<=tts;i++) l[i]=(i-1)*blo+1,r[i]=i*blo;
    r[tts]=n;
    for(int i=1;i<=tts;i++) sort(b+l[i],b+r[i]+1);
    int x,y,w;
    for(int i=1;i<=q;i++)
	{
        char c[5];
        scanf("%s%d%d%d",c,&x,&y,&w);
        if(c[0]=='M') update(x,y,w);
        else printf("%d\n",query(x,y,w));
    }
    return 0;
}
