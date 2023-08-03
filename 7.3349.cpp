#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100005;
int n,tot,P=99991,snow[maxn][6],head[maxn],nxt[maxn];
inline int hsh(int *a)
{
	int s=0,t=1;
	for(int i=0;i<6;i++)
	{
		s=(s+a[i])%P;
		t=(long long)t*a[i]%P;
	}
	return (s+t)%P;
}
inline bool equal(int *a,int *b)
{
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
		{
			bool eq=1;
			for(int k=0;k<6;k++)
				if(a[(i+k)%6]!=b[(j+k)%6]) { eq=0; break; }
			if(eq) return 1;
			eq=1;
			for(int k=0;k<6;k++)
				if(a[(i+k)%6]!=b[(j-k+6)%6]) { eq=0; break; }
			if(eq) return 1;
		}
	return 0;
}
inline bool insert(int *a)
{
	int val=hsh(a);
	for(int i=head[val];i;i=nxt[i])
		if(equal(snow[i],a)) return 1;
	++tot;
	memcpy(snow[tot],a,24);
	nxt[tot]=head[val];
	head[val]=tot;
	return 0;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a[10]; for(int j=0;j<6;j++) scanf("%d",&a[j]);
		if(insert(a))
		{
			puts("Twin snowflakes found.");
			return 0;
		}
	}
	puts("No two snowflakes are alike.");
	return 0;
}
