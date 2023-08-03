#include<cstdio>
#include<cctype>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
int T;
int line;
char buf[100],s[100];
int iex,ex;
bool hsh[128];
inline int GetNum(char *s)
{
    int len=strlen(s),res=0;
    for(int i=0;i<len;i++) res=res*10+s[i]-'0';
    return res;
}
void solve()
{
    memset(hsh,0,sizeof(hsh));
    stack<char> stk;
    stack<int> add;
    stack<bool> can;
    int depth=0; ex=0;
    bool err=false;
    for(int i=0;i<line;i++)
    {
        char ch;
        fgets(buf,100,stdin); ch=buf[0];
        if(err) continue;
        if(ch=='F')
        {
            char name;
            sscanf(buf,"F %c",&name);
            if(hsh[name]) { err=true; goto end; }
            hsh[name]=true;
            stk.push(name);
            char x[10],y[10];
            sscanf(buf,"F %*c %s %s",x,y);
            bool flag;
            if(x[0]=='n') { add.push(0); flag=(y[0]=='n'); }
            else
            {
                if(y[0]=='n') { add.push(1); depth++; flag=true; }
                else
                {
                    add.push(0);
                    int nx=GetNum(x),ny=GetNum(y);
                    if(ny-nx+1>=1) flag=true;
                    else flag=false;
                }
            }
            if(flag&&(can.empty()||can.top())) can.push(true);
            else can.push(false);
        }
        else
        {
            if(stk.empty()) { err=true; goto end; }
            hsh[stk.top()]=false;
            if(can.top()) ex=max(ex,depth);
            depth-=add.top();
            stk.pop();
            add.pop();
            can.pop();
        }
end:	continue;
    }
    if(stk.size()) err=true;
    if(err) printf("ERR\n");
    else if(ex==iex) printf("Yes\n");
    else printf("No\n");
}
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    fgets(buf,100,stdin);
	sscanf(buf,"%d",&T);
    while(T-->0)
    {
    	fgets(buf,100,stdin);
		sscanf(buf,"%d O(%s)",&line,s);
        if(s[0]=='1') iex=0;
        else sscanf(s,"n^%d",&iex);
        solve();
    }
    return 0;
}
