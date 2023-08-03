#include<cstdio>
#include<algorithm>
using namespace std;
int res[]={1,2,3,4,5,6,7,8,9};
int main()
{
	int a,b,c;
    do
    {
    	a=res[0]*100+res[1]*10+res[2];
    	b=res[3]*100+res[4]*10+res[5];
    	c=res[6]*100+res[7]*10+res[8];
    	if(a*6==b*3&&b*3==c*2) printf("%d %d %d\n",a,b,c);
    }
    while(next_permutation(res,res+9));
    return 0;
}
