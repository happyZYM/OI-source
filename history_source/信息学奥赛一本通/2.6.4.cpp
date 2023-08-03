#include<cstdio>
using namespace std;
int s1,s2,s3,s4,s5,s6,res;
void solve()
{
	res=s6+s5+s4;
	//6
	s1-=s5*11;
	if(s1<0) s1=0;
	//5
	s2-=s4*5;
	if(s2<0)
	{
		s1=s1+s2*4;
		if(s1<0) s1=0;
		s2=0;
	}
	//4
	res+=s3/4;
	if(s3%4) res++;
	switch(s3%4)
	{
		case 0:
			break;
		case 1:
			s2-=5;
			s1-=7;
			if(s1<0) s1=0;
			if(s2<0) s2=0;
			break;
		case 2:
			s2-=3;
			s1-=6;
			if(s1<0) s1=0;
			if(s2<0) s2=0;
			break;
		case 3:
			s2--;
			s1-=5;
			if(s1<0) s1=0;
			if(s2<0) s2=0;
			break;
	}
	//3
	res+=s2/9;
	if(s2%9)
	{
		res++;
		s1=s1-(9-s2%9)*4;
		if(s1<0) s1=0;
	}
	//2
	res+=s1/36;
	if(s1%36) res++;
	//1
	printf("%d\n",res);
}
int main()
{
	while(1)
	{
		scanf("%d%d%d%d%d%d",&s1,&s2,&s3,&s4,&s5,&s6);
		if(!s1&&!s2&&!s3&&!s4&&!s5&&!s6) return 0;
		solve();
	}
	return 0;
}
/*
0 0 4 0 0 1 
7 5 1 0 0 0 
0 0 0 0 0 0 
*/
