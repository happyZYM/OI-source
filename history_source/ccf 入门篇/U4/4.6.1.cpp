#include<iostream>
#include<cmath>
using namespace std;
int p;
bool pan(int a,int b,int c,int d,int e,int f,int g,int h,int i)
{
	if((a<f&&f<i)&&(b<d&&g<h&&c<e)&&(a+b+d+f==f+g+h+i==i+e+c+a==p)) return 1;
	else return 0;
}
int main()
{
	int n;
	while(true)
	{
		cin>>p;
		n=0;
		for(int a=1;a<=9;a++)
		{
			for(int b=1;b<=9;b++)
			{
				if(b==a) continue;
				for(int c=1;c<=9;c++)
				{
					if(c==a||c==b) continue;
					for(int d=1;d<=9;d++)
					{
						if(d==a||d==b||d==c) continue;
						for(int e=1;e<=9;e++)
						{
							if(e==a||e==b||e==c||e==d) continue;
							for(int f=1;f<=9;f++)
							{
								if(f==a||f==b||f==c||f==d||f==e) continue;
								for(int g=1;g<=9;g++)
								{
									if(g==a||g==b||g==c||g==d||g==e||g==f) continue;
									for(int h=1;h<=9;h++)
									{
										if(h==a||h==b||h==c||h==d||h==e||h==f||h==g) continue;
										int i=45-a-b-c-d-e-f-g-h;
										if(pan(a,b,c,d,e,f,g,h,i)) n++;
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<n<<endl;
	}
}
