#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn=100005;
int n,a[maxn];
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(int i=0;i<n;i++) printf("%d ",a[i]); puts("");
    return 0;
}

