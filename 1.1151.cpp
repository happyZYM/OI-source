#include<iostream>
using namespace std;
int main()
{
	int k,flg=1; cin>>k;
	for(int a=1;a<=3;a++) for(int b=0;b<=9;b++) for(int c=0;c<=9;c++) for(int d=0;d<=9;d++) for(int e=0;e<=9;e++)
		if(a*10000+b*1000+c*100+d*10+e<=30000&&(a*100+b*10+c)%k==0&&(b*100+c*10+d)%k==0&&(c*100+d*10+e)%k==0)
		{
			flg=0;
			cout<<a<<b<<c<<d<<e<<endl;
		}
	if(flg) cout<<"No"<<endl;
	return 0;
}
