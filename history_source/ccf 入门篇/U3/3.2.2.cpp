#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int g;
	while(true)
	{
		cin>>g;
		if(!(g>30))
		{
			if(g<=10) cout<<"需要 "<<0.8*g<<"元"<<endl;
			if(g>10&&g<=20) cout<<"需要 "<<0.75*g<<"元"<<endl;
			if(g>20&&g<=30) cout<<"需要 "<<0.7*g<<"元"<<endl;
		}
		else cout<<"无法邮寄！"<<endl;
	}
}
