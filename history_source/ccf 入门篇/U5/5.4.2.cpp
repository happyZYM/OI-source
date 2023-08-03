#include<iostream>
#include<vector>
struct Word
{
	int b;
	int size;
};
using namespace std;
int main()
{
	vector <char> sr;
	Word l;
	char in_;
	vector <Word> so;
	Word x;
	while(true)
	{
		sr.clear();
		so.clear();
		do
		{
			sr.push_back(' ');
		}
		while((sr[sr.size()-1]=getchar())!='.');
		sr.pop_back();
		l.b=0;
		l.size=0;
		so.push_back(l);
		for(int i=0;i<sr.size();i++)
		{
			if(sr[i]==' '){
				l.b=i+1;
				l.size=0;
				so.push_back(l);
			}
			else so[so.size()-1].size++;
		}
        for(int i=so.size()-1;i>0;i--)
        {
	        for(int j=0;j<i;j++)
	        {
	            if(so[j].size>so[j+1].size){
		            x=so[j];
		            so[j]=so[j+1];
		            so[j+1]=x;
		        }	
	        }
        }
        for(int i=so[0].b;sr[i]!=' ';i++) cout<<sr[i];
        cout<<endl;
	}
}
