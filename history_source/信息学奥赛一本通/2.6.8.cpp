#include<iostream>
#include<algorithm>
struct Point
{
	int x,y;
};
Point p[105],ans[105];
int len=0,n;
bool check(int idx)
{
	for(int i=0;i<n;i++)
		if(i!=idx)
			if(p[i].x>=p[idx].x&&p[i].y>=p[idx].y) return 0;
	return 1;
}
bool cmp(Point a,Point b)
{
	return (a.x<b.x);
}
using namespace std;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	for(int i=0;i<n;i++) if(check(i)) ans[len++]=p[i];
	sort(ans,ans+len,cmp);
	for(int i=0;i<len;i++)
	{
		if(i>0) printf(",");
		printf("(%d,%d)",ans[i].x,ans[i].y);
	}
	printf("\n");
	return 0;
}
