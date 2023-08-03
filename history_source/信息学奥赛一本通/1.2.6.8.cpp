#include<iostream>
using namespace std;
#include<vector> 
#include<cmath> 
#include<string>
struct bigNum
{
	vector<unsigned int> num;
	static const unsigned int BASE=100000000,W=8;//进位制(100000000进制) 
	void clear(int size)
	{
		if(num.size()==0) num.push_back(0);
		while(num[0]==0&&num.size()-size>0) num.erase(num.begin());
	} 
	bigNum operator=(string sr)//用字符串赋值 
	{
		num.clear();
		for(int i=0;i<sr.size();i++)
		{
			if(i%W==0) num.insert(num.begin(),0);
			num[0]=num[0]+(sr[sr.size()-1-i]-'0')*pow(10,i%W);
		}
		bigNum a;
		a.num=num;
		a.clear(0);
		return a;
	}
	bigNum operator+(bigNum b)
	{
		bigNum ans;
		ans.num=num;
		if(ans.num.size()<b.num.size())//确保ans的位数大于或等于b的位数 
		{
			bigNum li;
			li=ans;
			ans=b;
			b=li;
		}
		unsigned long long j=0;
		for(int ai=ans.num.size()-1,bi=b.num.size()-1;bi>=0;ai--,bi--)
		{
			j=ans.num[ai]+b.num[bi]+j;
			ans.num[ai]=j%BASE;//进位 
			j/=BASE;
		}
		if(j>0)
		{
			for(int ai=ans.num.size()-b.num.size()-1;ai>=0;ai--)
			{
				j=ans.num[ai]+j;
				ans.num[ai]=j%BASE;
			    j/=BASE;
			}
		}//处理连续进位 
		if(j>0) ans.num.insert(ans.num.begin(),1);//进位
		return ans;
	}
};
istream& operator>>(istream &in,bigNum& x)//定义输入流 
{
	string s;
	char li;
	in.get(li);
	while(li>='0'&&li<='9')//保证不读取非法字符 
	{
		s+=li;
		in.get(li);
	}
	x=s;//利用字符串赋值 
	return in;
}
ostream& operator<<(ostream &out,const bigNum &x)//定义输出流 
{
	out<<x.num[0];
	for(int i=1;i<x.num.size();i++)//确保有8位 
	{
		if(x.num[i]<10) out<<"0000000";
		else if(x.num[i]<100) out<<"000000";
		else if(x.num[i]<1000) out<<"00000";
		else if(x.num[i]<10000) out<<"0000";
		else if(x.num[i]<100000) out<<"000";
		else if(x.num[i]<1000000) out<<"00";
		else if(x.num[i]<10000000) out<<"0";
		out<<x.num[i];
	}
	return out;
}
bigNum str_big(string sr)
{
	bigNum ans;
	ans=sr;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	bigNum ans;
	ans="1";
	for(int i=0;i<n;i++) ans=ans+ans;
	cout<<ans<<endl;
	return 0;
}
