#include<iostream>
#include<string> 
using namespace std;
bool cmp(string a,string b)
{
	return a<b; 
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
	int len=0;
	string k[110],w[110];
	char x,a=' ';
	while(x=getchar(),x!='\n')
	{
		if(x!=' ') w[len]+=x;
		else if(a!=' ') len++;
		a=x;
	}
	if(w[len]!="") len++;
	fsort(w,w+len,cmp,k);
	cout<<w[0]<<endl;
	for(int i=1;i<len;i++) if(w[i]!=w[i-1]) cout<<w[i]<<endl;
	return 0;
}
