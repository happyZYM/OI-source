#include<cstdio>
using namespace std;
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
long long nums[200000],k[200000];
bool cmp(long long a,long long b)
{
	return a<=b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",nums+i);
	fsort(nums,nums+n,cmp,k); 
	long long num,times;
	num=nums[0];
	printf("%lld ",num);
	times=1;
	for(int i=1;i<n;i++)
	{
		if(num!=nums[i])
		{
			printf("%lld\n",times);
			num=nums[i];
			printf("%lld ",num);
			times=1;
		}
		else times++;
	}
	printf("%lld\n",times);
	return 0;
}
