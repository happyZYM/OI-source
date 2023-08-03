#include<iostream>
using namespace std;
int n,a[105];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<i;j++) tot+=(a[j]<a[i]);
		cout<<tot<<' ';
	}
	cout<<endl;
	return 0;
}
