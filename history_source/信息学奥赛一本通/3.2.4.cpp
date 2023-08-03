#include<cstdio>
int father[101],sum[101],p=1;
int find(int x)
{
	while(father[x]!=x) x=father[x];
	return x;
}
void unionn(int x,int y)
{
	x=find(x);
	y=find(y);
	father[y]=x;
	sum[x]+=sum[y];
	if(sum[x]>p) p=sum[x];
}
int main()
{
	for(int i=0;i<101;i++) 
	{
		father[i]=i;
		sum[i]=1;
	}
	int n,k;
	int minus=0;
	scanf("%d%d",&n,&k);
	int a,b,l1,l2;
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&a,&b);
		l1=find(a);
		l2=find(b);
		if(l1!=l2) 
		{
			unionn(l1,l2);
			minus++;
		}
	}
	printf("%d %d\n",n-minus,p);
	return 0;
}
