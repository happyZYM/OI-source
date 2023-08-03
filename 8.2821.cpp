#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn=1e5+5;
const int maxb=350;
int n,c,m,a[maxn],res,w[maxb][maxb],cnt[maxb][maxn],blo,tot,LP[maxb],RP[maxb],bid[maxn],tmp[maxn];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>c>>m;
	blo=sqrt(n); if(blo*blo<n) blo++;
	for(int i=1;i<=n;i++)
	{
		bid[i]=(i-1)/blo+1;
		tot=bid[i];
		if(!LP[tot]) LP[tot]=i;
		RP[tot]=i;
	}
	for(int i=1;i<=n;i++) { cin>>a[i]; cnt[bid[i]][a[i]]++; }
	for(int i=1;i<=tot;i++) for(int j=1;j<maxn;j++) cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=tot;i++)
	{ 
		memset(tmp,0,sizeof(tmp));
		int now=0;
		for(int j=i;j<=tot;j++)
		{
			for(int k=LP[j];k<=RP[j];k++)
			{
				if(tmp[a[k]]&&(tmp[a[k]]&1)==0) now--;
				tmp[a[k]]++;
				if((tmp[a[k]]&1)==0) now++;
			}
			w[i][j]=now;
		}
	}
	while(m-->0)
	{
		int l,r; cin>>l>>r;
		l=(l+res)%n+1; r=(r+res)%n+1;
		if(l>r) swap(l,r);
//		cout<<"["<<l<<","<<r<<"]"<<'\n';
		if(bid[l]+1>bid[r]-1)
		{
			memset(tmp,0,sizeof(tmp));
			res=0;
			for(int i=l;i<=r;i++)
			{
				if(tmp[a[i]]&&(tmp[a[i]]&1)==0) res--;
				tmp[a[i]]++;
				if((tmp[a[i]]&1)==0) res++;
			}
			cout<<res<<'\n';
		}
		else
		{
			res=w[bid[l]+1][bid[r]-1];
			for(int i=l;i<=RP[bid[l]];i++) tmp[a[i]]=cnt[bid[r]-1][a[i]]-cnt[bid[l]+1-1][a[i]];
			for(int i=LP[bid[r]];i<=r;i++) tmp[a[i]]=cnt[bid[r]-1][a[i]]-cnt[bid[l]+1-1][a[i]];
			for(int i=l;i<=RP[bid[l]];i++)
			{
				if(tmp[a[i]]&&(tmp[a[i]]&1)==0) res--;
				tmp[a[i]]++;
				if((tmp[a[i]]&1)==0) res++;
			}
			for(int i=LP[bid[r]];i<=r;i++)
			{
				if(tmp[a[i]]&&(tmp[a[i]]&1)==0) res--;
				tmp[a[i]]++;
				if((tmp[a[i]]&1)==0) res++;
			}
			cout<<res<<'\n';
		}
	}
	return 0;
}
