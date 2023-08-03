#include<cstdio>
using namespace std;
bool isp[110];
void f(int n)
{
	for(int i=2,j=n-2;i<=n-2&&j>=2;i++,j--)
		if(isp[i]&&isp[j])
			printf("%d=%d+%d\n",n,i,j);
}
int main()
{
	for(int i=0;i<110;i++) isp[i]=1;
	isp[0]=isp[1]=0;
	for(int i=2;i<110;i++)
		for(int j=2;i*j<110;j++)
			isp[i*j]=0;
	for(int i=6;i<=100;i+=2)
		f(i);
	return 0;
}
