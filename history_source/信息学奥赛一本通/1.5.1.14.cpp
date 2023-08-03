#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num,num+n);
	int j=0;
	for(int i=0;i<=num[n-1];i++)
	{
		int add=0;
		while(num[j]==i) add++,j++;
		cout<<add<<endl;
	}
	return 0;
}

