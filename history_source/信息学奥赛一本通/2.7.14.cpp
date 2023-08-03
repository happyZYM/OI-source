#include<cstdio>
#include<algorithm>
using namespace std;
int L,N,M,D[50005],l=1<<30,r,mid;
bool solve(int x)
{
	int last=0,cnt=0;
	for(int i=1;i<=N+1;i++)
	{
		if(D[i]-last<x) cnt++;
		else last=D[i];
	}
	if(cnt>M) return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&L,&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%d",D+i);
	D[N+1]=L;
	l=0,r=L;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(solve(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",l-1);
	return 0;
}
/*
25 5 2
2
11
14
17
21
*/
