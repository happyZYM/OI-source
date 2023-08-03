#include<cstdio>
using namespace std;
int main()
{
	int k,one=0,five=0,ten=0,x;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d",&x);
		if(x==1) one++;
		if(x==5) five++;
		if(x==10) ten++;
	}
	printf("%d\n%d\n%d\n",one,five,ten);
	return 0;
}

