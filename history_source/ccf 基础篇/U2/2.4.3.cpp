#include<iostream>
#include<string>
#include<vector>
using namespace std;
void turn(string &sr)
{
	char li;
	for(int i=0,j=sr.size()-1;i<j;i++,j--)
	{
		li=sr[i];
		sr[i]=sr[j];
		sr[j]=li;
	}
}
int main()
{
	string sr,li2;
	vector <char> li;
	int p1,p2,p3;
	cin>>p1>>p2>>p3;
	cin>>sr;
	for(int i=1;i<sr.size();i++)
	{
		if(sr[i]=='-')
		{
			if(sr[i+1]-sr[i-1]==1)
			{
				sr.erase(i,1);
				i--;
				continue;
			}
			if(sr[i+1]<=sr[i-1]) continue;
			sr.erase(i,1);
			li.clear();
			for(int j=1;j+sr[i-1]<sr[i];j++)
			{
				for(int k=0;k<p2;k++)
				{
					switch(p1)
					{
						case 1:
							li.push_back(char(sr[i-1]+j));
							break;
						case 2:
							li.push_back(char(sr[i-1]+j-32));
							break;
						case 3:
							li.push_back('*');
							break;
					}
				}
			}
			li2="";
			for(int i=0;i<li.size();i++) li2+=li[i];
			if(p3==2) turn(li2);
			sr.insert(i,li2);
			i+=li.size()-1;
		}
	}
	cout<<sr<<endl;
	return 0;
}
