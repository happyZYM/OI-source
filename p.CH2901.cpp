//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2901%20%E9%9D%B6%E5%BD%A2%E6%95%B0%E7%8B%AC
#include<cstdio>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
const int maxn=81*4+5;
const int maxnode=9*9*9*4*4+5;
int res=-1;
const int p[9][9]=
{
{6,6,6,6,6,6,6,6,6},
{6,7,7,7,7,7,7,7,6},
{6,7,8,8,8,8,8,7,6},
{6,7,8,9,9,9,8,7,6},
{6,7,8,9,10,9,8,7,6},
{6,7,8,9,9,9,8,7,6},
{6,7,8,8,8,8,8,7,6},
{6,7,7,7,7,7,7,7,6},
{6,6,6,6,6,6,6,6,6}
};
const int Slot=0;
const int Row=1;
const int Col=2;
const int Sub=3;
inline int encode(int a,int b,int c) { return a*81+b*9+c+1; }
inline void decode(int code,int &a,int &b,int &c)
{
    code--;
    c=code%9; code/=9;
    b=code%9; code/=9;
    a=code;
}
struct DLX
{
    int n,sz;
    int s[maxn];
    int row[maxnode],col[maxnode];
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    void init(int n)
    {
        this->n=n;
        sz=n+1;
        memset(s,0,sizeof(s));
        
        for(int i=0;i<=n;i++)
            { U[i]=i; D[i]=i; L[i]=i-1; R[i]=i+1; } 
        R[n]=0; L[0]=n;
    }
    void addNodes(int r,const vector<int> &columns)
    {
        int first=sz,c_sz=columns.size();
        for(int i=0;i<c_sz;i++)
        {
            int c=columns[i];
            L[sz]=sz-1; R[sz]=sz+1; D[sz]=c; U[sz]=U[c];
            D[U[c]]=sz; U[c]=sz;
            row[sz]=r; col[sz]=c;
            s[c]++;sz++;
        }
        R[sz-1]=first; L[first]=sz-1;
    }
    
    #define For(i,A,s) for(int i=A[s];i!=s;i=A[i])
    void remove(int c)
    {
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        For(i,D,c)
            For(j,R,i)
            { U[D[j]]=U[j]; D[U[j]]=D[j]; --s[col[j]]; }
    }
    void restore(int c)
    {
        For(i,U,c)
            For(j,L,i)
            { ++s[col[j]]; U[D[j]]=j; D[U[j]]=j; }
        L[R[c]]=c;
        R[L[c]]=c;
    }
    
    bool dfs(int val)
    {
        if(R[0]==0) { res=max(res,val); return true; }
        
        int c=R[0],flag=false;
        For(i,R,0) if(s[i]<s[c]) c=i;
        
        remove(c);
        
        For(i,D,c)
        {
            For(j,R,i) remove(col[j]);
            int nr,nc,nv;
            decode(row[i],nr,nc,nv);
            if(dfs(val+p[nr][nc]*(nv+1))) flag=true;
            For(j,L,i) restore(col[j]);
        }
        restore(c);
        
        return flag;
    }
    #undef For
};
DLX solver;
int mp[9][9];
#define For(i,a,b) for(int i=(a);i<=(b);i++)
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    For(r,0,8) For(c,0,8) scanf("%d",&mp[r][c]);
    solver.init(9*9*4);
    For(r,0,8) For(c,0,8) For(v,0,8)
        if(mp[r][c]==0||mp[r][c]==v+1)
        {
            vector<int> cols;
            cols.push_back(encode(Slot,r,c));
            cols.push_back(encode(Row,r,v));
            cols.push_back(encode(Col,c,v));
            cols.push_back(encode(Sub,(r/3)*3+c/3,v));
            solver.addNodes(encode(r,c,v),cols);
        }
    solver.dfs(0);
    printf("%d\n",res);
    return 0;
}
