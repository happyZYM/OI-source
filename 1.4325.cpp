#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
set<int> st;
int main()
{
	int x;
	while(cin>>x) st.insert(x%42);
	cout<<st.size()<<endl;
	return 0;
}
