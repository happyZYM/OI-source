#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int maxn,max,num;
	num=a[0];
	maxn=max=1;
	for(int i=1;i<n;i++)
	{
		if(num==a[i]) max++;
		else
		{
			if(max>maxn) maxn=max;
			max=1;
			num=a[i];
		}
	}
	if(max>maxn) maxn=max;
	cout<<maxn<<endl;
	return 0;
}

