#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=600005;
int n,m,ch[maxn*24][2],lst[maxn*24],s[maxn],rt[maxn],ncnt;
void insert(int i,int k,int p,int &q)
{
	if(!q) q=++ncnt;
	if(k<0) { lst[q]=i; return; }
	int c=(s[i]>>k)&1;
	if(p) ch[q][c^1]=ch[p][c^1];
	insert(i,k-1,ch[p][c],ch[q][c]);
	lst[q]=max(lst[ch[q][0]],lst[ch[q][1]]);
}
int query(int o,int val,int k,int L)
{
	if(k<0) return s[lst[o]]^val;
	int c=val>>k&1;
	if(lst[ch[o][c^1]]>=L) return query(ch[o][c^1],val,k-1,L);
	else return query(ch[o][c],val,k-1,L);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	lst[0]=-1;
	insert(0,23,0,rt[0]);
	for(int i=1;i<=n;i++)
	{
		int x; cin>>x;
		s[i]=s[i-1]^x;
		insert(i,23,rt[i-1],rt[i]);
	}
	for(int i=1;i<=m;i++)
	{
		char op; cin>>op;
		if(op=='A')
		{
			int x; cin>>x;
			n++;
			s[n]=s[n-1]^x;
			insert(n,23,rt[n-1],rt[n]);
		}
		else
		{
			int l,r,x; cin>>l>>r>>x;
			printf("%d\n",query(rt[r-1],x^s[n],23,l-1));
		}
	}
	return 0;
}
