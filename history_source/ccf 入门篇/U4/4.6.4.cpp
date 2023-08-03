#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int money[12],ans,c,n;
	bool j;
	while(true)
	{
		j=1;
		for(int i=0;i<12;i++) cin>>money[i];
		ans=0;
		c=0;
		for(int i=0;i<12;i++)
		{
			n=300+ans;
			if(n<money[i]) {
				cout<<"-"<<i+1<<endl;
				j=0;
				break;
			}
			else
			{
				ans=n-money[i];
				while(ans-100>=0) {
					ans-=100;
					c+=100;
				}
			}
		}
		if(j) cout<<c*1.2+ans<<endl;
	}
}
