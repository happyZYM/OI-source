#include<iostream>
using namespace std;
int h,w,s,flag;
char ch;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(cin>>h>>w)
	{
		s=0;
		for(int i=0;i<h;i++)
		{
			flag=0;
			for(int j=0;j<w;j++)
			{
				cin>>ch;
				switch(ch)
				{
					case '/':case '\\':
						flag=!flag;
						s++;
						break;
					case '.':
						s+=flag*2;
						break;
				}
			}
		}
		printf("%d\n",s/2);
	}
	return 0;
}
