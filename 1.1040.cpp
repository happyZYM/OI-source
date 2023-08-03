#include<cstdio>
using namespace std;
int n,v[31],dp[31][31],root[31][31],l,r;
void print(int l,int r)
{
    if(l>r) return;
    printf("%d ",root[l][r]);
    print(l,root[l][r]-1);
    print(root[l][r]+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        dp[i][i]=v[i]; 
        root[i][i]=i;
    }
    for(int k=2;k<=n;k++)
        for(int l=1;l+k-1<=n;l++)
        {
            r=l+k-1;
            if(dp[l][r]<v[l]+dp[l+1][r])
            {
                dp[l][r]=v[l]+dp[l+1][r];
                root[l][r]=l;
            }
            if(dp[l][r]<v[r]+dp[l][r-1])
            {
                dp[l][r]=v[r]+dp[l][r-1];
                root[l][r]=r;
            }
            for(int i=l+1;i<=r-1;i++)
                if(dp[l][i-1]*dp[i+1][r]+v[i]>dp[l][r])
                {
                    dp[l][r]=v[i]+dp[l][i-1]*dp[i+1][r];
                    root[l][r]=i;
            	}
        }
    printf("%d\n",dp[1][n]);
    print(1,n);
    return 0;
}
