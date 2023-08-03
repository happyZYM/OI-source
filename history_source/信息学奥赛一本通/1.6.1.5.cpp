#include<cstdio>
#include<cstring>
using namespace std;
bool isc_(int *front,int *last,int n)
{
	int *i;
	i=front; 
	for(;i<last;i++)
		if(*i==n) return 1;
	return 0;
}
int main()
{
	int m,n,diary[1200],front=0,last=0,ans=0,x;
	memset(diary,-1,1200);
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		if(!isc_(diary+front,diary+last,x))
		{
			diary[last++]=x;
			if(last-front>m) front++;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
