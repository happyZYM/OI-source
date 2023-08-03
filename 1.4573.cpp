#include<iostream>
#include<cstdlib>
using namespace std;
const int idx[6]={1,2,4,5,7,8};
char ch;
int mp[9][9],hav_r[9][10],hav_c[9][10],hav_bx[3][3][10];
int btl[9][9],btu[9][9];
inline int dcmp(int x) { return x>0?1:-1; }
void dfs(int r,int c)
{
	if(c==9) { dfs(r+1,0); return; }
	if(r==9)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++) printf("%d ",mp[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for(int i=1;i<=9;i++)
		if(!hav_r[r][i]&&!hav_c[c][i]&&!hav_bx[r/3][c/3][i]&&(!btl[r][c]||dcmp(i-mp[r][c-1])==btl[r][c])&&(!btu[r][c]||dcmp(i-mp[r-1][c])==btu[r][c]))
		{
			mp[r][c]=i;
			hav_r[r][i]=hav_c[c][i]=hav_bx[r/3][c/3][i]=true;
			dfs(r,c+1);
			mp[r][c]=0;
			hav_r[r][i]=hav_c[c][i]=hav_bx[r/3][c/3][i]=false;
		}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	for(int r=0;r<3;r++)
	{
		for(int i=0;i<6;i++) { cin>>ch; btl[r*3+0][idx[i]]=(ch=='<'?1:-1); }
		for(int i=0;i<9;i++) { cin>>ch; btu[r*3+1][i]=(ch=='^'?1:-1); }
		for(int i=0;i<6;i++) { cin>>ch; btl[r*3+1][idx[i]]=(ch=='<'?1:-1); }
		for(int i=0;i<9;i++) { cin>>ch; btu[r*3+2][i]=(ch=='^'?1:-1); }
		for(int i=0;i<6;i++) { cin>>ch; btl[r*3+2][idx[i]]=(ch=='<'?1:-1); } 
	}
	dfs(0,0);
	return 0;
}
