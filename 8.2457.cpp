#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=200005;
int n;
pair<int,int> a[maxn];
inline bool cmp(int x,int y) { return a[x]<a[y]||(a[x]==a[y]&&x<y); }
vector<int> b[maxn]; int cnt;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[++cnt].push_back(a[i].second);
		while(i+1<=n&&a[i].first==a[i+1].first) b[cnt].push_back(a[++i].second);
	}
	int flg=0,res=1,now=0x3f3f3f3f;
	for(int i=1;i<=cnt;i++)
	{
		int s=b[i].size();
		if(flg)
		{
			if(now<b[i][0]) now=b[i][s-1];
			else
			{
				now=b[i][0];
				res++; flg=0;
			}
		}
		else
		{
			if(now>b[i][s-1]) now=b[i][0];
			else
			{
				now=b[i][s-1];
				flg=1;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
