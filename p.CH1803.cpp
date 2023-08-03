//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1803%20City%20Game
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
int n,m,a[maxn][maxn],h[maxn],w[maxn],cnt,res; char x;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		cin>>x;
		if(x=='F') a[i][j]=a[i-1][j]+1;
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		for(int j=1;j<=m+1;j++)
		{
			int wid=0;
			while(cnt&&h[cnt-1]>=a[i][j])
			{
				wid+=w[cnt-1];
				res=max(res,wid*h[cnt-1]);
				cnt--;
			}
			h[cnt]=a[i][j]; w[cnt]=wid+1; cnt++;
		}
	}
	printf("%d\n",res*3);
	return 0;
}
