#include<cstdio>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define min(a,b) ((a)<(b)?(a):(b))
template<typename T>
inline void read(T& t)
{
    t=0; bool f=false; char ch;
    while(ch=getchar(),!((ch>='0'&&ch<='9')||ch=='-'));
    if(ch=='-') f=true,ch=getchar();
    t=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') t=t*10+ch-'0';
    if(f) t=-t;
}
template<typename T,typename... Args>
inline void read(T& t,Args&... args) { read(t); read(args...); }

const int maxab=1005;
const int maxn=105;
int mp[maxab][maxab];
int maxrow[maxab][maxab],maxsq[maxab][maxab];
int minrow[maxab][maxab],minsq[maxab][maxab];
int que[maxab],head,tail;
int a,b,n;
inline void InQueMax(int idx,int step,int *v)
{
	while(head<tail&&idx-que[head]>=step) head++;
	while(head<tail&&v[idx]>=v[que[tail-1]]) tail--;
	que[tail++]=idx;
}
inline void InQueMin(int idx,int step,int *v)
{
	while(head<tail&&idx-que[head]>=step) head++;
	while(head<tail&&v[idx]<=v[que[tail-1]]) tail--;
	que[tail++]=idx;
}
typedef void (*FP)(int idx,int step,int *v);
void cal(const FP &InQue,int vr[maxab][maxab],int vs[maxab][maxab])
{
	For(i,1,a)
	{
		head=tail=0;
		For(j,1,n-1) InQue(j,n,mp[i]);
		For(j,n,b)
		{
			InQue(j,n,mp[i]);
			vr[j][i]=mp[i][que[head]];
		}
	}
	For(j,n,b)
	{
		head=tail=0;
		For(i,1,n-1) InQue(i,n,vr[j]);
		For(i,n,a)
		{
			InQue(i,n,vr[j]);
			vs[i][j]=vr[j][que[head]];
		}
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	read(a,b,n);
	For(i,1,a) For(j,1,b) read(mp[i][j]);
	cal(InQueMax,maxrow,maxsq);
	cal(InQueMin,minrow,minsq);
	int res=1e9+7;
	For(i,n,a) For(j,n,b) res=min(res,maxsq[i][j]-minsq[i][j]);
	printf("%d\n",res);
	return 0;
}
/*
7 7 4
41 67 34 0 69 24 78 
58 62 64 5 45 81 27 
61 91 95 42 27 36 91 
4 2 53 92 82 21 16 
18 95 47 26 71 38 69 
12 67 99 35 94 3 11 
22 33 73 64 41 11 53 
*/
