#include<iostream>
#include<algorithm>
using namespace std;
int temp[5000], edge[505][505], k;
int maxn, minn;
void dfs(int v)
{
	for(int i=minn;i<=maxn;i++)
		if(edge[v][i])
		{
			edge[v][i]--;
			edge[i][v]--;
			dfs(i);
		}
	temp[k++]=v;
}
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	int first_point,second_point,i,edge_num;
	cin>>edge_num;
	minn=505;
	maxn=0;
	k=0;
	for(i=0;i<edge_num;i++)
	{
		cin>>first_point>>second_point;
		edge[first_point][second_point] ++;
		edge[second_point][first_point] ++;
		edge[first_point][0] ++;
		edge[second_point][0] ++;
		minn = min(minn,min(first_point,second_point));
		maxn = max(maxn,max(first_point,second_point));
	}
	for(i = minn; i <= maxn; i ++)
		if(edge[i][0]%2)
		{
			dfs(i);
			break;
		}
	if(i==maxn+1) dfs(1);
	for(int j=k-1;j>=0;j--)
		printf("%d\n",temp[j]);
	return 0;
}
