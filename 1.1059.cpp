#include<cstdio>
using namespace std;
int n,a[1001],res,t;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t);
        if(a[t]==0) a[t]=t,res++;
    }
    printf("%d\n",res);
    for(int i=0;i<1001;i++) if(a[i]!=0) printf("%d ",a[i]);
    return 0;
}
