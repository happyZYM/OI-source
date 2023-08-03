#include<cstdio>
using namespace std;
struct data
{
	int ID;
	int ch,ma,en;
};
bool cmp(data a,data b)
{
	if(a.ch+a.en+a.ma>b.ch+b.ma+b.en) return 1;
	if(a.ch+a.en+a.ma<b.ch+b.ma+b.en) return 0;
	if(a.ch>b.ch) return 1;
	if(a.ch<b.ch) return 0;
	return a.ID<b.ID;
}
template<class T>
void fsort(T *left,T *right,bool (*cmp)(T a,T b),T *k)
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
	data stu[n],b[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&stu[i].ch,&stu[i].ma,&stu[i].en);
		stu[i].ID=i+1;
	}
	fsort(stu,stu+n,cmp,b);
	for(int i=0;i<5;i++) printf("%d %d\n",stu[i].ID,stu[i].en+stu[i].ch+stu[i].ma);
	return 0;
}

