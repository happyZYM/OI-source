#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=40010;
const int x=33;
int n,m,pos;
unsigned long long H[maxn],xp[maxn],hsh[maxn];
int rnk[maxn];
int cmp(int a,int b)
{
	return hsh[a]<hsh[b]||(hsh[a]==hsh[b]&&a<b);
}
int possible(int L)
{
	int c=0;
	pos=-1;
	for(int i=0;i<n-L+1;i++)
	{
		rnk[i]=i;
		hsh[i]=H[i]-H[i+L]*xp[L];
	}
	sort(rnk,rnk+n-L+1,cmp);
	for(int i=0;i<n-L+1;i++)
	{
		if(i==0||hsh[rnk[i]]!=hsh[rnk[i-1]]) c=0;
		if(++c>=m) pos=max(pos,rnk[i]);
	}
	return pos>=0;
}
char s[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	xp[0]=1;
	for(int i=1;i<maxn;i++) xp[i]=xp[i-1]*x;
	while(scanf("%d",&m)==1&&m)
	{
		scanf("%s",s);
		n=strlen(s);
		H[n]=0;
		for(int i=n-1;i>=0;i--) H[i]=H[i+1]*x+s[i]-'a';
		if(!possible(1)) printf("none\n");
		else
		{
			int L=1,R=n+1;
			while(R-L>1)
			{
				int M=(L+R)/2;
				if(possible(M)) L=M;
				else R=M;
			}
			possible(L);
			printf("%d %d\n",L,pos);
		}
	}
	return 0;
}
