#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cassert>
using namespace std;
typedef long double LD;
const int maxn=100005;
int T,N,Len,P,a[maxn],sum[maxn],pre[maxn];
char s[maxn][33];
LD f[maxn];
inline LD ksm(LD v)
{
	LD res=1;
	for(int b=P;b;b>>=1,v=v*v) b&1?res*=v:0;
	return res;
}
inline LD val(int i,int j) { return ksm(abs((sum[i]-sum[j])+(i-j-1)-Len)); }
inline LD JC(int i,int j) { return f[j]+val(i,j); }
struct Data { int j,l,r; };
Data Q[maxn]; int L,R;
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%d",&N,&Len,&P);
		for(int i=1;i<=N;i++) { scanf("%s",s[i]); a[i]=strlen(s[i]); sum[i]=sum[i-1]+a[i]; }
		Q[L=R=1]=(Data){0,1,N};
		for(int i=1;i<=N;i++)
		{
			// printf("i=%d\n",i);
			if(Q[L].r==i-1) L++;
			else Q[L].l=i;
			assert(L<=R);
			f[i]=f[Q[L].j]+val(i,Q[L].j); pre[i]=Q[L].j;
			// printf("pre[%d]=%d\n",i,pre[i]);
			int pos=N+1;
			while(true)
			{
				if(JC(Q[R].l,i)<=JC(Q[R].l,Q[R].j)) { pos=Q[R].l; R--; continue; }
				if(JC(Q[R].r,Q[R].j)<=JC(Q[R].r,i)) break;
				int pl=Q[R].l,pr=Q[R].r,M;
				while(pl<=pr)
				{
					M=(pl+pr)>>1;
					if(JC(M,i)<=JC(M,Q[R].j)) pos=M,pr=M-1;
					else pl=M+1;
				}
				break;
			}
			// assert(pos!=N+1);
			if(pos!=N+1)
			{
				if(Q[R].l==pos) R--;
				else Q[R].r=pos-1;
				Q[++R]=(Data){i,pos,N};
			}
			// for(int i=L;i<=R;i++) printf("[%d,%d]=%d ",Q[i].l,Q[i].r,Q[i].j); puts("\n");
		}
		// puts("ok");
		if(f[N]>1e18) puts("Too hard to arrange");
		else
		{
			printf("%.0Lf\n",f[N]);
			stack<pair<int,int> > stk;
			int pr=N;
			while(pr)
			{
				stk.push(make_pair(pre[pr]+1,pr));
				pr=pre[pr];
			}
			while(stk.size())
			{
				int l=stk.top().first,r=stk.top().second;
				printf("%s",s[l]);
				for(int i=l+1;i<=r;i++)
					printf(" %s",s[i]);
				puts("");
				stk.pop();
			}
		}
		puts("--------------------");
	}
	return 0;
}