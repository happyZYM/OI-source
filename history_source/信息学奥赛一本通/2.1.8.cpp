#include<ctime>
using namespace std;
#include<iostream>
#include<string>
#include<vector>
int yu;
namespace bigNumF
{
	int mi;
}
struct bigNum
{
	static const int BASE=100000000,SIZE=8;
	vector<int>num;
/*	void clear()
	{
		while(num[0]==0&&num.size()>1) num.erase(num.begin());
		if(num.size()==0) num.push_back(0);
	}*/
	bigNum operator=(string b)
	{
		num.clear();
		bigNumF::mi=1;
		for(int i=0;i<b.size();i++)
		{
			if(bigNumF::mi==BASE) bigNumF::mi=1;
			if(i%SIZE==0) num.insert(num.begin(),0);
			num[0]+=(b[b.size()-1-i]-'0')*bigNumF::mi;
			bigNumF::mi*=10;
		}
		while(num[0]==0&&num.size()>1) num.erase(num.begin());
	}
	void operator/(int b)
	{
		int x;
		bool f=1;
		long long add=0;
		for(int i=0;i<num.size();i++)
		{
			add=add*BASE+num[i];
			x=(add/b)%BASE;
			if(x==0)
			{
				if(i==num.size()-1) cout<<x;
			}
			else
			{
				if(f)
				{
					cout<<x;
					f=0;
				}
				else
				{
					if(x<10) cout<<"0000000";
					else if(x<100) cout<<"000000";
					else if(x<1000) cout<<"00000";
					else if(x<10000) cout<<"0000";
					else if(x<100000) cout<<"000";
					else if(x<1000000) cout<<"00";
					else if(x<10000000) cout<<"0";
					cout<<x; 
				}
			}
			add=add%b;
		}
		yu=add;
	}
};
istream& operator>>(istream &a,bigNum &b)
{
	char x;
	string zhuan;
	while(a.get(x),x>='0'&&x<='9') zhuan+=x;
	b=zhuan;
	return a;
}
int main()
{
	ios::sync_with_stdio(false); 
	string x;
	bigNum a;
	cin>>x;
	a=x;
//	int runTime=clock();
	a/13;
	cout<<endl<<yu<<endl;
//	cout<<"time used "<<clock()-runTime<<" ms"<<endl; 
	return 0;
}
//9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
