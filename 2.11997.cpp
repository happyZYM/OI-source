#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct Item
{
	int s,b;
	Item(int s,int b):s(s),b(b){}
	inline bool operator<(const Item &r) const
	{
		return s>r.s;
	}
};
void pro(int *A,int *B,int *C,int n)
{
	priority_queue<Item> q;
	for(int i=0;i<n;i++)
		q.push(Item(A[i]+B[0],0));
	for(int i=0;i<n;i++)
	{
		Item item=q.top();q.pop();
		C[i]=item.s;
		int b=item.b;
		if(b+1<n) q.push(Item(item.s-B[b]+B[b+1],b+1));
	}
}
const int maxn=770;
int n,A[maxn][maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
			sort(A[i],A[i]+n);
		}
		for(int i=1;i<n;i++)
			pro(A[0],A[i],A[0],n);
		printf("%d",A[0][0]);
		for(int i=1;i<n;i++)
			printf(" %d",A[0][i]);
		printf("\n");
	}
	return 0;
}
