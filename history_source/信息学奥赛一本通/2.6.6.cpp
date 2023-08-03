#include<cstdio>
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
bool cmp(int a,int b)
{
	return a>=b;
}
int main()
{
	int b,n;
	scanf("%d%d",&n,&b);
	int hi[n],k[n];
	for(int i=0;i<n;i++) scanf("%d",hi+i);
	fsort(hi,hi+n,cmp,k);
	int ans=0;
	while(b>0)
	{
		b-=hi[ans];
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
