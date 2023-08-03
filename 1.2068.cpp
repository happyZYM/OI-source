#include<cstdio>
const int maxn=100005;
int n,m,c[maxn];
void Add(int p,int v)
{
	for(;p<=n;p+=(p&-p)) c[p]+=v;
}
int Sum(int p)
{
	int res=0;
	for(;p;p-=(p&-p)) res+=c[p];
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	while(m-->0)
	{
		char op[2]; int a,b; scanf("%s%d%d",op,&a,&b);
		if(op[0]=='x') Add(a,b);
		else printf("%d\n",Sum(b)-Sum(a-1));
	}
	return 0;
}