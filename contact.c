#include <stdio.h>
#include <string.h>
#include "contact.h"


int Find(struct Contact* p,char NAME[name_max])     //找到返回名字的下标，未找到返回-1；
{
    int i = 0;
    for(i=0;i<p->size;i++)
    {
        if (0 == strcmp(p->data[i].name,NAME))
        {
            return i;
        }
    }
    return -1;
}


void initcontact(struct Contact* pa)
{
    memset(pa->data,0,sizeof(pa->data));
    pa->size = 0;
}

void addcontact(struct Contact* pb)
{
    if(pb->size == max)
    {
        printf("fill!!!\n");
    }
    else
    {
        printf("name:>");
        scanf("%s",pb->data[pb->size].name);
        printf("age:>");
        scanf("%d",&(pb->data[pb->size].age));
        printf("sex:>");
        scanf("%s",pb->data[pb->size].sex);
        printf("tele:>");
        scanf("%s",pb->data[pb->size].tele);
        printf("addr:>");
        scanf("%s",pb->data[pb->size].addr);
        pb->size++;
        printf("success!\n");
    }
}

void showcontact(const struct Contact* pc)
{
    if(pc->size == 0)
    {
        printf("vacant!!");
    }
    else
    {
        int i = 0;
        printf("%8s\t%4s\t%5s\t%12s\t%10s\n","name","age","sex","tele","addr");
        for(i=0 ; i<pc->size ; i++)
        {
            printf("%8s\t%4d\t%5s\t%12s\t%10s\n",
            pc->data[i].name,
            pc->data[i].age,
            pc->data[i].sex,
            pc->data[i].tele,
            pc->data[i].addr);
        }
    }
}




void delcontact(struct Contact* pd)
{
    char NAME[name_max];
    printf("input dele name:>");
    scanf("%s",NAME);
    int ret = Find(pd,NAME);
    if (ret == -1)
    {
        printf("donot find\n");
    }
    else
    {
        int j = 0;
        for (j=ret;j<pd->size-1;j++)
        {
            pd->data[j] = pd->data[j+1];
        }
        pd->size--;
        printf("dele success!!!\n");
    }
}

void searchcontact(struct Contact* pe)
{
    char NAME[name_max];
    printf("input search name:>");
    scanf("%s",NAME);
    int ret = Find(pe,NAME);
    if (-1 == ret)
    {
        printf("dnnot fand!\n");
    }
    else
    {
        printf("%8s\t%4s\t%5s\t%12s\t%10s\n","name","age","sex","tele","addr");
        printf("%8s\t%4d\t%5s\t%12s\t%10s\n",
            pe->data[ret].name,
            pe->data[ret].age,
            pe->data[ret].sex,
            pe->data[ret].tele,
            pe->data[ret].addr);
    }
}

void modifycontact(struct Contact* pf)
{
    char NAME[name_max];
    printf("input modify name:>");
    scanf("%s",NAME);
    int ret = Find(pf,NAME);
    if (-1 == ret)
    {
        printf("dnnot fand!\n");
    }
    else
    {
        printf("name:>");
        scanf("%s",pf->data[ret].name);
        printf("age:>");
        scanf("%d",&(pf->data[ret].age));
        printf("sex:>");
        scanf("%s",pf->data[ret].sex);
        printf("tele:>");
        scanf("%s",pf->data[ret].tele);
        printf("addr:>");
        scanf("%s",pf->data[ret].addr);
        printf("success modify!!\n");
    }
}