#include<iostream>
#include<string> 
using namespace std;
struct data
{
	string sex;
	double h;
};
bool cmp(data a,data b)
{
	if(a.sex=="male")
	{
		if(b.sex=="male") return a.h<b.h;
		return 1;
	}
	else
	{
		if(b.sex=="male") return 0;
		return a.h>b.h;
	}
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
	char x;
	int n;
	scanf("%d",&n);
	data p[n],k[n];
	for(int i=0;i<n;i++) cin>>p[i].sex>>p[i].h;
	fsort(p,p+n,cmp,k);
	for(int i=0;i<n;i++) printf("%.2lf ",p[i].h);
	return 0;
}

