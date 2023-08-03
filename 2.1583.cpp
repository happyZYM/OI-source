#include<iostream>
#include<cstring>
using namespace std;
inline int hsh(int n)
{
    int j=n,ans=n;
    while(j)
    {
        ans+=j%10;
        j/=10;
    }
    return ans;
}
int a[100105];
int main()
{
    memset(a,0,sizeof(a));
    for(int i=1;i<=100000;i++)
    {
        int k=hsh(i);
        if(a[k]==0) a[k]=i;
    }
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cout<<a[x]<<endl;
    }
    return 0;
}
