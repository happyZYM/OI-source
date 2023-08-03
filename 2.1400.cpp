#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=500000+10;
const int maxnode=1000000+10;
typedef long long LL;
typedef pair<int,int> node;
LL prefix_sum[maxn];
inline LL sum(int L,int R) { return prefix_sum[R]-prefix_sum[L-1]; }
inline LL sum(const node &p) { return sum(p.first,p.second); }
node better(node a,node b)
{
	LL sa=sum(a),sb=sum(b);
	return sa!=sb?(sa>sb?a:b):(a<b?a:b);
}
int qL,qR;
struct IntervalTree
{
	node max_sub[maxnode];
	int max_prefix[maxnode];
	int max_suffix[maxnode];
	void build(int o,int L,int R)
	{
		if(L==R)
		{
			max_prefix[o]=L;
			max_suffix[o]=R;
			max_sub[o]=make_pair(L,L);
		}
		else
		{
			int lc=o*2,rc=o*2+1;
			int M=(L+R)/2;
			build(lc,L,M);
			build(rc,M+1,R);
			LL v1=sum(L,max_prefix[lc]);
			LL v2=sum(L,max_prefix[rc]);
			if(v1==v2) max_prefix[o]=min(max_prefix[lc],max_prefix[rc]);
			//the smaller,the better
			else max_prefix[o]=v1>v2?max_prefix[lc]:max_prefix[rc];
			
			v1=sum(max_suffix[lc],R);
			v2=sum(max_suffix[rc],R);
			if(v1==v2)  max_suffix[o]=min(max_suffix[lc],max_suffix[rc]);
			else max_suffix[o]=v1>v2?max_suffix[lc]:max_suffix[rc];
			
			max_sub[o]=better(max_sub[lc],max_sub[rc]);
			max_sub[o]=better(max_sub[o]
						,make_pair(max_suffix[lc],max_prefix[rc]));
		}
	}
	node query_prefix(int o,int L,int R)
	{
		if(max_prefix[o]<=qR) return make_pair(L,max_prefix[o]);
		int M=(L+R)/2;
		int lc=o*2,rc=o*2+1;
		if(qR<=M) return query_prefix(lc,L,M);
		node i=query_prefix(rc,M+1,R);
		i.first=L;
		return better(i,make_pair(L,max_prefix[lc]));
	}
	node query_suffix(int o,int L,int R)
	{
		if(max_suffix[o]>=qL) return make_pair(max_suffix[o],R);
		int M=(L+R)/2;
		int lc=o*2,rc=o*2+1;
		if(qL>M) return query_suffix(rc,M+1,R);
		node i=query_suffix(lc,L,M);
		i.second=R;
		return better(i,make_pair(max_suffix[rc],R));
	}
	node query(int o,int L,int R)
	{
		if(qL<=L&&qR>=R) return max_sub[o];
		else
		{
			int lc=o*2,rc=o*2+1;
			int M=(L+R)/2;
			if(qR<=M) return query(lc,L,M);
			if(qL>M) return query(rc,M+1,R);
			node i1=query_suffix(lc,L,M);
			node i2=query_prefix(rc,M+1,R);
			node i3=better(query(lc,L,M),query(rc,M+1,R));
			return better(make_pair(i1.first,i2.second),i3);
		}
	}
};
IntervalTree tree;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int kase=0,n,a,Q;
	while(scanf("%d%d",&n,&Q)==2)
	{
		prefix_sum[0]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			prefix_sum[i+1]=prefix_sum[i]+a;
		}
		tree.build(1,1,n);
		printf("Case %d:\n",++kase);
		for(int i=0;i<Q;i++)
		{
			scanf("%d%d",&qL,&qR);
			node ans=tree.query(1,1,n);
			printf("%d %d\n",ans.first,ans.second);
		}
	}
	return 0;
}
