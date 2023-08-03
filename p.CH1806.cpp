//http://contest-hunter.org:83/contest/0x18%E3%80%8C%E5%9F%BA%E6%9C%AC%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E3%80%8D%E7%BB%83%E4%B9%A0/1806%20Matrix
#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=1005;
const unsigned long long Pr=13141,Pc=521;
int N,M,A,B,Q;
int a[maxn][maxn]; char buf[maxn];
unsigned long long H[maxn][maxn],pmr[maxn],pmc[maxn];
set<unsigned long long> st;
inline void read(int R,int C)
{
	for(int i=1;i<=R;i++)
	{
		scanf("%s",buf);
		for(int j=1;j<=C;j++) a[i][j]=(buf[j-1]-'0');
	}
}
inline void Cal(int R,int C)
{
	for(int i=1;i<=R;i++) for(int j=1;j<=C;j++) H[i][j]=H[i-1][j]*Pr+H[i][j-1]*Pc-H[i-1][j-1]*Pr*Pc+(a[i][j]+51);
}
inline void Build()
{
	unsigned long long RM=pmr[A],CM=pmc[B],BM=pmr[A]*pmc[B];
	for(int i=A;i<=N;i++) for(int j=B;j<=M;j++) st.insert( H[i][j] - H[i-A][j]*RM - H[i][j-B]*CM + H[i-A][j-B]*BM);
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
	freopen("pro.out","w",stdout);
#endif
	scanf("%d%d%d%d",&N,&M,&A,&B);
	pmr[0]=pmc[0]=1;
	for(int i=1;i<maxn;i++) pmr[i]=pmr[i-1]*Pr,pmc[i]=pmc[i-1]*Pc;
	read(N,M);
	Cal(N,M);
	Build();
	scanf("%d",&Q);
//	cerr<<"Q="<<Q<<endl;
	while(Q-->0)
	{
		read(A,B);
		Cal(A,B);
	//	cerr<<H[A][B]<<endl;
		if(st.find(H[A][B])!=st.end()) puts("1");
		else puts("0");
	}
	return 0;
}
