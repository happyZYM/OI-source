#include<iostream>
#include<vector>
using namespace std;
int main()//0-670-82162-4
{
	vector <char> sr;
	int ans,a;
	while(true)
	{
		sr.clear();
		sr.resize(13);
		for(int i=0;i<13;i++) sr[i]=getchar();
		ans=0;
		a=1;
		for(int i=0;i<12;i++)
		{
			if(sr[i]!='-') {ans=ans+(sr[i]-'0')*a;a++;}
		}
		if(ans%11<10)
		{
			if(ans%11==sr[12]-'0') cout<<"Right"<<endl;
			else 
			{
				for(int i=0;i<12;i++) cout<<sr[i];
				cout<<ans%11<<endl;
			}
		}
		else
		{
			if(sr[12]=='X') cout<<"Right"<<endl;
			else
			{
				for(int i=0;i<12;i++) cout<<sr[i];
				cout<<"X"<<endl;
			}
		}
	}
}
