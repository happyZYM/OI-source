#include<cstdio>
#include<algorithm>
using namespace std;
double w;
int s;
struct Gold
{
	double g,V,prise;
};
Gold mon[110];
bool cmp(Gold a,Gold b)
{
	return a.prise>b.prise;
}
double answer()
{
	sort(mon,mon+s,cmp);
	double ans=0;
	int i=0;
	while(w>0&&i<s)
	{
		if(w>=mon[i].g)
		{
			ans+=mon[i].V;
			w-=mon[i].g;
		}
		else ans+=mon[i].prise*w,w=0;
		i++;
	}
	return ans;
}
int main()
{
	int k;
	scanf("%d",&k);
	double ans[k];
	for(int i=0;i<k;i++)
	{
		scanf("%lf%d",&w,&s);
		for(int j=0;j<s;j++) scanf("%lf%lf",&mon[j].g,&mon[j].V),mon[j].prise=mon[j].V/mon[j].g;
		ans[i]=answer();
	}
	for(int i=0;i<k;i++) printf("%.2lf\n",ans[i]);
	return 0;
}

