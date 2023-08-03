#include<iostream>
#include<vector>
using namespace std;
struct Sr
{
	int num;
	int p=0;
};
int main()
{
	vector <int> sr1;
	vector <Sr> sr2;
	Sr li;
	int n;
	while(true)
	{
		cin>>n;
		sr1.resize(n);
		for(int i=0;i<n;i++) cin>>sr1[i];
		sr2.clear();
		for(int i=0;i<n;i++)
		{
			li.num=sr1[i];
			sr2.push_back(li);
		}
		bool b;
        for(int i=sr2.size()-1;i>0;i--)
        {
            b=1;
	        for(int j=0;j<i;j++)
	        {
	            if(sr2[j].num>sr2[j+1].num){
		            li=sr2[j];
		            sr2[j]=sr2[j+1];
		            sr2[j+1]=li;
                    b=0;
		        }	
	        }
            if(b) break;
        }
        for(int i=0;i+1<sr2.size();i++)
        {
        	if(sr2[i].num==sr2[i+1].num)
        	{
        		sr2.erase(sr2.begin()+i);
        		i--;
			}
		}
		for(int i=1;i<=sr2.size();i++) sr2[i].p=i;
		for(int i=0;i<sr1.size();i++)
		{
			for(int j=0;j<sr2.size();j++)
			{
				if(sr1[i]==sr2[j].num)
				{
					cout<<sr2[j].p+1<<" ";
					break; 
				}
			}
		}
		cout<<endl;
	}
} 
