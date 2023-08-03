#include<iostream>
using namespace std;
int main()
{
	char li;
	bool isc[100010]={0};
	int k,x;
	cin>>k>>li>>x;
	isc[k]=1;
	for(int i=0;i*2+1<100010;i++)
		if(isc[i])
		{
			isc[i*2+1]=1;
			if(i*3+1<100010) isc[i*3+1]=1;
		}
	if(isc[x]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

