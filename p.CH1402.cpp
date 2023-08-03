//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1402%20%E5%90%8E%E7%BC%80%E6%95%B0%E7%BB%84
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=300005;
const int P=13141;
int n;
char s[maxn];
int SA[maxn],Height[maxn];
unsigned long long H[maxn],pm[maxn];
inline int LCP(int a,int b)
{
	int L=0,R=min(n-a+1,n-b+1),M,res=0;
	while(L<=R)
	{
		M=(L+R)>>1;
		if(H[a+M-1]-H[a-1]*pm[M]==H[b+M-1]-H[b-1]*pm[M]) L=M+1,res=M;
		else R=M-1;
	}
	return res;
}
inline bool cmp(int a,int b)
{
	int t=LCP(a,b);
	return s[a+t]<s[b+t];
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) SA[i]=i;
	pm[0]=1;
	for(int i=1;i<=n;i++) pm[i]=pm[i-1]*P;
	for(int i=1;i<=n;i++) H[i]=H[i-1]*P+(s[i]-'a'+1);
	sort(SA+1,SA+1+n,cmp);
	for(int i=2;i<=n;i++) Height[i]=LCP(SA[i],SA[i-1]);
	for(int i=1;i<=n;i++) printf("%d ",SA[i]-1);	puts("");
	for(int i=1;i<=n;i++) printf("%d ",Height[i]);	puts("");
	return 0;
}
