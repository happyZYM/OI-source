#include<iostream>
using namespace std;
void beford(const string &in,const string &after)
{
    if(in.size()>0)
	{
        char ch=after.back();
        cout<<ch;
        int k=in.find(ch);
        beford(in.substr(0,k),after.substr(0,k));
        beford(in.substr(k+1),after.substr(k,in.size()-k-1));
    }
}
int main()
{
    string a,b; cin>>a>>b;
    beford(a,b); cout<<endl;
    return 0;
}
