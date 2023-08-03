#include<bits/stdc++.h>
using namespace std;
int n;
char a[30][3];
void dfs(char x)
{
    if(x=='*') return;
    cout<<x;
    for(int i=1;i<=n;i++)
        if(a[i][0]==x) dfs(a[i][1]),dfs(a[i][2]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
    dfs(a[1][0]);
    return 0;
}
