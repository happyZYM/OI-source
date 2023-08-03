#include<iostream>
using namespace std;
int area=0;
bool Map[10][10]={0};
int dx[]={0,0,-1,1},
	dy[]={-1,1,0,0};
void tuo(int x,int y)
{
	if(x<0||x>=10) return;
	if(y<0||y>=10) return;
	if(Map[x][y]) return;
	area++;
	Map[x][y]=1;
	for(int i=0;i<4;i++)
		tuo(x+dx[i],y+dy[i]);
}
int main()
{
	int one=0,ans;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			cin>>Map[j][i];
			one+=Map[j][i];
		}
	for(int i=0;i<10;i++)
	{
		if(Map[i][0]==0) tuo(i,0);
		if(Map[i][9]==0) tuo(i,9);
		if(Map[0][i]==0) tuo(0,i);
		if(Map[9][i]==0) tuo(9,i);
	}
	ans=100-area-one;
//	cout<<"area: "<<area<<endl;
//	cout<<"one: "<<one<<endl;
	cout<<ans<<endl;
	return 0;
}
