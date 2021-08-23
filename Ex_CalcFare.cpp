#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#define DEFAULT_FARE 50000

class CPerson
{
public:
    CPerson() { }
    virtual ~CPerson() {
        cout << "virtual ~CPerson()" << endl;
    }

    // ��� ��� �������̽�(���� ���� �Լ�)
    virtual void CalcFare() { m_nFare = DEFAULT_FARE; };
    unsigned int GetFare() { return m_nFare; }

protected:
    unsigned int m_nFare = 0;
};
class CBaby : public CPerson
{
    void CalcFare() { m_nFare = 0; }; //100%����
};
class CChild : public CPerson
{
    void CalcFare() { m_nFare = DEFAULT_FARE * 0.5; };//50%����
};
class CTeen : public CPerson
{
    void CalcFare() { m_nFare = DEFAULT_FARE * 0.75; };//25%����
};
class CAdult : public CPerson
{
public:
    void CalcFare() { m_nFare = DEFAULT_FARE; };//���ξ���
};

int main()
{
    cout << "=======================================" << endl;
    cout << "\t �������� ��� ����" << endl;
    cout << "=======================================" << endl;

    int nCount = 0;
    cout << "�� �� ���� �����Ͻó���? ";
    cin >> nCount;
    cout << "------------------------------" << endl;

    CPerson** arList = new CPerson * [nCount];
    int nAge = 0;

    // 1. �ڷ� �Է�: ����� �Է¿� ���� ������ ��ü ����
    for (int i = 0; i < nCount; i++)
    {
        cout << i + 1 << "���� ���̸� �Է��ϼ���:";
        cin >> nAge;

        if (nAge < 8)
            arList[i] = new CBaby;
        else if (nAge < 14)
            arList[i] = new CChild;
        else if (nAge < 20)
            arList[i] = new CTeen;
        else
            arList[i] = new CAdult;
        
        arList[i]->CalcFare();
    }

    // 2. �ڷ� ���: ����� ����� Ȱ���ϴ� �κ�
    int nFare = 0;
    int nTotal = 0;
    cout << "------------------------------" << endl;
    for (int i = 0; i < nCount; i++)
    {
        nFare = arList[i]->GetFare();
        nTotal += nFare;

        cout << i + 1 << "���� ����� " << nFare << "��" << endl;
    }
    cout << "------------------------------" << endl;
    cout << "�� ��� : " << nTotal << endl;
    cout << "------------------------------" << endl;

    // 3. �ڷ� ���� �� ����
    for (int i = 0; i < nCount; i++)
    {
        delete arList[i];
    }
    delete[] arList;

    return 0;
}

#endif
