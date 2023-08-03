#include<bits/stdc++.h>
using namespace std;
#define lrt rt<<1
#define rrt rt<<1|1
typedef struct Node
{
    int lo, hi, sum;
    int add, put;
}Node;
const int maxn = 22;
const int maxm = 200200;
Node seg[maxn][maxm<<2];
int n, m, q;

void pushup(Node* seg, int rt)
{
    seg[rt].sum = seg[lrt].sum + seg[rrt].sum;
    seg[rt].lo = min(seg[lrt].lo, seg[rrt].lo);
    seg[rt].hi = max(seg[lrt].hi, seg[rrt].hi);
}

void pushdown(Node* seg, int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    if(seg[rt].put != -1)
	{
        seg[lrt].sum = (mid - l + 1) * seg[rt].put;
        seg[rrt].sum = (r - mid) * seg[rt].put;
        seg[lrt].lo = seg[lrt].hi = seg[rt].put;
        seg[rrt].lo = seg[rrt].hi = seg[rt].put;
        seg[lrt].put = seg[rrt].put = seg[rt].put;
        seg[lrt].add = seg[rrt].add = 0;
        seg[rt].put = -1;
    }
    if(seg[rt].add)
	{
        seg[lrt].sum += (mid - l + 1) * seg[rt].add;
        seg[rrt].sum += (r - mid) * seg[rt].add;
        seg[lrt].lo += seg[rt].add;
        seg[lrt].hi += seg[rt].add;
        seg[rrt].lo += seg[rt].add;
        seg[rrt].hi += seg[rt].add;
        seg[lrt].add += seg[rt].add;
        seg[rrt].add += seg[rt].add;
        seg[rt].add = 0;
    }
}

void build(Node* seg, int l, int r, int rt)
{
    seg[rt].lo = seg[rt].hi = seg[rt].sum = seg[rt].add = 0;
    seg[rt].put = -1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(seg, l, mid, lrt);
    build(seg, mid+1, r, rrt);
}

void update(Node* seg, int L, int R, int l, int r, int rt, int val, int type)
{
    if(L <= l && r <= R)
	{
        if(type == 1)
		{
            seg[rt].lo += val;
            seg[rt].hi += val;
            seg[rt].add += val;
            seg[rt].sum += (r - l + 1) * val;
        }
        else if(type == 2)
		{
            seg[rt].lo = val;
            seg[rt].hi = val;
            seg[rt].put = val;
            seg[rt].sum = (r - l + 1) * val;
            seg[rt].add = 0;
        }
        return;
    }
    pushdown(seg, rt, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(seg, L, R, l, mid, lrt, val, type);
    if(mid < R) update(seg, L, R, mid+1, r, rrt, val, type);
    pushup(seg, rt);
}

Node query(Node* seg, int L, int R, int l, int r, int rt)
{
    if(L <= l && r <= R) return seg[rt];
    pushdown(seg, rt, l, r);
    int mid = (l + r) >> 1;
    Node ret;
    ret.lo = 0x7f7f7f7f, ret.hi = 0, ret.sum = 0;
    if(L <= mid)
	{
        Node tmp = query(seg, L, R, l, mid, lrt);
        ret.lo = min(ret.lo, tmp.lo);
        ret.hi = max(ret.hi, tmp.hi);
        ret.sum += tmp.sum;
    }
    if(mid < R)
	{
        Node tmp = query(seg, L, R, mid+1, r, rrt);
        ret.lo = min(ret.lo, tmp.lo);
        ret.hi = max(ret.hi, tmp.hi);
        ret.sum += tmp.sum;
    }
    pushup(seg, rt);
    return ret;
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
    int type, x1, y1, x2, y2, val;
    while(scanf("%d%d%d",&n,&m,&q)==3)
	{
        for(int i = 1; i <= n; i++)
            build(seg[i], 1, m, 1);
        while(q--)
		{
            scanf("%d%d%d%d%d",&type,&x1,&y1,&x2,&y2);
            if(type == 3)
			{
                Node ret, tmp;
                ret.lo = 0x7f7f7f7f, ret.hi = 0, ret.sum = 0;
                for(int i = x1; i <= x2; i++)
				{
                    tmp = query(seg[i], y1, y2, 1, m, 1);
                    ret.lo = min(ret.lo, tmp.lo);
                    ret.hi = max(ret.hi, tmp.hi);
                    ret.sum += tmp.sum;
                }
                printf("%d %d %d\n", ret.sum, ret.lo, ret.hi);
            }
            else
			{
                scanf("%d", &val);
                for(int i = x1; i <= x2; i++)
                    update(seg[i], y1, y2, 1, m, 1, val, type);
            }
        }
    }
    return 0;
}
