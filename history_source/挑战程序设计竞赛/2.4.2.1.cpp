#include<bits/stdc++.h>
using namespace std;
int L,P,N;
int A[10001],B[10001];
void solve()
{
	A[N]=L;
	B[N]=0;
	N++;
	priority_queue<int>que;
	int ans=0,pos=0,tank=P;
	for(int i=0;i<N;i++)
	{
		int d=A[i]-pos;
		while(tank-d<0)
		{
			if(que.empty())
			{
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		tank-=d;
		pos=A[i];
		que.push(B[i]);
	}
	printf("%d\n",ans);
}
void init()
{
	scanf("%d%d%d",&N,&L,&P);
	int i;
	for(i=0;i<N;i++) scanf("%d",A+i);
	for(i=0;i<N;i++) scanf("%d",B+i); 
}
int main()
{
	init();
	solve();
	return 0;
}
/*
4 25 10
10 14 20 21
10 5 2 4
*/
