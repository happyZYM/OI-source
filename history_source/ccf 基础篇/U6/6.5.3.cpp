#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
long double str_num(string sr)
{
	stringstream li;
	li<<sr;
	long double ans;
	li>>ans;
	return ans;
}
string num_str(long double sr)
{
	stringstream li;
	li<<sr;
	string ans;
	li>>ans;
	return ans;
}
int main()
{
	vector <string> sr;
	char li;
	while(true)
	{
		sr.resize(1);
		sr[0]="";
		while((li=getchar())!='\n')
		{
			if(li!=' ') sr[sr.size()-1]+=li;
			else 
			{
				sr.push_back("");
			}
		}
		for(int i=sr.size()-1;i>=0;i--)
		{
			if(sr[i]=="+"||sr[i]=="-"||sr[i]=="*"||sr[i]=="/")
			{
				if(sr[i]=="+")
				{
					sr[i]=num_str(str_num(sr[i+1])+str_num(sr[i+2]));
					sr.erase(sr.begin()+i+1);
					sr.erase(sr.begin()+i+1);
				}
				if(sr[i]=="-")
				{
					sr[i]=num_str(str_num(sr[i+1])-str_num(sr[i+2]));
					sr.erase(sr.begin()+i+1);
					sr.erase(sr.begin()+i+1);
				}
				if(sr[i]=="*")
				{
					sr[i]=num_str(str_num(sr[i+1])*str_num(sr[i+2]));
					sr.erase(sr.begin()+i+1);
					sr.erase(sr.begin()+i+1);
				}
				if(sr[i]=="/")
				{
					sr[i]=num_str(str_num(sr[i+1])/str_num(sr[i+2]));
					sr.erase(sr.begin()+i+1);
					sr.erase(sr.begin()+i+1);
				}
			}
		}
		cout<<sr[0];
	}
}
