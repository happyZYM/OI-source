#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a<=b;
}
int *find(int *left,int *right,int n)
{
	int *mid,*p;
	p=left;
	bool f=1;
	while(left<right)
	{
		mid=left+(right-left)/2;
		if(*mid==n) 
		{
			f=0;
			left=mid;
			break;
		}
		if(*mid<n) left=mid;
		else right=mid;
	}
	if(f) return 0;
	if(*left!=n) return 0;
	while(*left==n&&left>=p) left--;
	left++;
	return left;
}
int main()
{
	int n,c;
	int ans=0;
	scanf("%d%d",&n,&c);
	int num[n];
	for(int i=0;i<n;i++) scanf("%d",num+i);
	sort(num,num+n,cmp);
	int x,*p;
	for(int i=0;i<n;i++)
	{
		x=num[i]-c;
		p=find(num,num+n,x);
		if(p!=0) while(*p==x&&p<num+n) ans++,p++;
	}
	printf("%d\n",ans);
	return 0;
} 
