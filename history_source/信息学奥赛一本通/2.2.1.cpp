#include<cstdio>
using namespace std;
struct data
{
	long long g;
	double score;
};
bool cmp(data a,data b)
{
	return a.score>b.score;
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
	int n,k;
	scanf("%d%d",&n,&k);
	data stu[n],b[n];
	for(int i=0;i<n;i++) scanf("%lld%lf",&stu[i].g,&stu[i].score);
	fsort(stu,stu+n,cmp,b);
	printf("%lld %g\n",stu[k-1].g,stu[k-1].score);
	return 0;
}
