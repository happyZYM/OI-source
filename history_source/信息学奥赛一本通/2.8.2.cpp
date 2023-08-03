#include<iostream>
using namespace std;
char Map[110][110];
int y,x;
void tuo(int xs,int ys)
{
	if(xs<0||xs>=x) return;
	if(ys<0||ys>=y) return;
	if(Map[xs][ys]!='W') return;
	Map[xs][ys]='.';
	for(int i=-1;i<=1;i++)
		for(int j=-1;j<=1;j++)
			tuo(xs+j,ys+i);
}
int main()
{
	int ans=0;
	cin>>y>>x;
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			cin>>Map[j][i];
	for(int i=0;i<y;i++)
		for(int j=0;j<x;j++)
			if(Map[j][i]=='W')
			{
				tuo(j,i);
				ans++;
			}
	cout<<ans<<endl;
	return 0;
}

