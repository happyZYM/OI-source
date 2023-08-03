#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int maxn=30;
int n;
vector<int> pile[maxn];
void find_block(int a,int& p,int& h)
{
	for(p=0;p<n;p++)
		for(h=0;h<pile[p].size();h++)
			if(pile[p][h]==a) return;
}
void clear_above(int p,int h)
{
	for(int i=h+1;i<pile[p].size();i++)
		pile[pile[p][i]].push_back(pile[p][i]);
	pile[p].resize(h+1);
}
void pile_onto(int p1,int h,int p2)
{
	for(int i=h;i<pile[p1].size();i++)
		pile[p2].push_back(pile[p1][i]);
	pile[p1].resize(h);
}
void print()
{
	for(int i=0;i<n;i++)
	{
		cout<<i<<':';
		for(int j=0;j<pile[i].size();j++) cout<<' '<<pile[i][j];
		cout<<endl;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int a,b,pa,pb,ha,hb;
	cin>>n;
	string s1,s2;
	for(int i=0;i<n;i++) pile[i].push_back(i);
	while(cin>>s1>>a>>s2>>b)
	{
		find_block(a,pa,ha);
		find_block(b,pb,hb);
		if(pa==pb) continue;
		if(s2=="onto") clear_above(pb,hb);
		if(s1=="move") clear_above(pa,ha);
		pile_onto(pa,ha,pb);
	}
	print();
	return 0;
}
