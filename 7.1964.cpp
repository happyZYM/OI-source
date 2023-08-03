#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1005;
int T,n,m,a[maxn][maxn],h[maxn],w[maxn],cnt,res; char x;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>T;
	while(T-->0)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		{
			cin>>x;
			if(x=='F') a[i][j]=a[i-1][j]+1;
			else a[i][j]=0;
		}
		res=0;
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
		cout<<res*3<<endl;
	}
	return 0;
}
