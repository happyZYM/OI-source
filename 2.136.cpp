#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int coeff[3]={2,3,5};
int main()
{
	priority_queue<LL,vector<LL>,greater<LL> > q;
	set<LL> s;
	q.push(1);
	s.insert(1);
	for(int i=1;;i++)
	{
		LL x=q.top();q.pop();
		if(i==1500)
		{
			cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
			return 0;
		}
		for(int j=0;j<3;j++)
		{
			LL x2=x*coeff[j];
			if(!s.count(x2))
			{
				s.insert(x2);
				q.push(x2);
			}
		}
	}
	return 0;
}
