#include<cstdio>
#include<algorithm>
using namespace std;
struct node { int h,w; };
inline bool operator<(const node &a,const node &b) { return a.w<b.w; } 
int n,s,h,x;
node ap[5005];
int main()
{
	scanf("%d%d",&n,&s);
	scanf("%d%d",&h,&x); h+=x;
	for(int i=0;i<n;i++) scanf("%d%d",&ap[i].h,&ap[i].w);
	sort(ap,ap+n);
	int res=0;
	for(int i=0;i<n;i++)
		if(s>=ap[i].w&&h>=ap[i].h)
		{
			s-=ap[i].w;
			res++;
		}
	printf("%d\n",res);
	return 0;
}
