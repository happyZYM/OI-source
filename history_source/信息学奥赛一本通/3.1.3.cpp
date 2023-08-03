#include<iostream>
#include<string>
#include<map>
using namespace std;
char stack[260]={'s','\0'},li;
int top=1;
map<char,int>f;
bool answer(string a)
{
	top=1;
	for(int i=0;i<a.size();i++)
	{
		switch(a[i])
		{
			case '(':stack[top++]='(';
			if(f[stack[top-1]]>f[stack[top-2]]) return 0;
			break;
			case '[':stack[top++]='[';
			if(f[stack[top-1]]>f[stack[top-2]]) return 0;
			break;
			case '{':stack[top++]='{';
			if(f[stack[top-1]]>f[stack[top-2]]) return 0;
			break;
			case '<':stack[top++]='<';
			if(f[stack[top-1]]>f[stack[top-2]]) return 0;
			break;
			case ')':
				if(stack[top-1]=='(') top--;
				else return 0;
				break;
			case ']':
				if(stack[top-1]=='[') top--;
				else return 0;
				break;
			case '}':
				if(stack[top-1]=='{') top--;
				else return 0;
				break;
			case '>':
				if(stack[top-1]=='<') top--;
				else return 0;
				break;
		}
	}
	if(top==1) return 1;
	return 0;
}
int main()
{
	f['<']=0;f['>']=4;
	f['(']=1;f[')']=4;
	f['[']=2;f[']']=4;
	f['{']=3;f['}']=4;
	f['s']=5;
	int n;
	cin>>n;
	bool ans[n];
	string li;
	getline(cin,li);
	for(int i=0;i<n;i++) 
	{
		getline(cin,li);
		ans[i]=answer(li);
	}
	for(int i=0;i<n;i++) 
	{
		if(ans[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
