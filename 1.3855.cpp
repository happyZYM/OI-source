#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct State { int Mx,My,Gx,Gy,step; };
const int dya[5]={0,0,0,1,-1},dxa[5]={0,-1,1,0,0};//Gurin
const int dyb[5]={0,0,0,-1,1},dxb[5]={0,-1,1,0,0};//Malon
int m,n;
char mp[31][31];
bool vis[31][31][31][31];
inline bool check(const State &st)
{
    if(st.Gx>n||st.Gx<1||st.Mx>n||st.Mx<1||st.Gy>m||st.Gy<1||st.My>m||st.My<1) return 0;
    if(mp[st.Gx][st.Gy]=='X'||mp[st.Mx][st.My]=='X') return 0;
    if(vis[st.Gx][st.Gy][st.Mx][st.My]) return 0;
    return 1;
}
inline void proc(State &st,int idx)
{
    if(mp[st.Gx][st.Gy]=='#') st.Gx-=dxa[idx],st.Gy-=dya[idx];
    if(mp[st.Mx][st.My]=='#') st.Mx-=dxb[idx],st.My-=dyb[idx];
}
int bfs(State beg)
{
    vis[beg.Gx][beg.Gy][beg.Mx][beg.My]=1;
    queue<State>Q;
    Q.push(beg);
    while(Q.size())
    {
        State now=Q.front(); Q.pop();
        if(mp[now.Gx][now.Gy]=='T'&&mp[now.Mx][now.My]=='T') return now.step;
        for(int i=1;i<=4;i++)
        {
            State tmp=now;
            tmp.Gx+=dxa[i],tmp.Gy+=dya[i];
            tmp.Mx+=dxb[i],tmp.My+=dyb[i];
            tmp.step++;
            proc(tmp,i);
            if(check(tmp))
            {
                vis[tmp.Gx][tmp.Gy][tmp.Mx][tmp.My]=1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    State beg;
    beg.step=0;
    cin>>n>>m; 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]=='G') beg.Gx=i,beg.Gy=j;
            if(mp[i][j]=='M') beg.Mx=i,beg.My=j;
        }
    int res=bfs(beg);
    if(res!=-1) cout<<res<<endl; 
    else cout<<"no"<<endl;
    return 0;
}
