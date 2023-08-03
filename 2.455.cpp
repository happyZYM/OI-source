#include<cstdio>  
#include<cstring>  
#include<cctype>
const int max=100+10;
char s[max];  
int main()  
{  
    int n, len;  
    scanf("%d", &n);  
    getchar();  
    while (n--)  
    {  
        getchar();  
        gets(s);  
        len = strlen(s);  
        for (int i = 1; i <= len;i++)  
        if (len%i == 0)  
        {  
            bool ok = true;  
            for (int j = i; j < len;j++)  
            if (s[j] != s[j%i])  
            {  
                ok = false;  
                break;  
            }  
            if (ok)  
            {  
                printf("%d\n", i);  
                if (n)  
                    putchar('\n');  
                break;  
            }  
        }  
    }  
    return 0;   
}  
