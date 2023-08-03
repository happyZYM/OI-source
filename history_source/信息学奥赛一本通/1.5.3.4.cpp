#include<iostream>
#include<string>
#include<cstring> 
using namespace std;
int hash_(string n)
{
	if(n=="Rock") return 0;
	if(n=="Scissors") return 1;
	if(n=="Paper") return 2;
}
int main()
{
	int n;
	cin>>n;
	short ans[n];
	string a,b;
	short win[3][3];
	memset(win,-1,sizeof(win));
	win[0][0]=win[1][1]=win[2][2]=0;
	win[0][1]=win[1][2]=win[2][0]=1;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		ans[i]=win[hash_(a)][hash_(b)];
	}
	for(int i=0;i<n;i++)
	{
		if(!ans[i]) cout<<"Tie"<<endl;
		if(ans[i]==-1) cout<<"Player2"<<endl;
		if(ans[i]==1) cout<<"Player1"<<endl;
	}
	return 0;
}

