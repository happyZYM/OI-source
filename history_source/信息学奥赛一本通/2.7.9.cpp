#include<cstdio>
int n,k,s;
int len[10005];
int main()
{
	scanf("%d%d",&n,&k);
	double x;
	int L=0,R=0,mid;
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&x);
		len[i]=x*100;
		R=(R>len[i]?R:len[i]);
	}
	R++;
	while(L+1<R)
	{
		mid=(L+R)/2;
		s=0;
		for(int i=0;i<n;i++)
			s+=len[i]/mid;
		if(s>=k) L=mid;
		else R=mid;
	}
	printf("%.2lf\n",(double)L/100);
	return 0;
}
/*
4 11
8.02
7.43
4.57
5.39
*/
