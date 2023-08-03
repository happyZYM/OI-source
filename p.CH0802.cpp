//http://contest-hunter.org:83/contest/0x08%E3%80%8C%E5%9F%BA%E6%9C%AC%E7%AE%97%E6%B3%95%E3%80%8D%E7%BB%83%E4%B9%A0/0802%20%E5%8D%A0%E5%8D%9CDIY
#include<iostream>
#include<algorithm>
using namespace std;
char a[14][6];
int f[128],hsh[15];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int i=1;i<=13;i++) for(int j=1;j<=4;j++) cin>>a[i][j];
	f['A']=1; f['0']=10; f['J']=11; f['Q']=12; f['K']=13;
	for(int i='2';i<='9';i++) f[i]=i-'0';
	for(int i=1;i<=4;i++)
	{
		int t=a[13][i];
		while(f[t]!=13&&hsh[f[t]]<4)
		{
			hsh[f[t]]++;
			for(int j=4;j>=2;j--) swap(a[f[t]][j],a[f[t]][j-1]);
			int tmp=a[f[t]][1]; a[f[t]][1]=t; t=tmp;
		}
	}
	for(int i=1;i<=12;i++) hsh[0]+=(hsh[i]==4);
	printf("%d\n",hsh[0]);
	return 0;
}
