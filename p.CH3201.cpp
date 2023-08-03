//http://contest-hunter.org:83/contest/0x30%E3%80%8C%E6%95%B0%E5%AD%A6%E7%9F%A5%E8%AF%86%E3%80%8D%E4%BE%8B%E9%A2%98/3201%20Hankson%E7%9A%84%E8%B6%A3%E5%91%B3%E9%A2%98
#include<cstdio>
#include<algorithm>
using namespace std;
int T,a0,a1,b0,b1;
int p[50000],v[50000],pcnt,res;
void cal(int p)
{
	int ma0=0,ma1=0,mb0=0,mb1=0;
	while(a0%p==0) ma0++,a0/=p;
	while(a1%p==0) ma1++,a1/=p;
	while(b0%p==0) mb0++,b0/=p;
	while(b1%p==0) mb1++,b1/=p;
	if(ma0==ma1&&mb0==mb1&&ma1<=mb1) { res*=(mb1-ma1+1); return; }
	if((ma0>ma1&&mb0<mb1&&ma1==mb1)||(ma0>ma1&&mb0==mb1&&ma1<=mb1)||(ma0==ma1&&mb0<mb1&&ma1<=mb1)) return;
	res=0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	for(int i=1;i<50000;i++) v[i]=i;
	for(int i=2;i<50000;i++)
	{
		if(v[i]==i) p[pcnt++]=i;
		for(int j=0;j<pcnt&&p[j]*i<50000&&p[j]<=v[i];j++) v[p[j]*i]=p[j];
	}
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		res=1;
		for(int i=0;i<pcnt;i++) cal(p[i]);
		if(b1>1&&b1!=a1) cal(b1);
		printf("%d\n",res);
	}
	return 0;
}
