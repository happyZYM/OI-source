#include<iostream>
#include<sstream>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
    return !b?a:gcd(b,a%b);
}
inline LL lcm(LL a, LL b)
{
    return a/gcd(a,b)*b;
}
inline int len(LL x)
{
    stringstream ss;
    ss<<x;
    return ss.str().length();
}
inline void print_chars(int cnt,char ch)
{
    while(cnt--) cout << ch;
}
inline void output(LL a,LL b,LL c)
{
    if(b==0) cout<<a<<"\n";
    else
    {
        int L1=len(a);
        print_chars(L1+1,' ');
        cout<<b<<"\n";
        cout<<a<<" ";
        print_chars(len(c),'-');
        cout<<"\n";
        print_chars(L1+1,' ');
        cout<<c<<"\n";
    }
}
int n,i;
LL x,a,b,c,g;
int main()
{
#ifdef local
    freopen("pro.in","r",stdin);
#endif
    while(cin>>n&&n)
    {
        if(n==1) {output(1,0,0); continue;}
        x=1;
        for(i=2;i<=n-1;i++)
            x=lcm(x, i);
        //b/c = 1/(n-1) + ... + 1/2
        c=x,b=0;
        for(i=2;i<=n-1;i++)
            b+=x/i;
        b*=n;
        g=gcd(b,c);
        b/=g;
        c/=g;
        //ans = a + b/c
        a=1+n+b/c;
        output(a,b%c,c);
    }
    return 0;
}
