#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int v[11][11],h[11][11];
	int m,n,k=0;
	while(k++,cin>>n>>m)
	{
		bool noans=true;
		memset(v,0,sizeof(v));
		memset(h,0,sizeof(h));
		char mode;
		int a,b;
		for(int i=0;i<m;i++)
		{
			cin>>mode>>a>>b;
			if(mode=='H')
				h[a][b]++;
			else
				v[b][a]++;
		}
		if(k!=1)
			cout<<endl<<"**********************************"<<endl<<endl;
		cout<<"Problem #"<<k<<endl<<endl;
		for(int s=1;s<n;s++)
		{
			int cont=0;
			for(int i=1;i<=n-s;i++)
				for(int j=1;j<=n-s;j++)
				{
					bool mark=true;
					for(int x=i,y=j;mark&&x<i+s;x++)
						if(!v[x][y]||!v[x][y+s])
							mark=false;
					for(int x=i,y=j;mark&&y<j+s;y++)
						if(!h[x][y]||!h[x+s][y])
							mark=false;
					if(mark)
						cont++;
				}
			if(cont)
			{
				cout<<cont<<" square (s) of size "<<s<<endl;
				noans=false;
			}
		}
		if(noans)
			cout<<"No completed squares can be found."<<endl;
	}
	return 0;
}
/*
4
16
H 1 1
H 1 3
H 2 1
H 2 2
H 2 3
H 3 2
H 4 2
H 4 3
V 1 1
V 2 1
V 2 2
V 2 3
V 3 2
V 4 1
V 4 2
V 4 3
2
3
H 1 1
H 2 1
V 2 1
*/
