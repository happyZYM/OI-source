#include<cstdio>
using namespace std;
double abs(double n)
{
	if(n<0) n=-n;
	return n;
}
int main()
{
	int n;
	scanf("%d",&n);
	double bai[n];
	double max,min,add;
	scanf("%lf",bai);
	add=max=min=bai[0];
	for(int i=1;i<n;i++)
	{
		scanf("%lf",bai+i);
		if(bai[i]>max) max=bai[i];
		if(bai[i]<min) min=bai[i];
		add+=bai[i];
	}
	double p=(add-max-min)/(n-2);
	printf("%.2lf ",p);
	double maxn;
	int i=0;
	while(bai[i]==max||bai[i]==min) i++;
	maxn=abs(p-bai[i]);
	i++;
	for(;i<n;i++)
	{
		if(abs(p-bai[i])>maxn&&bai[i]!=max&&bai[i]!=min) maxn=abs(p-bai[i]);
	}
	printf("%.2lf\n",maxn);
	return 0;
}

