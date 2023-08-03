#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int a[10][10],flag[10][10],count;
int step[10][3] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
int BFS(int x1, int y1, int x2, int y2)
{
    int tail = 1, head = 0, list[100][3], ct[100];
    list[head][0] = x1;
    list[head][1] = y1;
    flag[x1][y1] = 1;
    ct[head] = 0;
    while(head < tail)
    {
        for(int i =  0; i<8; i++)
        {
            int fx = step[i][0] + list[head][0], fy = step[i][1] + list[head][1];
            if(fx > 0 && fx <= 8 && fy > 0 && fy <= 8 && !flag[fx][fy]){
                if(fx == x2 && fy == y2) return count = ct[head] + 1;
                list[tail][0] = fx;
                list[tail][1] = fy;
                ct[tail++] = ct[head]+1;
                flag[fx][fy] = 1;
            }
        }
        head++;
    }
    return 0;
}
int main()
{
    int m,n;
    char km, kn;
    while(scanf("%c%d %c%d", &km, &m, &kn, &n) != EOF) {
        getchar();
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));
        int x1 = km - 'a' + 1, y1 = m, x2 = kn - 'a'+1, y2 = n;
        count = 0;
        count = BFS(x1, y1, x2, y2);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",km,m,kn,n,count);
    }
    return 0;
}

