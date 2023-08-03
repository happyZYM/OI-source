#include<iostream> 
#include<cmath>
using namespace std; 
int log2(int y)
{
	return log(y)/log(2);
}
void wrote(int sr)
{
	bool f=0;
	for(int i=log2(sr);sr>0;i--)
	{
		if(sr>=pow(2,i)) 
		{
			if(f) cout<<"+";
			f=1;
			cout<<"2(";
			switch(i)
			{
				case 1:cout<<"2(0)";break;
				case 2:cout<<"2";break;
				default:wrote(i);
			}
			cout<<")";
			sr-=pow(2,i);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	wrote(n);
	return 0;
}
