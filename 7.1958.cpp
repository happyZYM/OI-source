#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f3[15],f4[15];
int main()
{
	memset(f4,0x3f,sizeof(f4));
	f3[1]=1;
	for(int i=2;i<=12;i++) f3[i]=f3[i-1]*2+1;
	f4[1]=1;
	for(int i=2;i<=12;i++) for(int j=1;j<i;j++) f4[i]=min(f4[i],2*f4[j]+f3[i-j]);
	for(int i=1;i<=12;i++) printf("%d\n",f4[i]);
	return 0;
}
