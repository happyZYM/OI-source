#include<iostream>
using namespace std;
struct data
{
	int ID;
	int score;
};
bool cmp(data a,data b)
{
	if(a.score>b.score) return 1;
	if(a.score<b.score) return 0;
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
	int n,m;
	cin>>n>>m;
	data p[n],k[n];
	for(int i=0;i<n;i++) cin>>p[i].ID>>p[i].score;
	fsort(p,p+n,cmp,k);
	int f=p[int((double)m*1.5)-1].score;
	cout<<f<<" ";
	int add=0;
	while(p[add].score>=f) add++;
	cout<<add<<endl;
	for(int i=0;i<add;i++) cout<<p[i].ID<<" "<<p[i].score<<endl;
	return 0;
}

