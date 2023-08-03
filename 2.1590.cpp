#include<iostream>
using namespace std;
unsigned int ips[1005];
int m;
unsigned int base=0xffffffffu;
bool check(int n)
{
	for(int i=1;i<m;i++)
		if((ips[0]&(base<<n))^(ips[i]&(base<<n)))
			return 0;
	return 1;
}
inline void print(unsigned int ip)
{
	cout<<(ip>>24)<<"."<<((ip>>16)&0xffu)<<"."<<((ip>>8)&0xffu)<<"."<<(ip&0xffu)<<endl;
}
void solve()
{
	unsigned int t1,t2,t3,t4;
	char t;
	for(int i=0;i<m;i++)
	{
		cin>>t1>>t>>t2>>t>>t3>>t>>t4;
		ips[i]=(t1<<24)|(t2<<16)|(t3<<8)|t4;
//		cout<<'\t'<<ips[i]<<endl<<'\t';
//		print(ips[i]);
	}
	int i;
	for(i=0;i<=32;i++)
		if(check(i))
		{
			print(ips[0]&(base<<i));
			print(base<<i);
			return;
		}
	cout<<"0.0.0.0\n0.0.0.0"<<endl;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>m) solve();
	return 0;
}
