#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    string s;
    int id;
} a[25];
inline bool cmp(node x,node y)
{
    if(x.s.size()==y.s.size()) return x.s>y.s;
    else return x.s.size()>y.s.size();
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].s,a[i].id=i;
    sort(a+1,a+1+n,cmp);
    cout<<a[1].id<<endl<<a[1].s; 
    return 0;
}
