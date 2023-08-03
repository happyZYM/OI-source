#include<cstdio>
#define maxn 1000
int fa[maxn+1],size[maxn+1],dan=1,sum,n,s,a,k;
int tu[maxn+1][maxn+1],num[maxn+1];
inline int max(int aa,int bb)
{return aa>bb?aa:bb;}
int ff(int a)
{
	static int t1,t2;
	t1=a;
	while(fa[a]!=a) a=fa[a];
	while(t1!=a)
	{
		t2=fa[t1];
		fa[t1]=a;
		t1=t2;
	}
	return a;
}
void un(int a,int b)
{
	static int aa,bb;
	aa=ff(a);
	bb=ff(b);
	if(aa!=bb)
	{
		fa[bb]=aa;
		size[aa]+=size[bb];
		dan=max(dan,size[aa]);
	}
}
int main()
{
	freopen("black.in","r",stdin);
	freopen("black.out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) fa[i]=i,size[i]=1;
	sum=n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s);
		for(j=0;j<s;j++)
		{
			scanf("%d",&a);
			tu[i][num[i]++]=a;
			tu[a][num[a]++]=i;
		}
	}
	k=n;
	while(dan<=n/2)
	{
		k--;
		for(i=0;i<num[k+1];i++)
			if(tu[k+1][i]>k) un(k+1,tu[k+1][i]);
	}
	printf("%d\n",k+1);
	return 0;
}
/*
7
2 2 5
3 1 3 4
2 2 4
2 2 3
3 1 6 7
2 5 7
2 5 6
*/
