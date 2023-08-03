#include <iostream>
#include <cstdio>
#include <cstring>
#define Clean(x, y) memset(x, y, sizeof(x))
//#define rep(i, j, k) for (int i = j; i <= k; i++)
//#define Rrep(i, j, k) for (int i = j; i >= k; i--)
using namespace std;

int np, nt, nf, tp;
const int N = 105;
int num[N];
int input[N][N], output[N][N];
int Inum[N][N];
int find (int x, int k)
{
	for(int i=1;i<=input[x][0];i++)
		if ( input[x][i] == k) return i;
	return -1;
}
void init()
{
	Clean(num, 0);
	Clean(input, 0);
	Clean(output, 0);
	Clean(Inum, 0);
	
	for(int i=1;i<=np;i++)
		scanf("%d", num + i);
	scanf("%d", &nt);
	for(int i=1;i<=nt;i++)
	{
		while (scanf("%d", &tp), tp)
		{
			if ( tp < 0 )
			{
				int p = find(i, -tp);
				if ( p != -1 ) Inum[i][p]++;
				else
				{
					input[i][++input[i][0]] = -tp;
					Inum[i][input[i][0]] = 1;
				}
			}
			else output[i][ ++output[i][0] ] = tp;
		}
	}
	scanf("%d", &nf);
}

bool check (int x)
{
	for(int i=1;i<=input[x][0];i++)
		if ( num [ input[x][i] ] < Inum[x][i] ) return false;
	return true;
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int kase = 0;
	while ( cin >> np && np != 0)
	{
		init();
		int step = 0;
		bool can = true;
		while (can && step < nf)
		{
			can = false;
			for(int k=1;k<=nt;k++)
			{
				if ( step < nf && check(k) )
				{
					can = true;
					step++;
					for(int i=1;i<=input[k][0];i++)
						num[ input[k][i] ] -= Inum[k][i];
					for(int i=1;i<=output[k][0];i++)
						num[ output[k][i] ]++;
				} 
			}
		}
		printf("Case %d: ",++kase);
    	if ( step == nf ) printf("still live after %d transitions\n",nf);
   		else printf("dead after %d transitions\n",step);
    	printf("Places with tokens:"); 
    	for(int i=1;i<=np;i++)
        	if (num[i]) printf(" %d (%d)",i,num[i]);
    	printf("\n\n");
	}
	return 0;
}
