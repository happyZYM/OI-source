#include<iostream>
using namespace std;
struct ditan
{
	int x,y,xa,ya;
};
bool f(ditan t,int x,int y)
{
	if(t.x<=x&&t.x+t.xa>=x&&t.y<=y&&t.y+t.ya>=y) return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	ditan d[n];
	for(int i=0;i<n;i++) cin>>d[i].x>>d[i].y>>d[i].xa>>d[i].ya;
	int x,y;
	cin>>x>>y;
	int ans=-2;
	for(int i=0;i<n;i++)
		if(f(d[i],x,y)) ans=i;
	cout<<ans+1<<endl;
	return 0;
}

