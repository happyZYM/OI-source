#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
struct Cell
{
	int x,y;
	Cell(int x=0,int y=0):x(x),y(y){}
	inline bool operator<(const Cell &rhs) const
	{
		return x<rhs.x||(x==rhs.x&&y<rhs.y);
	}
};
typedef set<Cell> Block;
struct whc
{
	int w,h,c;
	whc(){}
	whc(int w,int h,int c):w(w),h(h),c(c){}
};

set<Block> poly[maxn];
int ans[maxn][maxn][maxn];
int SIZE[maxn];
whc V[maxn][17];

inline void format(Block *px)
{
	int minx=px->begin()->x,miny=px->begin()->y;
	for(auto c=px->begin();c!=px->end();++c)
	{
		minx=min(minx,c->x);
		miny=min(miny,c->y);
	}
	Block pn;
	for(auto c=px->begin();c!=px->end();++c)
		pn.insert(Cell(c->x-minx,c->y-miny));
	*px=pn;
}
inline void rotate(Block &px)
{
	Block p2;
	for(auto c=px.begin();c!=px.end();++c)
		p2.insert(Cell(c->y,-c->x));
	px=p2;
	format(&px);
}
inline void flip(Block &px)
{
	Block p3;
	for(auto c=px.begin();c!=px.end();++c)
		p3.insert(Cell(-c->x,c->y));
	format(&p3);
	px=p3;
}
void check(Block p,Cell &newCell)
{
	p.insert(newCell);
	format(&p);
	int n=p.size();
	for(int i=0;i<4;i++)
	{
		if(poly[n].count(p)) return;
		rotate(p);
	}
	flip(p);
	for(int i=0;i<4;i++)
	{
		if(poly[n].count(p)) return;
		rotate(p);
	}
	poly[n].insert(p);
}
void init()
{
	const int dx[]={0,0,1,-1};
	const int dy[]={1,-1,0,0};
	Block s;
	s.insert(Cell(0,0));
	poly[1].insert(s);
	for(int i=1;i<maxn-1;i++)
		for(auto it=poly[i].begin();it!=poly[i].end();it++)
			for(auto c=it->begin();c!=it->end();++c)
				for(int dir=0;dir<4;dir++)
				{
					Cell newc(c->x+dx[dir],c->y+dy[dir]);
					if(it->count(newc)==0) check(*it,newc);
				}
	int mp[maxn][maxn][maxn]={0};
	for(int n=1;n<maxn;n++)
	{
		SIZE[n]=0;
		for(auto it=poly[n].begin();it!=poly[n].end();it++)
		{
			int maxx=0,maxy=0;
			for(auto c=it->begin();c!=it->end();++c)
			{
				maxx=max(maxx,c->x);
				maxy=max(maxy,c->y);
			}
			if(maxy<maxx) swap(maxx,maxy);
			mp[n][maxx][maxy]++;
		}
	}
	for(int n=1;n<maxn;n++)
		for(int w=0;w<n;w++)
			for(int h=w;h<n;h++)
				if(mp[n][w][h])
					V[n][SIZE[n]++]=whc(w,h,mp[n][w][h]);
}

inline int solve(int n,int w,int h)
{
	if(ans[n][w][h]>-1) return ans[n][w][h];
	else
	{
		int cnt = 0;
		whc *a=V[n];
		for(int i=0,sz=SIZE[n];i<sz;i++)
		{
			whc &u=a[i];
			if(u.w<w&&u.h<h) cnt+=u.c;
		}
		return ans[n][w][h]=cnt;
	}
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	init();
	memset(ans,-1,sizeof(ans));
	int n,w,h;
	while(scanf("%d%d%d",&n,&w,&h)==3)
	{
		if(h<w) swap(w,h);
		printf("%d\n",solve(n,w,h));
	}
	return 0;
}
