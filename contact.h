#include <stdio.h>

#define max 1000

#define name_max 20
#define tele_max 12
#define sex_max 5
#define addr_max 30

enum E
{
    exit,
    add,
    del,
    search,
    modify,
    show,
    sort
};

struct PeoInfo
{
    char name[name_max];
    int age;
    char sex[sex_max];
    char tele[tele_max];
    char addr[addr_max];
};

struct Contact
{
    struct PeoInfo data[max];
    int size;
};


void initcontact(struct Contact* pa);
void addcontact(struct Contact* pb);
void showcontact(const struct Contact* pc);
void delcontact(struct Contact* pd);
void searchcontact(struct Contact* pe);
void modifycontact(struct Contact* pf);