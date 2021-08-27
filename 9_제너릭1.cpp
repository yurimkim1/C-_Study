//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

typedef struct USERDATA
{
    int age;
    string name;
} USERDATA;

class Human
{
public:
    int age = 0;
    string name = "";

    //Human() : age(-1), name("�̸�����") { }
    Human(int age, string name)
    {
        this->name = name;
        this->age = age;
    }
    void Print(void)
    {
        cout << name << ", " << age << endl;
    }
};

#include <vector>
#include <list>

int main()
{
    //vector + ����ü
    if (0)
    {/*
        std::vector<USERDATA> vec(3);

        vec[0] = USERDATA{ 10, "����"};
        vec[1] = USERDATA{ 20, "ö��" };
        vec[2] = USERDATA{ 33, "�⿵��" };

        //1. []������
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i].age << ", " << vec[i].name << endl;
        }
        cout << endl;

        //2. ������� for��
        for (auto& n : vec)
        {
            cout << n.age << ", " << n.name << endl;
        }
        cout << endl;

        //3. �ݺ��� ���
        auto p1 = begin(vec);///p1 = vec.begin();
        while (p1 != end(vec))
        {
            cout << p1->age << ", " << p1->name << endl;
            p1++;
        }
        cout << endl;

        ////////////////////
        // 2�� �߰�
        USERDATA a = { 40, "�迬��" };
        vec.push_back(a);
        vec.push_back(USERDATA{ 50, "ȫ�浿" });

        for (auto& n : vec)
        {
            cout << n.age << ", " << n.name << endl;
        }
        cout << endl;
        */
    }

    //vector + Ŭ����
    if (1)
    {
        vector<Human> vec;//(3);
        /*
        vec[0] = Human(10, "�⿵��");
        vec[1] = Human(20, "����");
        vec[2] = Human(30, "ö��");
        */
        for (auto& n : vec) n.Print();
        cout << endl;
        /////////////////////////
        vec.push_back(Human(40, "����"));
        vec.push_back(Human(50, "�ƺ�"));
        //vec.push_back(Human());

        for (auto& n : vec) n.Print();
        cout << endl;
    }
    return 0;
}

#endif