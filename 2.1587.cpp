#include<cstdio>
#include<map>
#include<set>
using namespace std;
int x,y,cnt,size;
map<pair<int,int>,int> mp;
set<int> st;
struct node
{
	int x,y,cnt;
};
node a[6];
bool ok;
int main()
{
#define NDEBUG
#ifdef local
	freopen("pro.in","r",stdin);
	#undef NDEBUG
#endif
	while(1)
	{
		size=cnt=0;
		mp.clear();
		st.clear();
		ok=true;
		for(int i=0;i<6;i++)
		{
			cnt+=scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			mp[make_pair(x,y)]++;
			st.insert(x);st.insert(y);
		}
		if(cnt<6) break;
		auto it=mp.begin();
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			a[size].x=(it->first).first;
			a[size].y=(it->first).second;
			a[size++].cnt=it->second;
		}
		if(size>3||st.size()>3)
		{
			ok=false;
			goto print;
		}
		for(int i=0;i<size;i++)
			if(a[i].cnt%2>0)
			{
				ok=false;
				goto print;
			}
		if(size==1) ok=(a[0].x==a[0].y);
		else if(mp.size()==2) ok=(a[0].x==a[0].y&&a[0].cnt==2&&a[1].cnt==4)
							   ||(a[1].x==a[1].y&&a[1].cnt==2&&a[0].cnt==4);
		else ok=(a[0].cnt==2&&a[1].cnt==2&&a[2].cnt==2);
print:
		if(ok) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
/*
1 2 3
1,2
1,3
2,3
*/
