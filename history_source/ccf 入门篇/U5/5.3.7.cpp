#include<cstdio>
using namespace std;
struct T
{
	int ID,ch,en,ma;
};
bool cmp(T a,T b)
{
	if(a.ch+a.en+a.ma>b.ch+b.en+b.ma) return 1;
	if(a.ch+a.en+a.ma<b.ch+b.en+b.ma) return 0;
	if(a.ch>b.ch) return 1;
	if(a.ch<b.ch) return 0;
	return a.ID<b.ID;
}
template<class T_fsort>
void fsort(T_fsort *left,T_fsort *right,bool (*cmp)(T_fsort a,T_fsort b),T_fsort *k)
{
	if(right-left<=1) return;
	unsigned int len=right-left;
	fsort(left,left+len/2,cmp,k);
	fsort(left+len/2,right,cmp,k+len/2);
	int i=0,j=len/2,n=0;
	while(i<len/2&&j<len)
	{
		if(cmp(left[i],left[j])) k[n++]=left[i++];
		else k[n++]=left[j++];
	}
	while(i<len/2) k[n++]=left[i++];
	while(j<len) k[n++]=left[j++];
	for(int i=0;i<len;i++) left[i]=k[i];
}
int main()
{
	int n;
	scanf("%d",&n);
	T a[n],k[n];
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i-1].ch,&a[i-1].ma,&a[i-1].en);
		a[i-1].ID=i;
	}
	fsort(a,a+n,cmp,k);
	for(int i=0;i<5;i++) 
		printf("%d %d\n",a[i].ID,a[i].ch+a[i].ma+a[i].en);
	return 0;
}
/*
6
90 67 80
87 66 91
78 89 91 
88 99 77
67 89 64
78 89 98
*/
