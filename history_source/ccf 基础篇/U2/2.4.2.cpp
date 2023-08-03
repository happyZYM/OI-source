#include<iostream>
using namespace std;
int main()
{
	int num[26],b;
	char sr;
	for(int i=0;i<26;i++) num[i]=0;
	while((sr=getchar())!='\n') if(sr>='A'&&sr<='Z') num[sr-'A']++;
	while((sr=getchar())!='\n') if(sr>='A'&&sr<='Z') num[sr-'A']++;
	while((sr=getchar())!='\n') if(sr>='A'&&sr<='Z') num[sr-'A']++;
	while((sr=getchar())!='\n') if(sr>='A'&&sr<='Z') num[sr-'A']++;
	b=num[0];
	for(int i=0;i<26;i++) if(num[i]>b) b=num[i];
	for(int i=b;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		if(num[j]>i) cout<<"* ";
		else cout<<"  ";
		cout<<endl;
	}
	for(int i=0;i<26;i++) cout<<char(i+'A')<<" ";
	cout<<endl; 
	return 0;
}
