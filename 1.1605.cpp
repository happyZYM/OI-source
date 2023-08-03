#include<bits/stdc++.h>
using namespace std;
int q[101][101];
int sum=0;
int i,j,n,m,t,sx,sy,x,y,ex,ey;
const int da[]={-1,0,0,1};
const int db[]={0,-1,1,0};
void dfs(int a,int b)
{
    if(a==ex&&b==ey) { sum++; return; }
    q[a][b]=0;
    for(int i=0;i<4;i++)
    	if(q[a+da[i]][b+db[i]]!=0)
    	{
    		dfs(a+da[i],b+db[i]);
    		q[a+da[i]][b+db[i]]=1;
    	}
}
int main()
{
    memset(q,0,sizeof(q));
    cin>>n>>m>>t;
    cin>>sx>>sy>>ex>>ey;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            q[i][j]=1;
    for(i=1;i<=t;i++)
    {
        cin>>x>>y;
        q[x][y]=0;
    }
    dfs(sx,sy);
    cout<<sum<<endl;
    return 0;
}
