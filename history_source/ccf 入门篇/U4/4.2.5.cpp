#include<iostream>
#include<cmath>
using namespace std;
int k;
long long n;
long double f(long long n)
{
	long double s=0;
	for(int i=1;i<=n;i++)
	{
		s=s+1.0/i;
	}
	return s;
}
int main()
{
	while(true)
	{
		cin>>k;
		if(k>=10) n=pow(k,4);
		else{
		if(k>=6) n=pow(k,3);
		else n=k*k;
	    }
	    if(k<12){
		while(f(n)<=k)n+=3;
		if(f(n-1)>k) 
		{if(f(n-2)>k) cout<<n-2<<endl;
		else cout<<n-1<<endl;}
		else cout<<n<<endl;}
		else {
			if(k>=14) n=pow(k,5);
			if(k>=15) while(f(n)<=k) n+=4096;
			else while(f(n)<=k) n+=2048;
			if(f(n-2048)>k) n-=2048;
			if(f(n-1024)>k) n-=1024;
			if(f(n-512)>k) n-=512;
			if(f(n-256)>k) n-=256;
			if(f(n-128)>k) n-=128;
			if(f(n-64)>k) n-=64;
			if(f(n-32)>k) n-=32;
			if(f(n-16)>k) n-=16;
			while(f(n)>k) n--;
			n++;
			cout<<n<<endl;
		}
	}
}
