#include<iostream>
using namespace std;
struct Sr
{
	char sr[200];
	int size;
};
int main()
{
	Sr sr1,sr2;
	int size;
	while(true)
	{
		sr1.size=0;
		sr2.size=0;
		while((sr1.sr[sr1.size]=getchar())!='\n') sr1.size++;
		while((sr2.sr[sr2.size]=getchar())!='\n') sr2.size++;
		size=(sr1.size<sr2.size)?sr1.size:sr2.size;
		for(int i=0;i<size;i++) 
		{
		if(sr1.sr[i]==sr2.sr[i]) cout<<i+1<<" ";
		if(i!=0&&i%10==0) cout<<endl;
	    }
	    cout<<endl;
	}
}
