#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
long long E[12][33],e;
double M[12][33],m,re;
char str[25],*ps;
int main()
{
    for(int i=0;i<=9;++i)
        for(int j=1;j<=30;++j)
		{
            m=1-pow(2,-1-i);
            e=pow(2,j)-1;
            re=log10(m)+log10(2)*e;
            E[i][j]=(long long)re;
            M[i][j]=pow(10,(re-E[i][j]));
        }
    while((cin>>str)&&(ps=str)!="0e0")
	{
        while(*++ps != 'e');*ps = ' ';
        istringstream s(str);
        s>>m>>e;
        for(int i=0;i<=9;++i)//M
		{
            int j;
            for(j=1;j<=30;++j)//E
                if(E[i][j]==e&&(M[i][j]-m<0.0001&&m-M[i][j]<0.0001))
				{
                    cout<<i<<' '<<j<< '\n';
                    break;
            	}
            if(j<=30) break;
        }
    }
    return 0;
}
