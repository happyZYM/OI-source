#include <iostream>
#include <algorithm>
using namespace std;
struct point
{
    int num, s, pos;
}op[100005];
bool cmp1(const point &a, const point &b)
{
    return a.num < b.num;
}
bool cmp2(const point &a, const point &b)
{
    return a.pos < b.pos;
}
int main()
{
    int n;

    while(cin >> n)
    {
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            int m;
            scanf("%d", &m);
            op[i].num = m;
            op[i].pos = i;
            op[i].s = 1;
            sum += m;
        }
        if(sum % 2)
		{
            cout << "No"<< endl;
            continue;
        }
        sort(op, op+n, cmp1);
        sum /= 2;
        for(int i = n-1; i >= 0; i--)
        {
            if(sum >= op[i].num)
			{
                sum -= op[i].num;
                op[i].s = -1;
            }
            if(sum == 0)
                break;
        }
        cout << "Yes" << endl;
        sort(op, op+n, cmp2);
        for(int i = 0; i < n-1; i++)
            cout << op[i].s << " ";
        cout << op[n-1].s << endl;
    }
    return 0;
}
