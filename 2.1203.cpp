#include<cstdio>
#include<queue>
using namespace std;
struct Item
{
	int QNum,Period,Time;
	inline bool operator<(const Item &a) const
	{
		return Time>a.Time||(Time==a.Time&&QNum>a.QNum);
	}
};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	priority_queue<Item> q;
	char s[20];
	while(scanf("%s",s)==1&&s[0]!='#')
	{
		Item item;
		scanf("%d%d",&item.QNum,&item.Period);
		item.Time=item.Period;
		q.push(item);
	}
	int k;
	scanf("%d",&k);
	while(k--)
	{
		Item r=q.top();
		q.pop();
		printf("%d\n",r.QNum);
		r.Time+=r.Period;
		q.push(r);
	}
	return 0;
}
