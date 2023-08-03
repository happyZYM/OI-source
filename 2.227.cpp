#include<iostream>
#include<string>
#include<queue>
using namespace std;
int x,y,kase;
string mp[5],str;
char c;
int dx[]={-1,+1,+0,+0};
int dy[]={+0,+0,-1,+1};
int hsh[128];
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	hsh['A']=0;hsh['B']=1;hsh['L']=2;hsh['R']=3;
	while(1)
	{
		while(getline(cin,str),str=="");
		if(str=="Z") return 0;
		mp[0]=str;
		for(int i=1;i<5;i++) getline(cin,mp[i]);
		for(int i=0;i<5;i++)
			for(int j=0;j<5;j++)
				if(mp[i][j]==' ')
				{
					x=i;
					y=j;
					goto next;
				}
next:
		queue<char> cmd;
		while(cin>>c,c!='0') cmd.push(c);
		if(kase) cout<<endl;
		cout<<"Puzzle #"<<++kase<<":"<<endl;
		while(cmd.size())
		{
			c=hsh[cmd.front()];cmd.pop();
			if(x+dx[c]>=0&&x+dx[c]<5
			 &&y+dy[c]>=0&&y+dy[c]<5)
			{
				swap(mp[x][y],mp[x+dx[c]][y+dy[c]]);
				x+=dx[c];
				y+=dy[c];
			}
			else
			{
				cout<<"This puzzle has no final configuration."<<endl;
				goto next2;
			}
		}
		for(int i=0;i<5;i++)
		{
			cout<<mp[i][0];
			for(int j=1;j<5;j++) cout<<' '<<mp[i][j];
			cout<<endl;
		}
next2:
		continue;
	}
	return 0;
}
