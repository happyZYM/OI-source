#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
double L,D;
int n,res;
map<double,double> mp;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%lf",&L)==1)
	{
		scanf("%lf%d",&D,&n);
		mp.clear();
		double x,y;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			double &t=mp[x];
			if(abs(y)>t) t=abs(y);
		}
		double now=-1000000;
		res=0;
		for(auto it=mp.begin();it!=mp.end();it++)
			//        y*y+x*x
			if(sqrt(it->second*it->second
			+abs(now-it->first)*abs(now-it->first))>D)
			{
				//        x+sqrt(D*D-x*x)
				now=it->first+sqrt(D*D-(it->second*it->second));
				res++;
			}
		printf("%d\n",res);
	}
	return 0;
}
