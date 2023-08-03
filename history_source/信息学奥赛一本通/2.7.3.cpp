#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct line
{
	int L,R;
};
bool cmp(line a,line b)
{
	if(a.L<b.L) return 1;
	return 0;
}
vector <line> site;
int main()
{
    int n;
    scanf("%d",&n);
    site.resize(n);
    line a[n];
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].L,&a[i].R);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) site[i]=a[i];
    for(int i=0;i<site.size()-1;i++)
    {
    	if(site[i].R>=site[i+1].L)
    	{
    		site[i].R=(site[i].R>site[i+1].R)?site[i].R:site[i+1].R;
    		site.erase(site.begin()+i+1);
    		i=-1;
		}
	}
	if(site.size()==1) printf("%d %d",site[0].L,site[0].R);
	else printf("no");
    return 0;
}
