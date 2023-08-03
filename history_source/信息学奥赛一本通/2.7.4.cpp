#include<cstdio>
unsigned long long ans=0;
void fsort(int *left,int *right,bool (*cmp)(int a,int b),int *k)
{
	if(right-left<=1) return;
	unsigned int len=right-left;
	fsort(left,left+len/2,cmp,k);
	fsort(left+len/2,right,cmp,k+len/2);
	int i=0,j=len/2,n=0;
	while(i<len/2&&j<len)
	{
		if(cmp(left[i],left[j])) k[n++]=left[i++];
		else 
		{
			k[n++]=left[j++];
			ans+=len/2-i;
		}
	}
	while(i<len/2) k[n++]=left[i++];
	while(j<len) k[n++]=left[j++];
	for(int i=0;i<len;i++) left[i]=k[i];
}
bool cmp(int a,int b)
{
	return a<=b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int num[n],f[n];
	for(int i=0;i<n;i++) scanf("%d",num+i);
	fsort(num,num+n,cmp,f);
	printf("%lld\n",ans);
	return 0;
}
