//http://contest-hunter.org:83/contest/0x29%E3%80%8C%E6%90%9C%E7%B4%A2%E3%80%8D%E7%BB%83%E4%B9%A0/2903%20Mayan%E6%B8%B8%E6%88%8F
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct State
{
	int v[5][7],lst;
};
int n;
inline bool merge(State &st)
{
	State bk; memcpy(&bk,&st,sizeof(bk));
	for(int i=0;i<=2;i++) for(int j=0;j<7;j++)
	{
		if(bk.v[i][j]==0) continue;
		if(bk.v[i][j]==bk.v[i+1][j]&&bk.v[i+1][j]==bk.v[i+2][j]) st.v[i][j]=st.v[i+1][j]=st.v[i+2][j]=0;
	}
	for(int i=0;i<5;i++) for(int j=0;j<=4;j++)
	{
		if(bk.v[i][j]==0) continue;
		if(bk.v[i][j]==bk.v[i][j+1]&&bk.v[i][j+1]==bk.v[i][j+2]) st.v[i][j]=st.v[i][j+1]=st.v[i][j+2]=0;
	}
	st.lst=0;
	for(int i=0;i<5;i++) for(int j=0;j<7;j++) st.lst+=(st.v[i][j]>0);
	return st.lst<bk.lst;
}
inline void op(State &st,int x,int y,int g)
{
	swap(st.v[x][y],st.v[x+g][y]);
	do
	{
		for(int i=0;i<5;i++)
		{
			int l=0,r=0;
			while(r<7)
			{
				if(!st.v[i][r]) { r++; continue; }
				swap(st.v[i][l++],st.v[i][r++]);
			}
		}
	}
	while(merge(st));
}
int sx[10],sy[10],sg[10],sc;
void dfs(int step,State st)
{
	if(st.lst==0)
	{
//		if(step==n)
//		{
			for(int i=0;i<sc;i++) printf("%d %d %d\n",sx[i],sy[i],sg[i]);
			exit(0);
//		}
//		return;
	}
	if(step+1>n) return;
	for(int x=0;x<5;x++) for(int y=0;y<7;y++) if(st.v[x][y])
	{
		if(x+1<5)
		{
			if(st.v[x+1][y]==st.v[x][y]) continue;
			State st2; memcpy(&st2,&st,sizeof(st));
			op(st2,x,y,1);
			sx[sc]=x; sy[sc]=y; sg[sc++]=1;
			dfs(step+1,st2);
			sc--;
		}
		if(x-1>=0&&st.v[x-1][y]==0)
		{
			State st2; memcpy(&st2,&st,sizeof(st));
			op(st2,x,y,-1);
			sx[sc]=x; sy[sc]=y; sg[sc++]=-1;
			dfs(step+1,st2);
			sc--;
		}
	}
}
void print(const State &st)
{
	printf("lst=%d\n",st.lst);
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<7;j++) printf("%d ",st.v[i][j]);
		puts("");
	}
	puts("");
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	State bg; memset(&bg,0,sizeof(bg));
	for(int i=0;i<5;i++)
	{
		int x,cnt=0;
		while(scanf("%d",&x),x) bg.v[i][cnt++]=x,bg.lst++;
	}
//	print(bg);
	dfs(0,bg);
	puts("-1");
	return 0;
}
