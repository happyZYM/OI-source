#include<iostream>
using namespace std;
struct con
{
	int a,b;
};
con *cont;int len;
template<class T_fsort>
void fsort(T_fsort *left,T_fsort *right,bool (*cmp)(T_fsort a,T_fsort b),T_fsort *k)
{
	if(right-left<=1) return;
	unsigned int len=right-left;
	fsort(left,left+len/2,cmp,k);
	fsort(left+len/2,right,cmp,k+len/2);
	int i=0,j=len/2,n=0;
	while(i<len/2&&j<len)
	{
		if(cmp(left[i],left[j])) k[n++]=left[i++];
		else k[n++]=left[j++];
	}
	while(i<len/2) k[n++]=left[i++];
	while(j<len) k[n++]=left[j++];
	for(int i=0;i<len;i++) left[i]=k[i];
}
template<class Tb_fsort>
void fsort(Tb_fsort *left,Tb_fsort *right,bool (*cmp)(Tb_fsort a,Tb_fsort b))
{
	if(right-left<=1) return;
	unsigned int len=right-left;
	Tb_fsort k[len];
	fsort(left,right,cmp,k);
}
bool cmp(con a,con b)
{
	if(a.a<b.a) return 1;
	if(a.a>b.a) return 0;
	return a.b<b.b;
}
con* road(int a)
{
	con *left,*right,*mid;
	left=cont;
	right=cont+len;
	while(left<right)
	{
		mid=left+(right-left)/2;
		if(mid->a>a) right=mid;
		if(mid->a<a) left=mid;
		if(mid->a==a)
		{
			left=mid;
			break;
		}
	}
	if(left->a!=a) return 0;
	while(left>=cont&&left->a==a) left--;
	left++;
	return left;
}
template<class T_queue>
struct Node_queue
{
	T_queue num;
	Node_queue *next;
};
template<class a_queue>
struct queue
{
	Node_queue<a_queue> *head,*tail;
	int SIZE_queue;
	void beginning()
	{
		head=tail=new Node_queue<a_queue>;
		tail->next=head;
		SIZE_queue=0;
	}
	bool push(a_queue s)
	{
		SIZE_queue++;
		tail->num=s;
		if(tail->next==head)
		{
			tail->next=new Node_queue<a_queue>;
			tail->next->next=head;
			tail=tail->next;
			return 1;
		}
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
	a_queue front()
	{
		return head->num;
	} 
	int size()
	{
		return SIZE_queue;
	}
};
struct BFS
{
	int num;
	int step;
};
int main()
{
	int n,m,p;
	ios::sync_with_stdio(0);
	cin>>n>>m>>p;
	cont=new con[m*2+10];
	con* x;
	int u,v;
	for(int i=0;i<m;i++)
	{
		cin>>u>>v;
		cont[len].a=u;
		cont[len].b=v;
		len++;
		cont[len].b=u;
		cont[len].a=v;
		len++;
	}
	fsort(cont,cont+len,cmp);
	bool guo[n+1]={0,1};
	queue<BFS>bfs;
	bfs.beginning();
	BFS r;
	r.num=1;
	r.step=0;
	bfs.push(r);
	while(bfs.size()>0&&bfs.front().step<=p)
	{
		x=road(bfs.front().num);
		if(x!=0)
		{
			while(x->a==bfs.front().num)
			{
				if(!guo[x->b]) 
				{
					r.num=x->b;
					r.step=bfs.front().step+1;
					bfs.push(r);
					guo[x->b]=1;
				}
				x++;
			}
		}
		bfs.pop();
	}
	int ans=0;
	for(int i=0;i<n+1;i++) ans+=guo[i];
	cout<<ans<<endl;
	return 0;
}
/*
4 4 2
1 2
1 3
2 3
3 4
*/
