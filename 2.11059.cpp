#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int data[20];

int main()
{
	int n,t = 1;
	while (cin >> n) {
		for (int i = 1 ; i <= n ; ++ i)
			cin >> data[i];
		long long max = 0,neg = 0,pos = 0,tem;
		for (int i = 1 ; i <= n ; ++ i) {
			if (data[i] == 0) 
				neg = pos = 0;
			else if (data[i] > 0) {
				pos = pos*data[i];
				neg = neg*data[i];
				if (!pos) pos = data[i];
			}else if (data[i] < 0) {
				tem = pos*data[i];
				pos = neg*data[i];
				neg = tem;
				if (!neg) neg = data[i];
			}
			if (max < pos && data[i])
				max = pos;
		}
		
		cout << "Case #" << t ++ << ": The maximum product is " << max << ".\n\n";	
	}
	return 0;
}

