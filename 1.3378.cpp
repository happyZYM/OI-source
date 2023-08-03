// luogu-judger-enable-o2
#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> q; 
int n,a,b;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a==1) q.push((scanf("%d",&b),b));
        if(a==2) printf("%d\n",q.top());
        if(a==3) q.pop();
    }
}
