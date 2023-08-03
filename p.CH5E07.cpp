//https://www.acwing.com/problem/content/320/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20005;
int a[7],f[maxn*6],tot,Q[maxn*6],L,R;
void DP(int v,int t)
{
	for(int s=0;s<v;s++)
	{
		Q[L=R=1]=s;
		for(int j=s+v;j<=tot;j+=v)
		{
			while(L<=R&&(j-Q[L])/v>t) L++;
			if(L<=R) f[j]=f[Q[L]];
			while(L<=R&&f[j]>=f[Q[R]]) R--;
			Q[++R]=j;
		}
	}
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	while(true)
	{
		tot=0;
		for(int i=1;i<=6;i++) { scanf("%d",&a[i]); tot+=a[i]*i; }
		if(tot==0) return 0;
		if(tot&1) { puts("Can't"); continue; }
		memset(f,0,sizeof(f));
		f[0]=1; tot/=2;
		for(int i=1;i<=6;i++) DP(i,a[i]);
		puts(f[tot]?"Can":"Can't");
	}
	return 0;
}