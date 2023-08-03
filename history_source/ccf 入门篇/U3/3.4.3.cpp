#include<iostream>
#include<cmath>
using namespace std;
int y,m; 
bool p()
{
	if(y%400==0) return 1;
	if(y%100==0) return 0;
	if(y%4==0) return 1;
	return 0;
}

int main()
{
	
	while(true)
	{
		cin>>y>>m;
		switch(m)
		{
			case 1:cout<<"31days"<<endl;break;
			case 2:{
				if(p())cout<<"29days"<<endl;
				else cout<<"28days"<<endl;
				break;
			}
			case 3:cout<<"31days"<<endl;break;
			case 4:cout<<"30days"<<endl;break;
			case 5:cout<<"31days"<<endl;break;
			case 6:cout<<"30days"<<endl;break;
			case 7:cout<<"31days"<<endl;break;
			case 8:cout<<"31days"<<endl;break;
			case 9:cout<<"30days"<<endl;break;
			case 10:cout<<"31days"<<endl;break;
			case 11:cout<<"30days"<<endl;break;
			case 12:cout<<"31days"<<endl;break;
		}
		
	}
}
