#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=7000005;
inline bool cmp(int a,int b) { return a>b; }
priority_queue<int>ans;
int Qa[maxn],now[maxn],Qb[maxn];
int n,m,q,u,v,t,add,h,ha,hb,Cnt,CntA,CntB;
double p;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    p=(double)u/v;
    for(Cnt=1;Cnt<=n;++Cnt) scanf("%d",&now[Cnt]);
    Cnt=n; h=ha=hb=1;
    sort(now+1,now+Cnt+1,cmp);
    for(int i=1;i<=m;i++)
	{
		int len;
        if(h>Cnt)
		{
			if(Qa[ha]>Qb[hb]) len=Qa[ha++];
			else len=Qb[hb++];
		}
        else if(now[h]>=Qa[ha]&&now[h]>=Qb[hb]) len=now[h++];
        else if(Qa[ha]>=Qb[hb]&&now[h]<=Qa[ha]) len=Qa[ha++];
        else len=Qb[hb++];
        len+=add;
        int a=p*len,b=len-a;
        add+=q;
        a-=add,b-=add;
        Qa[++CntA]=a;
		Qb[++CntB]=b;
        if(i%t==0) printf("%d ",len);
    }
    putchar('\n');
    for(int i=h;i<=Cnt;++i) ans.push(now[i]);
    for(int i=ha;i<=CntA;++i) ans.push(Qa[i]);
    for(int i=hb;i<=CntB;++i) ans.push(Qb[i]);
    for(int i=1;i<=n+m;i++)
	{
        if(i%t==0) printf("%d ",ans.top()+add);
        ans.pop();
    }
    return 0;
}
