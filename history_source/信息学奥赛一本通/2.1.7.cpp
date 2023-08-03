#include<cstdio>
#include<cstring>
#define maxn 405
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
void print(node &p)
{
	static int i;
	for(i=p.len;i>0;i--) printf("%d",p.num[i]);
	printf("\n");
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
void input(node &a)
{
	static char str[maxn];
	static int i;
	scanf("%s",str);
	a.len=strlen(str);
	for(i=1;i<=a.len;i++) a.num[i]=str[a.len-i]-'0';
}
int main()
{
	node a,b,c;
	input(a);
	input(b);
	times(a,b,c);
	print(c);
	return 0;
}
