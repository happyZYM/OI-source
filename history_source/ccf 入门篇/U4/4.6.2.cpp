#include<iostream>
#include<cmath>
using namespace std;
int n;
void pai(int &x,int &y)
{
	while(x>0&&y>0)
	{
		x--;
		y--;
	}
}
void pai2(int &x,int &y)
{
	while(x<=n&&y>0) 
	{
		x++;
		y--;
	}
}
int main()
{
	int i,j,xx,yy;
	while(true)
	{
		cin>>n>>i>>j;
		for(int x=1;x<=n;x++) cout<<"("<<i<<","<<x<<") ";
		cout<<endl;
		for(int x=1;x<=n;x++) cout<<"("<<x<<","<<j<<") ";
		cout<<endl;
		xx=j;
		yy=i;
		pai(xx,yy);
		for(int ii=1;ii+xx<=n&&ii+yy<=n;ii++) cout<<"("<<ii+yy<<","<<ii+xx<<") ";
		xx=j;
		yy=i;
		pai2(xx,yy);
		cout<<endl;
		for(int ii=1;xx-ii>0&&ii+yy<=n;ii++)  cout<<"("<<xx-ii<<","<<ii+yy<<") ";
		cout<<endl;
	}
}
