// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
int n,x,res;
priority_queue<int,vector<int>,greater<int>> Q;
int main()
{
    scanf("%d",&n);
    while(n-->0)
    {
        scanf("%d",&x);
        Q.push(x);
    }
    while(Q.size()>=2)
    {
        int a=Q.top(); Q.pop();
        a+=Q.top(); Q.pop();
        Q.push(a);
        res+=a;
    }
    printf("%d\n",res);
    return 0;
}
