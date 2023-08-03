#include<cstdio>
int n,m,x,res,l,r,a[1005],b[1005];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(a[x]==0) 
        {
            res++;
            r++; b[r]=x; a[x]=1;
            if(r>m) l++,a[b[l]]=0;
        }
    }
    printf("%d\n",res);
    return 0;
}
