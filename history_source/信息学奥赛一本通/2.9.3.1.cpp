#include<cstdio>
#include<string.h>
char a[210]={'\0'},b[210]={'\0'};
int dp[201][201];
namespace myDef
{
	template<class T_queue>
	struct Node_queue
	{
		T_queue num;
		Node_queue *next=0;
	};
	template<class a_queue>
	struct queue
	{
		Node_queue<a_queue> *head=0,*tail=0,*L=0;
		bool isn=0;
		int SIZE_queue;
		void beginning()
		{
			head=tail=new Node_queue<a_queue>;
			tail->next=head;
			SIZE_queue=0;
			isn=1;
		}
		queue()
		{
			beginning();
		} 
		bool push(a_queue s)
		{
			SIZE_queue++;
			tail->num=s;
			if(tail->next==head)
			{
				tail->next=new Node_queue<a_queue>;
				tail->next->next=head;
				L=tail;
				tail=tail->next;
				return 1;
			}
			L=tail;
			tail=tail->next;
			return 0;
		}
		bool pop()
		{
			if(head==tail) return 1;
			head=head->next;
			SIZE_queue--;
			return 0;
		} 
		a_queue& front()
		{
			return head->num;
		} 
		int size()
		{
			return SIZE_queue;
		}
	};
}
using myDef::queue;
#define max(a,b) ((a)>(b)?(a):(b))
int answer()
{
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=strlen(a+1);i++)
		for(int j=1;j<=strlen(b+1);j++)
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	return dp[strlen(a+1)][strlen(b+1)];
}
int main()
{
	queue<int>ans;
	while(scanf("%s%s",a+1,b+1)==2) ans.push(answer());
	while(ans.size()>0)
	{
		printf("%d\n",ans.front());
		ans.pop();
	}
	return 0;
}
