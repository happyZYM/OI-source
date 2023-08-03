#include<cstdio>
#include<cstring>
//#include<conio.h>
const int maxn=205;
int mp[maxn][maxn];
char s[maxn];
const int dx[]={0,0,-1,1};
const int dy[]={-1,1,0,0};
int H,W;
#define set(a,b,c,d) mp[i][j<<2]=a,mp[i][(j<<2)+1]=b,mp[i][(j<<2)+2]=c,mp[i][(j<<2)+3]=d;
void init()
{
	for(int i=0;i<H;i++)
	{
		scanf("%s",s);
		for(int j=0;j<W;j++)
			switch(s[j])
			{
				case '0':set(0,0,0,0);break;
				case '1':set(0,0,0,1);break;
				case '2':set(0,0,1,0);break;
				case '3':set(0,0,1,1);break;
				case '4':set(0,1,0,0);break;
				case '5':set(0,1,0,1);break;
				case '6':set(0,1,1,0);break;
				case '7':set(0,1,1,1);break;
				case '8':set(1,0,0,0);break;
				case '9':set(1,0,0,1);break;
				case 'a':set(1,0,1,0);break;
				case 'b':set(1,0,1,1);break;
				case 'c':set(1,1,0,0);break;
				case 'd':set(1,1,0,1);break;
				case 'e':set(1,1,1,0);break;
				case 'f':set(1,1,1,1);break;
			}
	}
	W<<=2;
}
void dfs1(int y,int x,int co)
{
	if(y<0||y>=H||x<0||x>=W) return;
	if(mp[y][x]==-1||mp[y][x]!=co) return;
	mp[y][x]=-1;
	for(int i=0;i<4;i++)
		dfs1(y+dy[i],x+dx[i],co);
}
int dfs2(int y,int x)
{
	if(y<0||y>=H||x<0||x>=W) return 0;
	if(mp[y][x]==-1) return 0;
	int res=0;
	if(mp[y][x]==1)
	{
		mp[y][x]=-1;
		for(int i=0;i<4;i++)
			res+=dfs2(y+dy[i],x+dx[i]);
	}
	else
	{
//		printf("\t\t\tfound zero! at x=%d y=%d\n",x,y);
		dfs1(y,x,0);
		return 1;
	}
	return res;
}
int cnt;
void print()
{
	for(int i=0;i<H;i++)
	{
		printf("\t");
		for(int j=0;j<W;j++) printf("%3d",mp[i][j]);
		printf("\n");
	}
}
void solve()
{
	for(int i=0;i<H;i++)
	{
		if(mp[i][0]==0) dfs1(i,0,0);
		if(mp[i][W-1]==0) dfs1(i,W-1,0);
	}
	for(int i=0;i<W;i++)
	{
		if(mp[0][i]==0) dfs1(0,i,0);
		if(mp[H-1][i]==0) dfs1(H-1,i,0);
	}
	int A,D,J,K,S,w;
	A=D=J=K=S=w=0;
//	printf("process finished! H=%d W=%d\n",H,W);
//	print();
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
		{
//			printf("mp[%d][%d]=%d\n",i,j,mp[i][j]);
			if(mp[i][j]==1)
			{
//				printf("\t123\n");
				int t;
				switch(t=dfs2(i,j))
				{
					case 1:A++;break;
					case 3:J++;break;
					case 5:D++;break;
					case 4:S++;break;
					case 0:w++;break;
					case 2:K++;break;
				}
//				printf("\t\tfind %d holes at x=%d y=%d\n",t,j,i);
//				print();
//				getch();
			}
		}
	printf("Case %d: ",++cnt);
	while(A-->0) putchar('A');
	while(D-->0) putchar('D');
	while(J-->0) putchar('J');
	while(K-->0) putchar('K');
	while(S-->0) putchar('S');
	while(w-->0) putchar('W');
	printf("\n");
}
int main()
{
	while(scanf("%d%d",&H,&W)==2&&H&&W)
	{
		init();
		solve();
	}
	return 0;
}
