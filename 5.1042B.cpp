#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mem[2][8],*dp,*la;
int n,c,st;
char vit[10];
char* gtv(int j)
{
	char *s=new char[10];
	char *res=s;
	if(j&1) *s++='A';
	if(j&2) *s++='B';
	if(j&4) *s++='C';
	*s=0;
	return res;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	memset(mem,0x3f,sizeof(mem));
	dp=mem[0]; la=mem[1];
	la[0]=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%s",&c,vit);
		st=0;
		for(char *it=vit;*it;it++) st|=1<<(*it-'A');
		memcpy(dp,la,sizeof(mem)/2);
		for(int j=0;j<8;j++)
			dp[j|st]=min(dp[j|st],min(la[j|st],la[j]+c));
//		printf("i=%d st=%s c=%d\n",i,gtv(st),c);
//		for(int j=0;j<8;j++) printf("dp[%s]=%d ",gtv(j),dp[j]);
//		printf("\n");
		swap(dp,la);
	}
	printf("%d\n",la[7]==0x3f3f3f3f?-1:la[7]);
	return 0;
}
