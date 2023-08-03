#include<iostream>
#include<string>
using namespace std;
struct people
{
	string name;
	int f;
};
int n;
int main()
{
	people sr[100];
	int k;
	while(true)
	{
		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>sr[i].name>>sr[i].f;
		bool b;
        people x;
        for(int i=n-1;i>0;i--)
        {
            b=1;
	        for(int j=0;j<i;j++)
	        {
	            if(sr[j].f>sr[j+1].f){
		            x=sr[j];
		            sr[j]=sr[j+1];
		            sr[j+1]=x;
                    b=0;
		        }	
	        }
        if(b) break;
        }
        cout<<endl;
        cout<<sr[k-1].name<<endl;
        cout<<endl;
	}
}
