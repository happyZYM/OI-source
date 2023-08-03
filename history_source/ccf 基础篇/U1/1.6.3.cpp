#include<iostream>
using namespace std;
long double f_j(int sr)
{
    if(sr<0) return 0;
    if(sr==0) return 1;
    return sr*f_j(sr-1);
}
long double C(int x,int y)
{
    return f_j(x)/f_j(x-y)/f_j(y);
}
long double big_(long double a,long double b)
{
return (a>b)?a:b;
}
long double small_(long double a,long double b)
{
return (a<b)?a:b;
}
int main()
{
	int n,add;
	while(true)
	{
		cin>>n;
		add=0;
		for(int one=0;one<=n;one++)
		{
			for(int two=0;two<=n/2;two++)
			{
				if(one+two*2==n)
				{
					add+=C(big_(one,two)+small_(one,two),small_(one,two));
				}
			}
		}
		cout<<add<<endl;
	}
}
