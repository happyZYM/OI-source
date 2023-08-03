#include<cstdio>
int n,a[15],len;
int gcd(int a,int b)
{return b==0?a:gcd(b,a%b);}
struct node
{
	int v;
	node *next;
	node()
	{
		v=-1;
		next=0;
	}
};
node* group[15],*p,*t;
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++) scanf("%d",a+i);
	len=1;
	group[0]=new node;
	group[0]->v=a[0];
	for(i=1;i<n;i++)
	{
		for(j=0;j<len;j++)
		{
			p=group[j];
			while(p!=0)
			{
				if(gcd(p->v,a[i])>1) goto addr1;
				p=p->next;
			}
			t=new node;
			t->v=a[i];
			t->next=group[j];
			group[j]=t;
			goto allright;
			addr1:;
		}
		group[len]=new node;
		group[len++]->v=a[i];
		allright:;
	}
	printf("%d\n",len);
	return 0;
}
