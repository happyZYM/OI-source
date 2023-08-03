// luogu-judger-enable-o2
#include<vector>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
int CacheSize=10;//try to use the cache
struct BigInt
{
	bool f;
	std::vector<int> num;
	static const int base=100000000;
	BigInt()
	{
		f=0;
		num.push_back(0);
	}
	void format()
	{
		while(num.size()>1&&num[num.size()-1]==0) num.erase(num.end()-1);
		if(num.size()==1&&num[0]==0) f=0;
	}
	//Input and Output
	char* c_str()
	{
		char *p;
		p=new char[num.size()*8+16];
		memset(p,0,sizeof(p));
		if(f) sprintf(p,"-");
		sprintf(p,"%s%d",p,num[num.size()-1]);
		for(int i=num.size()-2;i>=0;i--) sprintf(p,"%s%08d",p,num[i]);
		return p;
	}
	BigInt operator=(int v)
	{
		f=0;
		if(v<0)
		{
			f=1;
			v=-v;
		}
		std::queue<int> q;
		if(v==0) q.push(0);
		else
			while(v>0)
			{
				q.push(v%base);
				v/=base;
			}
		num.resize(q.size());
		for(int i=0;q.size()>0;i++)
		{
			num[i]=q.front();
			q.pop();
		}
		return *this;
	}
	BigInt operator+(BigInt& b)
	{
		format();
		b.format();
		BigInt c;
		int t=0,t2=std::max(num.size(),b.num.size())+1;
		c.num.resize(t2);
		memset(&c.num[0],0,t2*4);
		for(int i=0;i<t2;i++)
		{
			if(i<num.size()) t+=num[i];
			if(i<b.num.size()) t+=b.num[i];
			c.num[i]=t%base;
			t/=base;
		}
		c.format();
		return c;
	}
	BigInt operator*(BigInt& b)
	{
		format();
		b.format();
		BigInt c;
		c.num.resize(num.size()+b.num.size());
		memset(&c.num[0],0,(num.size()+b.num.size())*4);
		int i,j,k,I,J;
		long long t;
		for(i=0;i*CacheSize<num.size();i++)
			for(j=0;j*CacheSize<b.num.size();j++)
				for(I=i*CacheSize;I<(i+1)*CacheSize&&I<num.size();I++)
					for(J=j*CacheSize;J<(j+1)*CacheSize&&J<b.num.size();J++)
					{
						t=(long long)num[I]*b.num[J];
						t+=c.num[I+J];
						c.num[I+J]=t%base;
						k=I+J+1;
						t/=base;
						while(t>0)
						{
							t+=c.num[k];
							c.num[k++]=t%base;
							t/=base;
						}
					}
		c.f=(f!=b.f);
		c.format();
		return c;
	}
};
using namespace std;
int main()
{
	BigInt res,t,t2;
	t=1;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		t2=i;
		t=t*t2;
		res=res+t;
	}
	printf("%s\n",res.c_str());
	return 0;
}
