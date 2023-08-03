#include<iostream>
using namespace std;
int sr[5][5];
bool pan(int x,int y)
{
	int text=sr[x][y];
	for(int i=0;i<5;i++) if(sr[i][y]>text) return 0;
	for(int i=0;i<5;i++) if(sr[x][i]<text) return 0;
	return 1;
}
int main()
{
	bool find;
	while(true)
	{
	    for(int i=0;i<5;i++) for(int j=0;j<5;j++) cin>>sr[j][i];
	    find=1;
	    for(int i=0;i<5;i++)
	    {
	    	for(int j=0;j<5;j++)
	    	{
	    		if(pan(j,i))
	    		{
	    			cout<<i+1<<" "<<j+1<<" "<<sr[j][i]<<endl;
	    			find=0;
	    			break;
				}
			}
			if(!find) break;
		}
		if(find) cout<<"not find"<<endl;
	}
}
