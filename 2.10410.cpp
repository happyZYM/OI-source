// Rey
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
vector<int> G[maxn];
int pos[maxn];
int main()
{
   int n;
   int t;
   while(scanf("%d",&n)==1&&n)
   {
      for(int i = 1; i <= n; i++)
         scanf("%d",&t), pos[t] = i, G[i].clear();
      int root;
      scanf("%d",&root);
      stack<int> sta;
      sta.push(root);
      for(int i = 1; i < n; i++){
         scanf("%d",&t);
         for(;;) {
            int u = sta.top();if( pos[u]+1 < pos[t] ||  (pos[u]+1 == pos[t] && u > t) || u == root  ) {
               G[u].push_back(t);
               sta.push(t);
               break;
            }else {
               sta.pop();
            }
         }

      }
      for(int i = 1; i <= n; i++) {
         printf("%d:",i);
         for(int j = 0, sz =  G[i].size(); j < sz; j++)
            printf(" %d",G[i][j]);
         puts("");
      }
   }
   return 0;
}
