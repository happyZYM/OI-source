#include<cstdio>
#include<cstring>
#define maxn 205
struct node
{
	int len,num[maxn];
	node()
	{
		len=1;
		memset(num,0,sizeof(num));
		num[1]=0;
	}
};
inline int max(int a,int b)
{return a>b?a:b;}
void print(node &p)
{
	static int i;
	for(i=p.len;i>0;i--) printf("%d",p.num[i]);
	printf("\n");
}
void plus(node &a,node &b,node &c)
{
	c.len=max(a.len,b.len);
	static int i;
	memset(c.num,0,sizeof(c.num));
	for(i=1;i<=c.len;i++) c.num[i]+=c.num[i-1]/10,c.num[i-1]%=10,c.num[i]+=a.num[i]+b.num[i];
	if(c.num[c.len]>=10) c.len++,c.num[c.len]+=c.num[c.len-1]/10,c.num[c.len-1]%=10;
}
void times(node &a,node &b,node &c)
{
	c.len=a.len+b.len-1;
	static int i,j;
	memset(c.num,0,sizeof(c.num));
	for(i=1;i<=a.len;i++)
		for(j=1;j<=b.len;j++)
			c.num[i+j-1]+=a.num[i]*b.num[j];
	for(i=1;i<=c.len;i++) c.num[i+1]+=c.num[i]/10,c.num[i]%=10;
	if(c.num[c.len+1]>0) c.len++;
}
int main()
{
	int n,sum=1;
	node i,one,p,c,ans;
	one.num[1]=1;
	p=i=one;
	scanf("%d",&n);
	for(;sum<=n;sum++)
	{
		times(i,p,c);
		p=c;
		plus(one,i,c);
		i=c;
		plus(p,ans,c);
		ans=c;
	}
	print(ans);
	return 0;
}
