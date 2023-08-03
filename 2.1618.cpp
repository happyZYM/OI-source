#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=5005;
int a[maxn],l[maxn][maxn],r[maxn][maxn];
// l[i][j]±íÊ¾ÏÂ±êÐ¡ÓÚjÇÒÖµ±ÈNi´óµÄÊýÖÐ×îÐ¡ÖµµÄÎ»ÖÃ
// r[i][j]±íÊ¾ÏÂ±ê´óÓÚjÇÒÖµ±ÈNiÐ¡µÄÊýÖÐ×î´óÖµµÄÎ»ÖÃ
int k;

bool solve()
{
    for(int i=1;i<=k;i++)
	{
	    l[i][0]=0;
	    for(int j=1;j<i;j++)
		{ // Ã¶¾ÙNq,ÕÒNp
		    if(a[i]>=a[j])
			    l[i][j]=l[i][j-1];
		    else if(!l[i][j-1]||a[j]<a[l[i][j-1]])
			    l[i][j]=j;
		    else
			    l[i][j]=l[i][j-1];
		}
	}
    for(int i=1;i<=k;i++)
	{
	    r[i][k+1]=0;
	    for(int j=k;j>i;j--)
		{// Ã¶¾ÙNr,ÕÒNs
		    if(a[i]<=a[j])
			    r[i][j]=r[i][j+1];
		    else if(!r[i][j+1]||a[j]>a[r[i][j+1]])
			    r[i][j]=j;
		    else 
			    r[i][j]=r[i][j+1];
		}
	}
	//Ã¶¾Ùr£¬q£¬ÕÒp£¬s¾Í±ä³ÉÁË³£ÊýÊ±¼ä¡£¸´ÔÓ¶ÈÓÉn^4±ä³ÉÁËn^2.
    for(int i=1;i<=k;i++)
	{
	    for(int j=i+1;j<=k;j++)
		{
		    if(!l[j][i-1]||!r[i][j+1]||a[i]<=a[j])
			    continue;
		    int p=l[j][i-1],s=r[i][j+1];
		    if(a[j]<a[p]&&a[p]<a[s]&&a[s]<a[i])
			    return true;
		}
	}		
    return false;
}

int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif 
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
	{
	    cin>>k;
	    for(int i=1;i<=k;i++) cin>>a[i];
	    if(solve()) cout<<"YES\n";
	    else
		{
		    reverse(a+1,a+k+1);
		    if(solve()) cout<<"YES\n";
		    else cout<<"NO\n";
		}
	}
    return 0;
}
