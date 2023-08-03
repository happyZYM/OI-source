#include<cstdio>
int c,m,a[13];
int main()
{
    for(int i=1;i<=12;i++) scanf("%d",a+i);
    for(int i=1;i<=12;i++)
    {
    	if(m+300<a[i])
    	{
    		printf("-%d",i);
    		return 0;
    	}
    	m+=300-a[i];
    	c+=m/100*100;
    	m%=100;
    }
    printf("%d",c/10*12+m);
    return 0;
}
/*
290 
230 
280 
200 
300 
170 
330 
50 
90 
80 
200 
60
*/
