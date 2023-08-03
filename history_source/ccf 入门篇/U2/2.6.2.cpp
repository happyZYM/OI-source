#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	while(true){
	  double R,X,P;
	  cin>>X>>R>>P;
	  cout<<P<<"年后本利合为"<<X*pow(1+R/100.0,P)<<endl;
    }
	
}
