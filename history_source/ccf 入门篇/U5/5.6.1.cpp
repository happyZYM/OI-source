#include<iostream>
using namespace std;
#include<string>
struct passengers
{
	string sex;
	double high;
};
int main()
{
    passengers sr[40];
    passengers li;
    bool li2;
    int n;
    while(true)
    {
    	cin>>n;
    	for(int i=0;i<n;i++) cin>>sr[i].sex>>sr[i].high;
    	do
    	{
    	li2=0;
    	for(int i=0;i<n-1;i++)
    	{
    		if(sr[i].sex=="female"&&sr[i+1].sex=="male")
    		{
    			li2=1;
    			li=sr[i];
    			sr[i]=sr[i+1];
    			sr[i+1]=li;
			}
		}
	    }
	    while(li2);
	    int male;
	    for(male=0;sr[male].sex=="male";male++);
	    male--;
	    do
    	{
    	li2=0;
    	for(int i=0;i<male;i++)
    	{
    		if(sr[i].high>sr[i+1].high)
    		{
    			li2=1;
    			li=sr[i];
    			sr[i]=sr[i+1];
    			sr[i+1]=li;
			}
		}
	    }
	    while(li2);
	    do
    	{
    	li2=0;
    	for(int i=male+1;i<n-1;i++)
    	{
    		if(sr[i].high<sr[i+1].high)
    		{
    			li2=1;
    			li=sr[i];
    			sr[i]=sr[i+1];
    			sr[i+1]=li;
			}
		}
	    }
	    while(li2);
	    for(int i=0;i<n;i++) cout<<sr[i].high<<" ";
	    cout<<endl;
	}
}
