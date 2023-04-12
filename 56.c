//判断当前计算机的大小端存储

#include <stdio.h>

int check()
{
    union Un
    {
        int i;
        char c;
    }u;
    u.i=1;
    return u.c;
    
}

int main()
{
    int ret = check();
    if (ret == 1)
    {
        printf("xiao\n");
    } 
    else
    {
        printf("da\n");
    }
    //[][][11][22][33][44][][][][][][][]   大端
    //[][][44][33][22][11][][][][][][][]   小端
    return 0;
}