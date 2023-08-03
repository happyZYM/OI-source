#include<iostream>
#include<string>
using namespace std; 
string sr1;
short T1[52],T2[52];
int hash_(char n)
{
	if(n>='A'&&n<='Z') return n-'A';
	return n-'a'+26;
}
void insert(char a){T2[hash_(a)]++;}
void delete_(char a)
{
	T2[hash_(a)]--;
	if(T2[hash_(a)]<0) T2[hash_(a)]=0;
}
bool check()
{
	for(int i=0;i<52;i++) if(T1[i]!=T2[i]) return 0;
	return 1;
}
struct Node
{
	char c;
	Node *next;
};
int main()
{
	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(0);
	int ans=0;
	cin>>sr1;
	for(int i=0;i<sr1.size();i++)
	{
		if(sr1[i]>='A'&&sr1[i]<='Z') T1[sr1[i]-'A']++;
		else T1[sr1[i]-'a'+26]++;
	}
	char ch;
	Node *head,*last;
	last=head=new Node;
	for(int i=0;i<sr1.size();i++)
	{
		ch=getchar();
		insert(ch);
		last->c=ch;
		last->next=new Node;
		last=last->next;
	}
	last->next=head;
	if(check()) ans++;
	while(ch=getchar(),ch!='\n')
	{
		delete_(head->c);
		head=head->next;
		last->c=ch;
		last=last->next;
		insert(ch);
		if(check()) ans++;
	} 
	cout<<ans<<endl;
	return 0;
}
