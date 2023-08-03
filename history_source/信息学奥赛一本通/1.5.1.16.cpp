#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>a;
	int n;
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			if(a[j]==a[i])
			{
				a.erase(a.begin()+j);
				j--;
			}
		}
	}
	for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
	return 0;
}

