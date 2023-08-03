//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1809%20%E5%8C%B9%E9%85%8D%E7%BB%9F%E8%AE%A1
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200005;
char A[maxn],B[maxn];
int N,M,Q,cnt[maxn],nxt[maxn],f[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&N,&M,&Q);
	scanf("%s%s",A+1,B+1);
	nxt[1]=0;
	for(int i=2,j=0;i<=M;i++)
	{
		while(j&&B[i]!=B[j+1]) j=nxt[j];
		if(B[i]==B[j+1]) j++;
		nxt[i]=j;
	}
	for(int i=1,j=0;i<=N;i++)
	{
		while(j&&(j==M||A[i]!=B[j+1])) j=nxt[j];
		if(A[i]==B[j+1]) j++;
		f[i]=j;
	}
	for(int i=1;i<=N;i++) cnt[f[i]]++;
	for(int i=M;i>=1;i--) cnt[nxt[i]]+=cnt[i];
	while(Q-->0)
	{
		int x; scanf("%d",&x);
		printf("%d\n",cnt[x]-cnt[x+1]);
	}
	return 0;
}
