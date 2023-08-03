#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 100009
struct edge
{
    int from,to,cost;
};
int n,m,r,ans;
int p[M];
edge e[M];
int cmp(edge a,edge b)
{
    return a.cost<b.cost;
}
int find(int x)
{
    return x==p[x]?x:p[x]=find(p[x]);
}
int kruskal()
{
    for(int i=0;i<n+m;i++)
        p[i]=i;
    for(int i=0;i<r;i++)
    {
        int x=find(e[i].from);
        int y=find(e[i].to);
        if(x!=y)
        {
            p[x]=y;
            ans+=e[i].cost;
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ans = 0;
        scanf("%d %d %d",&n,&m,&r);
        for(int i = 0;i < r;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            e[i] = (edge){a,b+n,-c};
        }
        sort(e,e+r,cmp);
        printf("%d\n",10000*(n+m)+kruskal());
    }
    return 0;
}
