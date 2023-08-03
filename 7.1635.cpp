#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
const int maxn=10005;
int T,n; char a[maxn],b[maxn],*p;
ULL h[maxn];
const ULL md=1287349021931ull;
ULL hsh(int d)
{
	ULL s=h[d];
	while(*p!=0&&*p++=='0') s=(s+hsh(d+1)*h[d])%md;
	return s*s%md;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
//	freopen("pro.out","w",stdout);
#endif
	srand(131);
	scanf("%d",&T);
	for(int i=0;i<10000;i++) h[i]=((((ULL)rand()*(ULL)rand()+(ULL)rand())*(ULL)rand()+(ULL)rand())*(ULL)rand()+(ULL)rand())%md;
	while(T-->0)
	{
		scanf("%s%s",a,b);
		if(strlen(a)!=strlen(b)) { puts("different"); continue; }
		p=a; ULL ha=hsh(1);
		p=b; ULL hb=hsh(1);
//		cout<<"ha="<<ha<<" hb="<<hb<<endl;
		puts(ha==hb?"same":"different");
	}
	return 0;
}
