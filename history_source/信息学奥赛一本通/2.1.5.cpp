//#include<algorithm>
//#include<ctime>
using namespace std;
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
struct bigNum
{
	static const int BASE=100000000,SIZE=8;
	vector<int>num;
	void clear()
	{
		while(num[0]==0&&num.size()>1) num.erase(num.begin());
		if(num.size()==0) num.push_back(0);
	}
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
	bool operator==(bigNum b)
	{
		bigNum a;
		a.num=num;
		a.clear();
		b.clear();
		if(a.num==b.num) return 1;
		return 0;
	}
	bigNum operator+(bigNum b)
	{
		bigNum a;
		a.num=num;
		a.clear();
		b.clear();
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
		a.clear();
		return a;
	}
	bigNum operator*(int b)
	{
		bigNum a;
		a.num=num;
		a.clear();
		long long add,j=0;
		for(int i=a.num.size()-1;i>=0;i--)
		{
			add=(long long)a.num[i]*b+j;
			j=add/BASE;
			add=add%BASE;
			a.num[i]=add;
		}
		if(j) a.num.insert(a.num.begin(),j);
		a.clear();
		return a;
	}
};
ostream& operator<<(ostream &a,bigNum b)
{
	b.clear();
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
	bigNum ans;
	ans="1";
	int n;
	cin>>n;
//	int runTime=clock();
	for(int i=1;i<=n;i++) ans=ans*i;
	cout<<ans<<endl;
//	cout<<"time used "<<clock()-runTime<<" ms"<<endl;
	return 0;
}
