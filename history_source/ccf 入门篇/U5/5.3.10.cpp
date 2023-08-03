#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m,find,j,w;
	long long sr1[100000],sr2[10000];
	while(true)
	{
		cin>>n;
		for(int i=0;i<n;i++) cin>>sr1[i];
		//===================================
		bool b;
        double x;
        for(int i=n-1;i>0;i--)
        {
            b=1;
	        for(int j=0;j<i;j++)
	        {
	            if(sr1[j]>sr1[j+1]){
		            x=sr1[j];
		            sr1[j]=sr1[j+1];
		            sr1[j+1]=x;
                    b=0;
		        }	
	        }
            if(b) break;
        }
        //=======================================
		cin>>m;
		for(int i=0;i<m;i++) cin>>sr2[i];
		for(int ii=0;ii<m;ii++)
		{
			find=sr2[ii];
			w=n-1;
			j=sr1[w]-find;
			j=abs(j);
			for(int i=n-2;i>=0;i--)
			{
				if(abs(sr1[i]-find)<j)
				{
					j=abs(sr1[i]-find);
					w=i;
				}
			}
			cout<<sr1[w]<<endl;
		}
	}
}
