#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,f[128],ff[62];
char a[1005],stk[1005]; int sz=0;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int cnt=0;
	for(int i='0';i<='9';i++)
	{
		f[i]=cnt;
		ff[cnt++]=i;
	}
	for(int i='A';i<='Z';i++)
	{
		f[i]=cnt;
		ff[cnt++]=i;
	}
	for(int i='a';i<='z';i++)
	{
		f[i]=cnt;
		ff[cnt++]=i;
	}
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d%s",&n,&m,a);
		printf("%d %s\n%d ",n,a,m);
		int lena=strlen(a);
		reverse(a,a+lena);
		sz=0;
		while(lena)
		{
			int jw=0;
			for(int i=lena-1;i>=0;i--)
			{
				jw=jw*n+f[a[i]];
				a[i]=ff[jw/m];
				jw%=m;
			}
			stk[sz++]=ff[jw];
			while(lena&&a[lena-1]=='0') a[lena--]=0;
		//	printf("lena=%d %s\n",lena,a);
		}
		while(sz) putchar(stk[--sz]); puts("\n");
	}
	return 0;
}
