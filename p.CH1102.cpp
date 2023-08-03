//http://contest-hunter.org:83/contest/0x10%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E4%BE%8B%E9%A2%98/1102%20%E7%81%AB%E8%BD%A6%E8%BF%9B%E5%87%BA%E6%A0%88%E9%97%AE%E9%A2%98
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=60005;
int n,p[maxn*2],isp[maxn*2],res[1000005]={0,1},len=1,pcnt;
inline void times(int x)
{
	for(int i=1;i<=len;i++) res[i]*=x;
	len+=6;
	for(int i=1;i<=len;i++)
	{
		res[i+1]+=res[i]/10;
		res[i]%=10;
	}
	while(!res[len]) len--;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	memset(isp,1,sizeof(isp)); isp[0]=isp[1]=0;
	for(int i=2;i<=n*2;i++)
	{
		if(isp[i]) p[pcnt++]=i;
		for(int j=0;j<pcnt&&p[j]*i<=n*2;j++)
		{
			isp[p[j]*i]=0;
			if(i%p[j]==0) break;
		}
	}
	for(int i=0;i<pcnt;i++)
	{
		int a=p[i],acnt=0;
		while(a<=n*2)
		{
			acnt+= n*2/a - n/a - (n+1)/a;
			a=a*p[i];
		}
		while(acnt--) times(p[i]);
	}
	for(int i=len;i>=1;i--) printf("%d",res[i]); puts("");
	return 0;
}
