#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxlen=105;
inline void Add(int *a,int *b)
{
    int &la=a[0],&lb=b[0];
    for(int i=1;i<=max(la,lb);i++)
    {
        if(i>la) a[++la]=0;
        a[i]+=b[i];
    }
    for(int i=1;i<=la;i++)
        if(a[i]>9)
        {
            if(i==la) a[++la]=0;
            a[i+1]++;
            a[i]-=10;
        }
}
inline void Times(int *a,int b)
{
    int &la=a[0];
    for(int i=1;i<=la;i++) a[i]*=b;
    for(int i=1;i<=la;i++)
        if(a[i]>9)
        {
            if(i==la) a[++la]=0;
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
}
inline void Times(int *a,int *b)
{
    static int c[maxlen];
    int &la=a[0],&lb=b[0],&lc=c[0];
    memset(c,0,sizeof(c));
    lc=la+lb-1;
    for(int i=1;i<=la;i++) for(int j=1;j<=lb;j++) c[i+j-1]+=a[i]*b[j];
    for(int i=1;i<=lc;i++)
        if(c[i]>9)
        {
            if(i==lc) c[++lc]=0;
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    la=lc;
    for(int i=1;i<=lc;i++) a[i]=c[i];
}
int n,k;
map<int,int> ys;
int res[maxlen]={1,1},tot[maxlen],t[maxlen];
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d%d",&n,&k);
    for(int i=2;i*i<=n;i++) if(n%i==0) while(n%i==0) { ++ys[i]; n/=i; }
    if(n>1) ++ys[n];
    if(n>1) n=1;
    for(map<int,int>::iterator it=ys.begin();it!=ys.end();++it)
    {
        int v=it->first,p=it->second*k;
        tot[0]=tot[1]=t[0]=t[1]=1;
        for(int i=0;i<p;i++) { Times(t,v); Add(tot,t); }
        Times(res,tot);
    }
    for(int i=res[0];i>=1;i--) printf("%d",res[i]); printf("\n");
    return 0;
}
