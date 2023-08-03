#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
char buf[100],mp[9][10];
int rc[9],cc[9],bx[3][3],lg[2000],ct[2000];
bool dfs(int lst)
{
	if(lst==0) return true;
	int nr=-1,nc=-1,ncnt=10;
	for(int r=0;r<9;r++) for(int c=0;c<9;c++)
	{
		if(mp[r][c]) continue;
		int can=rc[r]&cc[c]&bx[r/3][c/3];
		if(ct[can]<ncnt) nr=r,nc=c,ncnt=ct[can];
	}
	for(int can=rc[nr]&cc[nc]&bx[nr/3][nc/3];can;can-=(can&-can))
	{
		int now=lg[can&-can];
		mp[nr][nc]=now;
		rc[nr]^=1<<now;
		cc[nc]^=1<<now;
		bx[nr/3][nc/3]^=1<<now;
		assert(1<=now&&now<=9);
		if(dfs(lst-1)) return true;
		mp[nr][nc]=0;
		rc[nr]^=1<<now;
		cc[nc]^=1<<now;
		bx[nr/3][nc/3]^=1<<now;
	}
	return false;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T; scanf("%d",&T);
	for(int i=1;i<=9;i++) lg[1<<i]=i;
	ct[1]=1;
	for(int i=1;(i<<1)+1<2000;i++) { ct[(i<<1)+1]=ct[i]+1; ct[i<<1]=ct[i]; }
	while(T-->0)
	{
		for(int r=0;r<9;r++) scanf("%s",mp[r]);
		memset(rc,0,sizeof(rc)); memset(cc,0,sizeof(cc)); memset(bx,0,sizeof(bx));
		for(int i=0;i<9;i++) for(int j=1;j<=9;j++) rc[i]|=1<<j;
		for(int i=0;i<9;i++) for(int j=1;j<=9;j++) cc[i]|=1<<j;
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=1;k<=9;k++) bx[i][j]|=1<<k;
		int tot=0;
		for(int r=0;r<9;r++) for(int c=0;c<9;c++)
		{
			if(mp[r][c]=='0') { mp[r][c]=0; tot++; continue; }
			mp[r][c]-='0';
			rc[r]^=(1<<mp[r][c]);
			cc[c]^=(1<<mp[r][c]);
			bx[r/3][c/3]^=(1<<mp[r][c]);
		}
		assert(dfs(tot));
		for(int r=0;r<9;r++) { for(int c=0;c<9;c++) putchar(mp[r][c]+'0'); puts(""); }
	}
	return 0;
}
