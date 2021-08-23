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
    //Human() { ; }//디폴트 생성자(by Compiler)
    //~Human() { ; }//디폴트 소멸자(by Compiler)

    int nAge;
    char szName[32];

    void PrintData() { printf("%d,%s\n", nAge, szName); }
};

int main()
{
    //구조체(=사용자정의 데이터타입)
    if (0)
    {
        USERDATA kim = { 20, "김철수" };
        PrintData(&kim);
        //printf("%d, %s\n", kim.mAge, kim.szName);
    }

    //객체
    if (1)
    {
        Human lee;
        lee.nAge = 33;
        sprintf_s(lee.szName, "%s", "이길동");
    
        lee.PrintData();
    }

    return 0;
}

#endif

