#include<cstdio>
#include<cmath>
using namespace std;
int find_(int a,int b,int n)
{
	a*=pow(10,n);
	return a/b;
}
int sun[110];
bool find(int *front,int *last,int n)
{
	int *p;
	for(p=front;p<last;p++)
		if(*p==n) return 1;
	return 0;
}
int main()
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	int x=0,i=1;
	while(!find(sun,sun+x,find_(a,b,i))) x++,i++;
	printf("%d\n",x);
	return 0;
}
