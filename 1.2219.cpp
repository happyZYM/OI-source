#include<cstdio>
#define For(i,a,b) for(int i=a;i<=b;++i)
inline int max(int a,int b) { return a>b?a:b; }
template<typename T> inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args> inline void read(T& t,Args&... args) { read(t); read(args...); }

const int maxnm=1005;
int n,m,a,b,c,d;
int mp[maxnm][maxnm],s[maxnm][maxnm];
int MWR[maxnm][maxnm],MW[maxnm][maxnm];
int que[maxnm],head,tail;
inline int SubSum(int r,int c,int rl,int cl)
{ return s[r][c]-s[r-rl][c]-s[r][c-cl]+s[r-rl][c-cl]; }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(n,m,a,b,c,d);
	For(i,1,n) For(j,1,m) read(mp[i][j]);
	For(i,1,n) For(j,1,m) s[i][j]=mp[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	For(i,c+1,n-1)
	{
		head=tail=0;
		For(j,d+1,b-2)
		{
			while(head<tail&&SubSum(i,j,c,d)<=SubSum(i,que[tail-1],c,d)) tail--;
			que[tail++]=j;
		}
		For(j,b-1,m-1)
		{
			while(head<tail&&(que[head]-d+1)<=(j+1-b+1)) head++;
			while(head<tail&&SubSum(i,j,c,d)<=SubSum(i,que[tail-1],c,d)) tail--;
			que[tail++]=j;
			MWR[i+1][j+1]=SubSum(i,que[head],c,d);
		}
	}
	For(j,b,m)
	{
		head=tail=0;
		For(i,c+2,a-1)
		{
			while(head<tail&&MWR[i][j]<=MWR[que[tail-1]][j]) tail--;
			que[tail++]=i;
		}
		For(i,a,n)
		{
			while(head<tail&&(que[head]-c)<=(i-a+1)) head++;
			while(head<tail&&MWR[i][j]<=MWR[que[tail-1]][j]) tail--;
			que[tail++]=i;
			MW[i][j]=MWR[que[head]][j];
		}
	}
	int res=0;
	For(i,a,n) For(j,b,m) res=max(res,SubSum(i,j,a,b)-MW[i][j]);
	printf("%d\n",res);
	return 0;
}
/*
8 8 5 5 2 2
9 7 6 9 3 5 7 6 
6 5 8 2 5 4 4 1 
6 1 6 3 3 5 5 3 
2 8 2 5 3 6 1 8 
6 2 1 4 6 2 9 1 
5 0 3 6 4 9 2 9 
3 4 4 0 5 9 6 3 
4 2 8 8 7 5 8 1 
MWR:
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0 19 13 13 17
  0  0  0  0 16 14 14 17
  0  0  0  0 12 12 17 17
  0  0  0  0  6 14 20 21
  0  0  0  0 11 13 15 26
MW:
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0  0  0  0  0
  0  0  0  0 16 13 13 17
  0  0  0  0 12 12 13 17
  0  0  0  0  6 12 14 17
  0  0  0  0  6 12 15 17
110
*/
