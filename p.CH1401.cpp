//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1401%20%E5%85%94%E5%AD%90%E4%B8%8E%E5%85%94%E5%AD%90
#include<cstdio>
#include<cstring>
const int maxn=1000005;
const int P=131;
unsigned long long f[maxn],p[maxn];
int n,Q; char s[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s %d",s+1,&Q);
	n=strlen(s+1); p[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]*P+(s[i]-'a'+1);
		p[i]=p[i-1]*P;
	}
	for(int i=1;i<=Q;i++)
	{
		int L1,R1,L2,R2; scanf("%d%d%d%d",&L1,&R1,&L2,&R2);
		puts((f[R1]-f[L1-1]*p[R1-L1+1]==f[R2]-f[L2-1]*p[R2-L2+1])?"Yes":"No");
	}
	return 0;
}
