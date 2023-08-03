#include<cstdio>
using namespace std;
double poeple[4];
void read(int n)
{
	if(n>=0&&n<=18) poeple[0]++;
	if(n>=19&&n<=35) poeple[1]++;
	if(n>=36&&n<=60) poeple[2]++;
	if(n>=61&&n<=100) poeple[3]++;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		read(x);
	}
	for(int i=0;i<4;i++)
	{
		printf("%.2lf%c\n",poeple[i]*100/n,'%');
	}
	return 0;
}

