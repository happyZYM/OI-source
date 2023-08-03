#include<iostream>
#include<string> 
using namespace std;
struct input
{
	string name;
	int score;
};
int main()
{
	int n;
	cin>>n;
	input sr[n];
	for(int i=0;i<n;i++) cin>>sr[i].score>>sr[i].name;
	input ans=sr[0];
	for(int i=1;i<n;i++)
		if(sr[i].score>ans.score) ans=sr[i];
	cout<<ans.name<<endl;
	return 0;
}
