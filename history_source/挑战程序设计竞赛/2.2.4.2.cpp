#include<cstdio>
#include<vector>
struct heap
{
	int SIZE;
	std::vector<int> v;
	heap()
	{
		SIZE=0;
	}
	int push(int vv)
	{
		static int p,i;
		i=SIZE++;
		if(i>=v.size()) v.push_back(int());
		while(i>0)
		{
			p=(i-1)/2;
			if(v[p]<=vv) break;
			v[i]=v[p];
			i=p;
		}
		v[i]=vv;
		return vv;
	}
	int top()
	{
		if(SIZE>0) return v[0];
		return int();
	}
	int pop()
	{
		static int i,a,b;
		static int x,ret;
		ret=v[0];
		x=v[--SIZE];
		i=0;
		while(i*2+1<SIZE)
		{
			a=i*2+1,b=i*2+2;
			if(b<SIZE&&v[b]<v[a]) a=b;
			if(v[a]>=x) break;
			v[i]=v[a];
			i=a;
		}
		v[i]=x;
		return ret;
	}
	inline int size()
	{
		return SIZE;
	}
};
heap hp;
void solve()
{
	long long a,b,ans=0;
	while(hp.size()>1)
	{
		a=hp.top();
		hp.pop();
		b=hp.top();
		hp.pop();
		ans+=a+b;
		hp.push(a+b);
	}
	printf("%lld\n",ans);
}
void init()
{
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		hp.push(t);
	}
}
int main()
{
	init();
	solve();
	return 0;
}
