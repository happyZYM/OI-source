#include<iostream>
#include<string>
#include<vector> 
using namespace std;
void turn(string &sr)
{
	for(int i=0;i<sr.size();i++) if(sr[i]>='A'&&sr[i]<='Z') sr[i]+=32;
}
int main()
{
	string find,li;
	vector <string> sr;
	char sr2;
	int add,i;
	cin>>find;
	sr2=getchar();
	sr.clear();
	li="";
	while((sr2=getchar())!='\n')
	{
		if(sr2!=' ') li+=sr2;
		else
		{
			sr.push_back(li);
			li="";
		}
	}
	turn(find);
	for(int i=0;i<sr.size();i++) turn(sr[i]);
	add=0;
	for(int i=0;i<sr.size();i++) if(sr[i]==find) add++;
	if(add!=0)
	{
		cout<<add<<" ";
		for(i=0;i<sr.size();i++) if(find==sr[i]) break;
		cout<<i<<endl;
	}
	else cout<<-1<<endl;
	return 0;
}
