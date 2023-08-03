#include<cstdio>
#include<cstring>
#include<cassert>
const int maxn=100010;
char a[maxn],b[maxn];
bool ok;
int la,lb,p1,p2;
int main()
{
#define NDEBUG
#ifdef local
	freopen("pro.in","r",stdin);
	#undef NDEBUG
#endif
	while(scanf("%s%s",a,b)==2)
	{
		ok=true;
		la=strlen(a);lb=strlen(b);
		p1=p2=0;
		while(true)
		{
			if(a[p1]==b[p2]) p1++,p2++;
			else p2++;
			if(p1>=la) goto print;
			if(p2>=lb)
			{
				ok=false;
				goto print;
			}
		}
print:
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
