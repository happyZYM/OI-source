#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
void times(int a[8][8],int b[8][8],int t[8][8])
{
	memset(t,0,256);
	for(int r=0;r<8;r++) for(int c=0;c<8;c++)
	{
		for(int k=0;k<8;k++) t[r][c]+=a[r][k]*b[k][c];
		t[r][c]%=1000;
	}
}
int n;
int a[8][8]={
{0,1,0,0,0,0,0,1},
{1,0,1,0,0,0,0,0},
{0,1,0,1,0,0,0,0},
{0,0,1,0,0,0,0,0},
{0,0,0,1,0,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,1,0,1},
{1,0,0,0,0,0,1,0}
},b[8][8],c[8][8];
void ksm(int a[8][8],int b[8][8],int tmp[8][8],int n)
{
	memset(b,0,256);
	for(int i=0;i<8;i++) b[i][i]=1;
	for(;n;n>>=1)
	{
		if(n&1) { times(b,a,tmp); memcpy(b,tmp,256); }
		times(a,a,tmp); memcpy(a,tmp,256);
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	ksm(a,b,c,n);
	printf("%d\n",b[4][0]);
	return 0;
}
