#include<iostream>
using namespace std;
int zd(int a,int b)
{
	int ans=1;
	for(int i=2;i<=(a<b?a:b);i++) if(a%i==0&&b%i==0) ans=i;
	return ans;
}
int zx(int a,int b)
{
	return a*b/zd(a,b);
}
int main()
{
	int answer,x,y,p,q;
	while(true)
	{
		answer=0;
		cin>>x>>y;
		for(p=x;p<=y;p++)
		{
			for(q=x;q<=y;q++) if(zd(p,q)==x&&zx(p,q)==y) answer++;
		}
		cout<<answer<<endl;
	}
}
