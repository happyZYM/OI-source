#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;
const int SIZE=3600;
int n,c,p;
inline void add(int a[30][30],int b[30][30],int c[30][30])
{
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) c[i][j]=(a[i][j]+b[i][j])%p;
}
inline void mul(int a[30][30],int b[30][30],int c[30][30])
{
	memset(c,0,SIZE);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		for(int k=0;k<n;k++)
			(c[i][j]+=a[i][k]*b[k][j])%=p;
}
inline void ksm(int x[30][30],int b,int c[30][30])
{
	int t[30][30],a[30][30]; memcpy(a,x,SIZE);
	memset(c,0,SIZE); for(int i=0;i<n;i++) c[i][i]=1;
	for(;b;b>>=1)
	{
		if(b&1) { mul(c,a,t); memcpy(c,t,SIZE); }
		mul(a,a,t); memcpy(a,t,SIZE);
	}
}
int a[30][30],b[30][30],e[30][30];
void f(int a[30][30],int c,int b[30][30])
{
	if(c==1) { memcpy(b,a,SIZE); return ;}
	if(c&1)
	{
		f(a,c-1,b);
		int x[30][30];
		mul(a,b,x);
		add(a,x,b);
		return;
	}
	int x[30][30],t[30][30];
	f(a,c/2,x);
	ksm(a,c/2,b);
	add(e,b,t);
	mul(t,x,b);
}
void print(int a[30][30])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",a[i][j]);
		puts("");
	}
	puts("-----------");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&c,&p);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++) e[i][i]=1;
	//print(a);
	f(a,c,b);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("%d ",b[i][j]);
		printf("\n");
	}
	return 0;
}
