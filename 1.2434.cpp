#include<cstdio>
#include<algorithm>
using namespace std;
const int maxv=2000005;
int n,d[maxv],L,R,st,v,maxR;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&L,&R);
		d[L*2-1]++; d[R*2]--;
		maxR=max(maxR,R*2);
	}
	for(int i=1;i<=maxR;i++)
	{
		v+=d[i];
		if(v&&st==0) { L=i; st=1; }
		if(!v&&st==1) { printf("%d %d\n",(L+1)/2,i/2); st=0; }
	}
	return 0;
}
