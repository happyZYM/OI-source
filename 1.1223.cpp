// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
using namespace std;
struct node { int ti,id; };
inline bool operator<(const node a,const node b) { return a.ti<b.ti; }
node p[1005];
int n;
double s=0.0;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&p[i].ti),p[i].id=i+1;
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i].id);
        s+=p[i].ti*(n-i-1);
    }
    printf("\n%.2lf\n",s/n);
    return 0;
}
