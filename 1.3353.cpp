// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,w,x,y,ans,a[100010],s[100010];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x]=a[x]+y;
        m=max(m,x);
    }
    for(int i=1;i<=m;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=m-w+1;i++)
        ans=max(ans,s[i+w-1]-s[i-1]);
    printf("%d",ans);
    return 0;
}
