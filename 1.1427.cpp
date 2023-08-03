#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int x; stack<int> stk;
int main()
{
	while(cin>>x,x) stk.push(x);
	while(stk.size()) { printf("%d ",stk.top()); stk.pop(); }
	puts("");
	return 0;
}
