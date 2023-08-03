#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int n,s,q,h;
int a[1005],x[1005];
bool is_stk()
{
	stack<int> stk;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) stk.push(x[i]);
		else
		{
			if(stk.empty()) return false;
			if(x[i]!=stk.top()) return false;
			stk.pop();
		}
	}
	return true;
}
bool is_que()
{
	queue<int> que;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) que.push(x[i]);
		else
		{
			if(que.empty()) return false;
			if(x[i]!=que.front()) return false;
			que.pop();
		}
	}
	return true;
}
bool is_heap()
{
	priority_queue<int> heap;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) heap.push(x[i]);
		else
		{
			if(heap.empty()) return false;
			if(x[i]!=heap.top()) return false;
			heap.pop();
		}
	}
	return true;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1)
	{
		stack<int> stk;
		queue<int> que;
		priority_queue<int> heap;
		for(int i=0;i<n;i++)
			scanf("%d%d",a+i,x+i);
		s=is_stk();q=is_que();h=is_heap();
		if(s+q+h>=2) printf("not sure\n");
		else if(s) printf("stack\n");
		else if(q) printf("queue\n");
		else if(h) printf("priority queue\n");
		else printf("impossible\n");
	}
	return 0;
}
