#include<cstdio>
#include<cstring>
#include<vector>
#include<cassert>
using namespace std;
const int maxn=2010;
const int maxnode=20000;
struct DLX
{
	int n,sz;
	int s[maxn];
	int row[maxnode],col[maxnode];
	int U[maxnode],D[maxnode],L[maxnode],R[maxnode];
	int ansd,ans[300];
	void init(int n)
	{
		this->n=n; sz=n+1;
		memset(s,0,sizeof(s));
		for(int i=0;i<=n;i++) { U[i]=i; D[i]=i; L[i]=i-1; R[i]=i+1; }
		L[0]=n; R[n]=0;
	}
	inline void push_back(int r,const vector<int> &cols)
	{
		int first=sz,szc=cols.size();
		for(int i=0;i<szc;i++)
		{
			int c=cols[i];
			L[sz]=sz-1; R[sz]=sz+1; D[sz]=c; U[sz]=U[c];
			D[U[sz]]=sz; U[c]=sz;
			row[sz]=r; col[sz]=c;
			++s[c]; ++sz;
		}
		R[sz-1]=first; L[first]=sz-1;
	}
	#define For(i,A,s) for(int i=A[s];i!=s;i=A[i])
	inline void remove(int c)
	{
		L[R[c]]=L[c]; R[L[c]]=R[c];
		For(i,D,c) For(j,R,i) { U[D[j]]=U[j]; D[U[j]]=D[j]; --s[col[j]]; }
	}
	inline void restore(int c)
	{
		For(i,U,c) For(j,L,i) { ++s[col[j]]; U[D[j]]=j; D[U[j]]=j; }
		L[R[c]]=c; R[L[c]]=c;
	}
	bool dfs(int d)
	{
		if(R[0]==0) { ansd=d; return true; }
		int c=R[0];
		For(i,R,0) if(s[i]<s[c]) c=i;
		remove(c);
		For(i,D,c)
		{
			ans[d]=row[i];
			For(j,R,i) remove(col[j]);
			if(dfs(d+1)) return true;
			For(j,L,i) restore(col[j]);
		}
		restore(c);
		return false;
	}
	bool solve(vector<int> &res)
	{
		res.clear();
		if(!dfs(0)) return false;
		for(int i=0;i<ansd;i++) res.push_back(ans[i]);
		return true;
	}
};
DLX solver;
const int Slot=0;
const int Row=1;
const int Col=2;
const int Sub=3;
inline int encode(int a,int b,int c) { return a*256+b*16+c+1; }
inline void decode(int code,int &a,int &b,int &c)
{
	code--;
	c=code%16;code/=16;
	b=code%16;code/=16;
	a=code;
}
char mp[16][20];
bool read()
{
	for(int i=0;i<16;i++) if(scanf("%s",mp[i])!=1) return false;
	return true;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int kase=0;
	while(read())
	{
		if(++kase!=1) printf("\n");
		solver.init(1024);
		for(int r=0;r<16;r++)
			for(int c=0;c<16;c++)
				for(int v=0;v<16;v++)
					if(mp[r][c]=='-'||mp[r][c]=='A'+v)
					{
						vector<int> cols;
						cols.push_back(encode(Slot,r,c));
						cols.push_back(encode(Row,r,v));
						cols.push_back(encode(Col,c,v));
						cols.push_back(encode(Sub,(r/4)*4+c/4,v));
						solver.push_back(encode(r,c,v),cols);
					}
		vector<int> ans;
		solver.solve(ans);
		for(int i=0;i<ans.size();i++)
		{
			int r,c,v;
			decode(ans[i],r,c,v);
			mp[r][c]='A'+v;
		}
		for(int i=0;i<16;i++) printf("%s\n",mp[i]);
	}
	return 0;
}
