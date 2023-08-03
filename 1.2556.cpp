#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=80005;
int n,a[maxn],b[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n); n/=8;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		for(int j=0;j<8;j++)
			b[i*8+j]=(a[i]&(1<<(7-j)))>>(7-j);
//	for(int i=0;i<n*8;i++) printf("%d",b[i]); printf("\n");
	int v=b[0],len=1;
	for(int i=1;i<n*8;i++)
	{
		if(b[i]==v) len++;
		else
		{
			printf("%d ",v*128+len);
			v=b[i];
			len=1;
		}
	}
	printf("%d\n",v*128+len);
	return 0;
}
