#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int a[10005];
vector<pair<int,int>> res;
inline void reverse(int* L,int* R)   //[L,R)
{
	int mid=(R-L)/2;
	for(int i=0;i<mid;i++) swap(L[i],L[mid+i]);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T,i,j,pos;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",a+i);
		res.clear();
		for(i=1;i<n;i++)
		{
			for(j=1;j<=n;j++)
				if(a[j]==i)
				{
					pos=j;
					break;
				}
			if(pos==i) continue;
			if(i+(pos-i)*2-1>n)
			{
				int len=(n-i+1)/2;
				res.push_back(make_pair(n-len*2+1,n));
				reverse(a+n-len*2+1,a+n+1);
				pos-=len;
			}
			reverse(a+i,a+i+(pos-i)*2);
			res.push_back(make_pair(i,i+(pos-i)*2-1));
		}
		printf("%d\n",res.size());
		for(int i=0;i<res.size();i++) printf("%d %d\n",res[i].first,res[i].second);
	}
	return 0;
}
/*
4 3 2 1
*/
