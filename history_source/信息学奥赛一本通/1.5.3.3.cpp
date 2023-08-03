#include<iostream>
#include<string>
using namespace std;
int main()
{
	string dna1,dna2;
	double f,b=0;
	cin>>f;
	cin>>dna1>>dna2;
	for(int i=0;i<dna1.size();i++)
		if(dna1[i]==dna2[i]) b=b+1;
	b=b/dna1.size();
	if(b>=f) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}

