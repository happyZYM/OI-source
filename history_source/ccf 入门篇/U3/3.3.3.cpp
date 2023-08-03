#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int f;
	while(true)
	{
		cin>>f;
		if(f>90) cout<<"优秀"<<endl;
		else
		{
			if(f/10==8) cout<<"良好"<<endl;
			else
			{
				if(f>=60&&f<80) cout<<"及格"<<endl;
				else cout<<"不及格"<<endl;
			}
		}
	}
}
