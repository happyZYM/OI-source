//https://www.acwing.com/problem/content/339/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
int T,kase,n,h1[128],cnt1[14],cnt2[5];
ULL f[14][14][14][14];
ULL dp(int c4,int c3,int c2,int c1)
{
	ULL &res=f[c4][c3][c2][c1];
	if(res!=-1ull) return res;
	res=0;
	if(c1>0) res+=1ull*c1*dp(c4,c3,c2,c1-1);
	if(c2>0) res+=2ull*c2*(dp(c4,c3,c2-1,c1+1)-dp(c4,c3,c2-1,c1));
	if(c3>0) res+=3ull*c3*(dp(c4,c3-1,c2+1,c1)-2ull*(dp(c4,c3-1,c2,c1+1)-dp(c4,c3-1,c2,c1)));
	if(c4>0) res+=4ull*c4*(dp(c4-1,c3+1,c2,c1)-3ull*(dp(c4-1,c3,c2+1,c1)-2ull*(dp(c4-1,c3,c2,c1+1)-dp(c4-1,c3,c2,c1))));
	return res;
}
int main()
{
	#ifdef local
	freopen("pro.in","r",stdin);
	#endif
	scanf("%d",&T);
	h1['A']=1;
	for(int i='2';i<='9';i++) h1[i]=i-'0';
	h1['T']=10; h1['J']=11; h1['Q']=12; h1['K']=13;
	memset(f,-1,sizeof(f));
	f[0][0][0][0]=1;
	while(T-->0)
	{
		scanf("%d",&n);
		char s[3];
		FU(i,1,13) cnt1[i]=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			cnt1[h1[s[0]]]++;
		}
		FU(i,1,4) cnt2[i]=0;
		FU(i,1,13) cnt2[cnt1[i]]++;
		printf("Case #%d: %llu\n",++kase,dp(cnt2[4],cnt2[3],cnt2[2],cnt2[1]));
	}
	return 0;
}