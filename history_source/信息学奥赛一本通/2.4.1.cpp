#include<iostream>
#include<string>
#include<math.h>
using namespace std;
bool isop(string n)
{
	if(n=="+") return 1;
	if(n=="-") return 1;
	if(n=="*") return 1;
	if(n=="/") return 1;
	return 0;
}
double operation()
{
	string sr;
	cin>>sr;
	if(!isop(sr)) return atof(sr.c_str());
	switch(sr[0])
	{
		case '+': return operation()+operation();
		case '-': return operation()-operation();
		case '*': return operation()*operation();
		case '/': return operation()/operation();
	}
}
int main()
{
	printf("%.6lf\n",operation());
	return 0;
}
