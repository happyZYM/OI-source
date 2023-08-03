#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,bu[60],res=17;
struct Bus { int bg,jg,ti; };
inline bool operator<(const Bus &a,const Bus &b) { return a.ti>b.ti; }
Bus bus[1005]; int bc;
inline bool check(int bg,int jg)
{
	for(int i=bg;i<60;i+=jg) if(!bu[i]) return false;
	return true;
}
void dfs(int cho,int lst,int pos)
{
	if(cho+lst/bus[pos].ti>=res) return;
	if(!lst) { res=min(res,cho); return; }
	for(int i=pos;i<=bc;i++)
	{
		if(!check(bus[i].bg,bus[i].jg)) continue;
		for(int j=bus[i].bg;j<60;j+=bus[i].jg) bu[j]--;
		dfs(cho+1,lst-bus[i].ti,i);
		for(int j=bus[i].bg;j<60;j+=bus[i].jg) bu[j]++;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++) { int x; scanf("%d",&x); bu[x]++; }
	for(int i=0;i<30;i++)
		for(int j=i+1;i+j<60;j++)
			if(check(i,j))
			{
				bus[++bc]=(Bus){i,j,0};
				for(int k=i;k<60;k+=j) bus[bc].ti++;
			}
	sort(bus+1,bus+bc+1);
	dfs(0,n,1);
	printf("%d\n",res);
	return 0;
}
