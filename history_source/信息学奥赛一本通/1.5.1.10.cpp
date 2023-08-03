#include<cstdio>
using namespace std;
bool check(int lesson[7])
{
	for(int i=0;i<7;i++) if(lesson[i]>8) return 0;
	return 1;
}
int main()
{
	int lesson[7],a,b;
	for(int i=0;i<7;i++)
	{
		scanf("%d%d",&a,&b);
		lesson[i]=a+b;
	} 
	if(check(lesson)) printf("0\n");
	else
	{
		int max=0;
		for(int i=1;i<7;i++) if(lesson[i]>lesson[max]) max=i;
		printf("%d\n",max+1);
	} 
	return 0;
}

