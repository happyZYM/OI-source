#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char *a=new char[105],*b=new char[105];
int n1,n2,x,y;
bool ok(int pos)
{
	for(int i=pos;i<n1&&i<n2+pos;i++)
		if(a[i]-'0'+b[i-pos]-'0'>3) return false;
	return true;
}
int main()
{
#define NDEBUG
#ifdef local
	freopen("pro.in","r",stdin);
	#undef NDEBUG
#endif
	while(scanf("%s%s",a,b)==2)
	{
		n1=strlen(a);
		n2=strlen(b);
		for(int i=0;i<=n1;i++)
			if(ok(i))
			{
				x=max(n1,n2+i);
				break;
			}
		swap(a,b);
		swap(n1,n2);
		for(int i=0;i<=n1;i++)
			if(ok(i))
			{
				y=max(n1,n2+i);
				break;
			}
		printf("%d\n",min(x,y));
	}
	return 0;
}
