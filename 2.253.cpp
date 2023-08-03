#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool hsh[1<<13];
char str[15];
const int mp[4][7]={
	{0,0,0,0,0,0,0},
	{0,1,3,5,2,4,6},
	{0,4,2,1,6,5,3},
	{0,2,6,3,4,1,5}
};
struct node
{
	int m[7];
	node t(int id)
	{
		node res;
		for(int i=1;i<=6;i++)
			res.m[i]=m[mp[id][i]];
		return res;
	}
};
inline int f(node n)
{
	return n.m[1]*3+n.m[2]*9+n.m[3]*27+n.m[4]*81+n.m[5]*243+n.m[6]*729;
}
queue<node> que;
void solve()
{
	memset(hsh,0,sizeof(hsh));
	while(que.size()) que.pop();
	node s,e,t;
	for(int i=0;i<6;i++)
		switch(str[i])
		{
			case 'r':
				s.m[i+1]=0;
				break;
			case 'b':
				s.m[i+1]=1;
				break;
			case 'g':
				s.m[i+1]=2;
				break;
		}
	for(int i=6;i<12;i++)
		switch(str[i])
		{
			case 'r':
				e.m[i-5]=0;
				break;
			case 'b':
				e.m[i-5]=1;
				break;
			case 'g':
				e.m[i-5]=2;
				break;
		}
	hsh[f(s)]=1;
	int so=f(e);
	if(hsh[so])
	{
		cout<<"TRUE"<<endl;
		return;
	}
	que.push(s);
	while(que.size())
	{
		for(int id=1;id<=3;id++)
		{
			t=que.front();
			for(int i=0;i<3;i++)
			{
				t=t.t(id);
				if(!hsh[f(t)])
				{
					hsh[f(t)]=1;
					if(f(t)==so)
					{
						cout<<"TRUE"<<endl;
						return;
					}
					que.push(t);
				}
			}
		}
		que.pop();
	}
	cout<<"FALSE"<<endl;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>str) solve();
	return 0;
}
