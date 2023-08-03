#include <iostream>
#include <string>
using namespace std;
const int bin[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
    int kase = 1;
    int number;
    while(cin >> number)
    {
        if(number == 0)
            break;
        string t1, t, s;
        int num;
        for(int j = 0; j < number; j++)
            cin >> t1;
        cin >> t;
        int n;
        cin >> n;
        cout << "S-Tree #" << kase++ << ":" << endl;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            num = 0;
            for(int j = 0; j < s.length(); j++)
                num += bin[s.length()-j-1]*(s[j] - '0');
            cout << t[num];
        }
        cout << endl << endl;
    }
    return 0;
}
