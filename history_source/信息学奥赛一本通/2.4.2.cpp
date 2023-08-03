#include<iostream>
#include<string> 
#include<algorithm>
#include<cstring>
using namespace std;
string biao;
short *ans;
bool *use;
void answer(int step)
{
	if(step==biao.size())
	{
		for(int i=0;i<biao.size();i++) cout<<biao[ans[i]];
		cout<<'\n';
		return; 
	}
	for(int i=0;i<biao.size();i++)
	{
		if(use[i])
		{
			use[i]=0;
			ans[step]=i;
			answer(step+1);
			use[i]=1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>biao;
	sort(biao.begin(),biao.end());
	ans=new short[biao.size()];
	use=new bool[biao.size()];
	memset(use,1,biao.size());
	answer(0);
	cout<<flush;
	return 0;
}
