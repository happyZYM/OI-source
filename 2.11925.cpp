#include <bits/stdc++.h>
using namespace std;

deque<int> a;
vector<int> res;

bool is_order()
{
	for (int i = 1; i != a.size(); ++i)
		if (a[i] < a[i-1])
			return false;
	return true;
}
int main()
{
	int n;
	while (a.clear(),res.clear(),cin>>n, n)
	{
		for (int i = 0; i < n; ++i)
		{
			int t; cin >> t; a.push_back(t);
		}
		while(!is_order())
		{
			if (a[0]>a[1] && a[0]!=n)
			{
				swap(a[0], a[1]);
				res.push_back(1);
			}
			else
			{
				int t = a.back();
				a.pop_back();
				a.push_front(t);
				res.push_back(2);
			}
		}
		for(auto it = res.rbegin(); it != res.rend(); ++it)
            cout << *it;
        cout << endl;
	}
	return 0;
}
