#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string fn[105];
int n,size;
void print(const string& s,int len,char ch)
{
	cout<<s;
	for(int i=0;i<len-s.size();i++) cout<<ch;
}
void solve()
{
	size=0;
	for(int i=0;i<n;i++)
	{
		cin>>fn[i];
		size=max(size,(int)fn[i].size());
	}
	sort(fn,fn+n);
	print("",60,'-');
	cout<<endl;
	int L=62/(size+2),H=n/L+(n%L>0),pos;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<L;j++)
		{
			pos=j*H+i;
			if(pos<n) print(fn[pos],j==L-1?size:size+2,' ');
		}
		cout<<endl;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>n) solve();
	return 0;
}
