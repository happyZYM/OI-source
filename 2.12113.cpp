#include <bits/stdc++.h>
using namespace std;
const int N=10,M=5;
char s[N+5][N+5],now[N+5][N+5];
char square[M+5][M+5];
void init()
{
    for (int i = 0;i <3;i++)
        for (int j = 0;j<5;j++)
            square[i][j] = ' ';
    for (int i = 0;i < 2;i++) square[i+1][0] = square[i+1][4] = '|';
    for (int j = 1;j < 5;j+=2) square[0][j]=square[2][j] = '_';
}
void Set(int x,int y)
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 5;j++)
		{
            if (i<=0 && now[i+x][j+y]!=' ' && square[i][j]==' ') continue;
            now[i+x][j+y] = square[i][j];
        }
    for (int i = 1;i < 2;i++)
        for (int j = 1;j<4;j++)
            now[i+x][j+y] = ' ';
}
bool ok()
{
    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 9;j++)
            if (now[i][j]!=s[i][j])
                return false;
    return true;
}
void out()
{
    for (int i = 0;i < 5;i++)
	{
        for (int j = 0;j < 9;j++)
            cout <<now[i][j];
        cout << endl;
    }
    cout << endl;
}
bool dfs(int dep)
{
    if (dep > 1 && ok()) return true;
    if (dep >= 7) return false;
    int temp[M+5][M+5];
    for (int i = 0;i < 3;i++)
	{
        for (int j = 0;j < 5;j+=2)
		{
            for (int k = 0;k <3;k++)
                for (int l = 0;l < 5;l++)
                    temp[k][l] = now[k+i][l+j];
            Set(i,j);
            if (dfs(dep+1)) return true;
            for (int k = 0;k <3;k++)
                for (int l = 0;l < 5;l++)
                    now[k+i][l+j] = temp[k][l];
        }
    }
    return false;
}
int main()
{
#ifdef local
    freopen("pro.in", "r", stdin);
#endif
    ios::sync_with_stdio(0),cin.tie(0);
    init();
    int kase = 0;
    while(1)
	{
        for(int i=0;i< 5;i++)
		{
            cin.getline(s[i],15);
            if (s[i][0]=='0') return 0;
        }
        for (int i = 0;i< 5;i++)
            for (int j = 0;j < 9;j++)
                now[i][j] = ' ';
        if (dfs(1))
            cout <<"Case "<<++kase<<": Yes"<<endl;
        else
            cout <<"Case "<<++kase<<": No"<<endl;
    }
    return 0;
}
