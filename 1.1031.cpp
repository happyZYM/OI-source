// luogu-judger-enable-o2
#include<cstdio>
const int maxn=105;
int n,a[maxn],s,res;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]),s+=a[i];
    s/=n;
    for(int i=0;i<n;i++) a[i]-=s;
    for(int i=0;i<n;i++) if(a[i]!=0) a[i+1]+=a[i],res++;
    printf("%d\n",res);
    return 0;
}
