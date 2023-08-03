#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10007;
int n,k,a[maxn],s[maxn],top,q,x;
bool f()
{
    k=1,top=0;
    for(int i=1;i<=n;i++)
    {
        s[++top]=i;
        while(top>0&&s[top]==a[k])
        {
            k++;
            top--;
        }
    }
    if(top==0) return 1;
    else return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    while(1)
    {
        scanf("%d",&q);
        if(q==0) break;
        while(1)
        {
            scanf("%d",&x);
            if(!x) break;
            else a[1]=x;
            for(int i=2;i<=q;i++)
                scanf("%d",&a[i]);
            n=q;
            if(f()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}
