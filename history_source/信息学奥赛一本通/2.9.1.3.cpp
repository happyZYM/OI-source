#include<stdio.h>
#include<string.h>
using namespace std;
int q,h[1005],s[1005],n[1005],ans=0,maxx=0,i,j,b,m;
int main()
{
	scanf("%d",&q);
	for(i=1;i<=q;i++) scanf("%d",h+i);
	for(i=1;i<=q;i++) s[i]=1;
	for(i=1;i<=q;i++)
	{
		for(j=1;j<=i;j++) if(h[j]<h[i]) s[i]=s[i]>s[j]+1?s[i]:s[j]+1;
		b=0;
		memset(n,0,sizeof(n));
		for(j=i;j<=q;j++)
		{
			for(m=i;m<=j;m++) if(h[m]>h[j]) n[j]=n[j]>n[m]+1?n[j]:n[m]+1;
			b=b>n[j]?b:n[j];
		}
		ans=ans>s[i]+b?ans:s[i]+b;
	}
	printf("%d\n",ans);
	return 0;
}
