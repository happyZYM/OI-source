#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define BASE 100000000
#define SIZE 8
using namespace std;
struct bigNum
{
	vector<int>num;
	bigNum operator=(string b)
	{
		num.clear();
		for(int i=0;i<b.size();i++)
		{
			if(i%SIZE==0) num.insert(num.begin(),0);
			num[0]+=(b[b.size()-1-i]-'0')*pow(10,i%SIZE);
		}
		while(num[0]==0&&num.size()>1) num.erase(num.begin());
	}
	bigNum operator+(bigNum b)
	{
		bigNum a;
		a.num=num;
		if(a.num.size()<b.num.size())
		{
			bigNum c=a;
			a=b;
			b=c;
		}
		int ai,bi;
		int j=0;
		for(ai=a.num.size()-1,bi=b.num.size()-1;bi>=0;ai--,bi--)
		{
			a.num[ai]=a.num[ai]+b.num[bi]+j;
			j=a.num[ai]/BASE;
			a.num[ai]=a.num[ai]%BASE;
		}
		while(ai>=0&&j)
		{
			a.num[ai]+=j;
			j=a.num[ai]/BASE;
			a.num[ai]=a.num[ai]%BASE;
			ai--;
		}
		if(j) a.num.insert(a.num.begin(),1);
		return a;
	}
};
ostream& operator<<(ostream &a,bigNum b)
{
	a<<b.num[0];
	int x;
	for(int i=1;i<b.num.size();i++)
	{
		x=b.num[i];
		if(x<10) a<<"0000000";
		else if(x<100) a<<"000000";
		else if(x<1000) a<<"00000";
		else if(x<10000) a<<"0000";
		else if(x<100000) a<<"000";
		else if(x<1000000) a<<"00";
		else if(x<10000000) a<<"0";
		a<<x; 
	}
	return a;
}
int main()
{
    int n;
    cin>>n;
    bigNum ans[n];
    bigNum a,b;
    string x;
    for(int i=0;i<n;i++)
    {
    	cin>>x;
    	a=x;
    	cin>>x;
    	b=x;
    	ans[i]=a+b; 
	}
	for(int i=0;i<n;i++) cout<<ans[i]<<endl;
	return 0;
} 
