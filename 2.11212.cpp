//迭代加深搜索
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 9;
int n, a[maxn];
//判断是否达到状态
bool is_sorted() {
  for(int i = 0; i < n-1; i++)
    if(a[i] >= a[i+1]) return false;
  return true;
}
//计算序列中不正确数的个数
int h() {
  int cnt = 0;
  for(int i = 0; i < n-1; i++)
    if(a[i]+1 != a[i+1]) cnt++;
  if(a[n-1] != n) cnt++;
  return cnt;
}
bool dfs(int d, int maxd) {
  if(d*3 + h() > maxd*3) return false;//剪枝
  if(is_sorted()) return true;
  int b[maxn], olda[maxn];//辅助完成剪切，插入
  memcpy(olda, a, sizeof(a));
  //确定i，j区间
  for(int i = 0; i < n; i++)
   for(int j = i; j < n; j++) {
     // cut
     int cnt = 0;
     for(int k = 0; k < n; k++)
       if(k < i || k > j) b[cnt++] = a[k];//剪切

     // insert before position k
     for(int k = 0; k <= cnt; k++) {
       int cnt2 = 0;
       for(int p = 0; p < k; p++) a[cnt2++] = b[p];
       for(int p = i; p <= j; p++) a[cnt2++] = olda[p];//插入
       for(int p = k; p < cnt; p++) a[cnt2++] = b[p];

       if(dfs(d+1, maxd)) return true;//递归搜索答案
       memcpy(a, olda, sizeof(a));
     }
   }
  return false;
}

int solve() {
  if(is_sorted()) return 0;
  int max_ans = 8;
  //控制深度
  for(int maxd = 1; maxd < max_ans; maxd++)
    if(dfs(0, maxd)) return maxd;
  return max_ans;//最坏情况
}

int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n) {
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Case %d: %d\n", ++kase, solve());
  }
  return 0;
}


