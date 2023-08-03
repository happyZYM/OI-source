#include<iostream>
#include<string>
using namespace std;
struct Type
{
	int ID,score;
};
bool cmp(Type a,Type b)
{
	if(a.score>b.score) return 1;
	if(a.score<b.score) return 0;
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
	int n,m;
	scanf("%d%d",&n,&m);
	Type a[n],k[n];
	for(int i=0;i<n;i++) scanf("%d%d",&a[i].ID,&a[i].score);
	fsort(a,a+n,cmp,k);
	int f=a[int(m*1.5)].score;
	printf("%d ",f);
	int sum=0;
	for(int i=0;a[i].score>=f;i++) sum++;
	printf("%d\n",sum);
	for(int i=0;i<sum;i++) printf("%d %d\n",a[i].ID,a[i].score);
	return 0;
}
/*
6 3
1000 90
3239 88
2390 95
7231 84
1005 95
1001 88
*/
