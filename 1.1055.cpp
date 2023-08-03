#include<cstdio>
const int q[]={1,0,2,3,4,0,5,6,7,8,9};
char input[20];
int main()
{
    int mod=0;
    for(int i=0;i<11;i++)
    {
        input[i]=getchar();
        mod+=q[i]*(input[i]-'0');
    }
    getchar();
    int cro=getchar()-'0';
    if(cro=='X'-'0') cro=10;
    if(cro==mod%11) printf("Right\n");
    else printf("%s-%c\n",input,mod%11==10?'X':'0'+mod%11);
    return 0;
}
