#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=12005;
const int maxb=150;
int n,m,a[maxn],s[maxn],w[maxb][maxn],LP[maxb],RP[maxb],bid[maxn],mem[maxn],*rt=mem+1,ch[60*maxn][2],cnt[60*maxn],ncnt;
int modify(int o,int val,int k)
{
	int no=++ncnt;
	ch[no][0]=ch[o][0]; ch[no][1]=ch[o][1];
	cnt[no]=cnt[o]+1;
	if(k<0) return no;
	ch[no][val>>k&1]=modify(ch[no][val>>k&1],val,k-1);
	return no;
}
int xw(int lrt,int rrt,int val,int k)
{
	if(k<0) return 0;
	int c=val>>k&1;
	if(cnt[ch[rrt][c^1]]-cnt[ch[lrt][c^1]]>0) return (1<<k)+xw(ch[lrt][c^1],ch[rrt][c^1],val,k-1);
	else return xw(ch[lrt][c],ch[rrt][c],val,k-1);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++) rt[i]=modify(rt[i-1],s[i],30);
	int blo=sqrt(n),tot=0,res=0;
	if(blo*blo<n) blo++;
	for(int i=1;i<=n;i++)
	{
		bid[i]=(i-1)/blo+1;
		tot=max(tot,bid[i]);
		if(!LP[tot]) LP[tot]=i;
		RP[tot]=i;
	}
	//cout<<"blo="<<blo<<" tot="<<tot<<endl;
	for(int i=1;i<=tot;i++)
		for(int j=LP[i];j<=n;j++)
			w[i][j]=max(w[i][j-1],xw(rt[LP[i]-1],rt[j],s[j],30));
	while(m-->0)
	{
		int x,y; cin>>x>>y;
		x=(((LL)x+res)%n)+1; y=(((LL)y+res)%n)+1;
		int l=min(x,y),r=max(x,y);
	//	cout<<l<<' '<<r<<' ';
		l--;
		if(bid[l]==bid[r])
		{
			res=0;
			for(int i=l;i<=r;i++) res=max(res,xw(rt[l-1],rt[i],s[i],30));
		}
		else
		{
			res=w[bid[l]+1][r];
			for(int i=l;i<=RP[bid[l]];i++) res=max(res,xw(rt[i-1],rt[r],s[i],30));
		}
		cout<<res<<endl;
	}
	return 0;
}
