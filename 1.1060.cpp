#include<iostream>
#include<algorithm>
using namespace std;
int w[30],v[30],f[50000];
int n,m;
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m]<<endl;
    return 0;
}
