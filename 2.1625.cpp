#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5000+5;
const int oo=1<<30;
char p[maxn],q[maxn];
int sp[26],sq[26],ep[26],eq[26];
int d[2][maxn],c[2][maxn];
int i,j,v1,v2,t,n,m;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",p+1,q+1);
		n=strlen(p+1);
		m=strlen(q+1);
		for(i=1;i<=n;i++) p[i]-='A';
		for(i=1;i<=m;i++) q[i]-='A';
		for(i=0;i<26;i++){sp[i]=sq[i]=oo; ep[i]=eq[i]=0;}
		for(i=1;i<=n;i++)
		{
			sp[p[i]]=min(sp[p[i]],i);
			ep[p[i]]=i;
		}
		for(i=1;i<=m;i++)
		{
			sq[q[i]]=min(sq[q[i]],i);
			eq[q[i]]=i;
		}
		
		t=0;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(!i&&!j) continue;
				
				v1=oo,v2=oo;
				if(i) v1=d[t^1][j]+c[t^1][j];//p
				if(j) v2=d[t][j-1]+c[t][j-1];//q
				d[t][j]=min(v1,v2);
				if(i)
				{
					c[t][j]=c[t^1][j];
					if(sp[p[i]]==i&&sq[p[i]]>j) c[t][j]++;
					if(ep[p[i]]==i&&eq[p[i]]<=j) c[t][j]--;
				}
				else if(j)
				{
					c[t][j]=c[t][j-1];
					if(sq[q[j]]==j&&sp[q[j]]>i) c[t][j]++;
					if(eq[q[j]]==j&&ep[q[j]]<=i) c[t][j]--;
				}
			}
			t^=1;
		}
		printf("%d\n",d[t^1][m]);
	}
	return 0;
}
