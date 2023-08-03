#include<cstdio>
using namespace std;
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
bool cmp(int a,int b)
{
	return a<=b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int num[n],b[n];
	for(int i=0;i<n;i++) scanf("%d",num+i);
	fsort(num,num+n,cmp,b);
	bool f=0;
	for(int i=0;i<n;i++) 
	{
		if(num[i]&1)
		{
			if(f) printf(",");
			f=1;
			printf("%d",num[i]);
		}
	}
	printf("\n");
	return 0;
}

