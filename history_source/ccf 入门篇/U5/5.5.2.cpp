#include<iostream>
using namespace std;
int main()
{
	int sr[4][4],ts,fs;
	while(true)
	{
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) cin>>sr[j][i];
		ts=fs=0;
		for(int i=0;i<4;i++) fs+=sr[i][i];
		for(int i=0;i<4;i++) ts+=sr[3-i][i];
		cout<<"左上-右下: "<<fs<<endl<<"右上-左下: "<<ts<<endl;
	}
}
