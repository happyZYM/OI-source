#include<cstdio>
#include<cstring>
const int UP   =0;
const int LEFT =1;
const int RIGHT=2;
const int DOWN =3;
const int maxn =70+5;
int d[maxn][4][4][3];
int action[maxn][4][4][3]; 
char str[maxn],hsh[128],fth[]=".LR";
inline int energy(int a,int ta)
{
	if(a==ta) return 3;
	if(a+ta==3) return 7;
	return 5;
}
int energy(int i,int a,int b,int s,int f,int t,int& ta,int& tb)
{
	ta=a;tb=b;
	if(f==1) ta=t;
	else if(f==2) tb=t;
	
	if(ta==tb) return -1;//the same position
	if(ta==RIGHT&&tb==LEFT) return -1;//turned around
	if(a==RIGHT&&tb!=b) return -1;
	if(b==LEFT&&ta!=a) return -1;//bad action
	
	int e;
	if(f==0) e=0;
	else if(f!=s) e=1;
	else
	{
		if(f==1) e=energy(a,ta);
		else e=energy(b,tb);
	}
	return e;
}
void update(int i,int a,int b,int s,int f,int t)
{
	int ta,tb;
	int e=energy(i,a,b,s,f,t,ta,tb);
	if(e<0) return;//bad action
	int cost=d[i+1][ta][tb][f]+e;
	int &res=d[i][a][b][s];
	if(cost<res)
	{
		res=cost;
		action[i][a][b][s]=f*4+t;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	hsh['U'] = 0; hsh['L'] = 1; hsh['R'] = 2; hsh['D'] = 3;
	int i,a,b,s,t;
	while(scanf("%s",str)==1)
	{
		if(str[0]=='#') break;
		int n=strlen(str);
		memset(d,0,sizeof(d));
		for(i=n-1;i>=0;i--)
			for(a=0;a<4;a++)
				for(b=0;b<4;b++)
					if(a!=b)
						for(s=0;s<3;s++)
						{
							d[i][a][b][s]=10*n;
							if(str[i]=='.')
							{
								update(i,a,b,s,0,0);
								for(t=0;t<4;t++)
								{
									update(i,a,b,s,LEFT ,t);
									update(i,a,b,s,RIGHT,t);
								}
							}
							else
							{
								update(i,a,b,s,LEFT ,hsh[str[i]]);
								update(i,a,b,s,RIGHT,hsh[str[i]]);
							}
						}
		
		a=LEFT,b=RIGHT,s=0;
		for(i=0;i<n;i++)
		{
			int f=action[i][a][b][s]/4;
			int t=action[i][a][b][s]%4;
			putchar(fth[f]);
			s=f;
			if(f==1) a=t;
			else if(f==2) b=t;
		}
		printf("\n");
	}
	return 0;
}
