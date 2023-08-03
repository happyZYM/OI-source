#include<iostream>
#include<vector>
using namespace std;
int d(int a)
{
	int add=a;
	do
	{
		add+=a%10;
		a/=10;
	}
	while(a>0);
	return add;
}
bool find(int sr)
{
	for(int i=1;i<=sr;i++) if(d(i)==sr) return 1;
	return 0;
}
int main()
{
	int n,k,sr[5000],num,j;
	vector <int> so;
	while(true)
	{
		so.clear();
		num=0;
		cin>>n>>k;
		for(int i=0;i<k;i++) cin>>sr[i];
		for(int i=1;i<=n;i++) if(!find(i)) num++;
		cout<<num<<endl;
		j=0;
		for(int i=1;i>0;i++)
		{
			if(!find(i))
			{
				so.push_back(i);
			}
			if(so.size()>=sr[k-1]) break;
		}
		for(int i=0;i<k;i++) cout<<so[sr[i]-1]<<" ";
		cout<<endl;
	}
}
