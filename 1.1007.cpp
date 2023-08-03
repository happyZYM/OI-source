#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,p,maxv,minv;
int main()
{
    scanf("%d%d",&l,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p);
        maxv=max(maxv,max(l-p+1,p));
        minv=max(minv,min(l-p+1,p));
    }
    printf("%d %d",minv,maxv);
    return 0;
}
