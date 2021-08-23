//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;

struct USERDATA
{
    int nAge;
    char szName[32];

    void PrintData()
    {
        printf("%d,%s\n", nAge, szName);
    }
};

void PrintData(USERDATA* p)
{
    printf("%d,%s\n", p->nAge, p->szName);
}

class Human
{
public:
    //Human() { ; }//����Ʈ ������(by Compiler)
    //~Human() { ; }//����Ʈ �Ҹ���(by Compiler)

    int nAge;
    char szName[32];

    void PrintData() { printf("%d,%s\n", nAge, szName); }
};

int main()
{
    //����ü(=��������� ������Ÿ��)
    if (0)
    {
        USERDATA kim = { 20, "��ö��" };
        PrintData(&kim);
        //printf("%d, %s\n", kim.mAge, kim.szName);
    }

    //��ü
    if (1)
    {
        Human lee;
        lee.nAge = 33;
        sprintf_s(lee.szName, "%s", "�̱浿");
    
        lee.PrintData();
    }

    return 0;
}

#endif

