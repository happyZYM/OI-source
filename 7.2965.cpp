#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int p[1<<17];
char a[5][5],b[5][5];
#define fli(x) (x)^=1
inline bool ok(int st)
{
	memcpy(b,a,sizeof(b));
	while(st)
	{
		int i=p[st&-st]>>2,j=p[st&-st]&3;
		for(int k=0;k<4;k++) fli(b[i][k]);
		for(int k=0;k<4;k++) fli(b[k][j]);
		fli(b[i][j]);
		st-=st&-st;
	}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if(b[i][j]) return false;
	return true;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=0;i<16;i++) p[1<<i]=i;
	for(int i=0;i<4;i++)
	{
		scanf("%s",a[i]);
		for(int j=0;j<4;j++) a[i][j]=(a[i][j]=='+');
	}
	int res=(1<<16)-1;
	for(int st=0;st<(1<<16);st++) if(__builtin_popcount(st)<__builtin_popcount(res)&&ok(st)) res=st;
	printf("%d\n",__builtin_popcount(res));
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
		if((res>>(i*4+j))&1) printf("%d %d\n",i+1,j+1);
	return 0;
}
