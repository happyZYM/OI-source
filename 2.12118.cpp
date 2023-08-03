#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1010;
int v,e,t,cnt;
bool vis[maxn];
vector<int> g[maxn];
inline bool read()
{
    cin>>v>>e>>t;
    if(!v&&!e&&!t) return false;
    for(int i=0;i<maxn;++i)
        g[i].clear();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<e;++i)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    return true;
}
void dfs(int cur)
{
    if(vis[cur]) return;
    vis[cur]=true;
    cnt+=(int)g[cur].size()&1;
    for(int i=0;i<g[cur].size();++i)
        dfs(g[cur][i]);
    return;
}
int solve()
{
    int ans=0;
    for(int i=1;i<=v;++i)
	{
        if(!vis[i]&&!g[i].empty())
		{
            cnt=0;
            dfs(i);
            ans+=max(cnt,2);
        }
    }
    return t*(max(ans/2-1,0)+e);
}
int main()
{
    ios::sync_with_stdio(false);
    int k=0;
    while(read())
        cout<<"Case "<<++k<<": "<<solve()<<endl;
    return 0;
}
