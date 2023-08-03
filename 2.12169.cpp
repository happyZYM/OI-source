#include<iostream>
using namespace std;
const int Mod=10001;
int T,x[105];
int p,q,r,s,a,tmp,i,j;
void exgcd(int a,int tmp,int &x,int &y)
{
	if(!tmp) x=1,y=0;
	else
	{
		exgcd(tmp,a%tmp,y,x);
		y-=x*(a/tmp);
	}
}
void solve()
{
	for(a=0;a<=10000;a++)
	{
		p=(a+1)%Mod,q=10001,r=0,s=0;
		exgcd(p,q,r,s);
		r=(x[1]-a*a%Mod*x[0]%Mod+Mod)%Mod*r%Mod;
		tmp=(a*x[0]+r)%Mod;
		for(i=1;i<T;i++)
		{
			int flag=(a*tmp+r)%Mod;
			if(x[i]!=flag) break;
			tmp=(a*x[i]+r)%Mod;
		}
		if(i==T)
		{
			for(j=0;j<T;j++)
			printf("%d\n",(a*x[j]+r)%Mod);
			break;
		}
	}
}
int main()
{
	cin>>T;
	for(i=0;i<T;i++) cin>>x[i];
	solve();
	return 0;
}
