//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;

class CTest
{
public:
	int m_nData;
	int m_nData2;

	CTest() : m_nData(10), m_nData2(20)
	{
		cout << "CTest()�� ������" << endl;
		//m_nData = 10;
		//m_nData2 = 20;
	}
	~CTest()
	{
		cout << "~CTest()�� �Ҹ���" << endl;
	}
	void PrintData(void)
	{
		cout << "m_nData : " << m_nData << endl;
		cout << "m_nData2 : " << m_nData2 << endl;
		cout << endl;
	}
};

class CTestStatic
{
public:

	CTestStatic(int a)
	{
		m_nData = a;
		m_nCount++;//�����ڰ� �Ҹ� Ƚ��
	}

	int m_nData;//��ü���� ���� ������

	//���� ��� ���� ����(���Ǵ� �ƴϴ�)
	static int m_nCount;//���ݱ��� CTest��ü�� ������ Ƚ��
	static int GetCount()
	{
		return m_nCount;
	}
};

//���� ��� ���� ����
int CTestStatic::m_nCount = 0;

int main()
{
	//��������� �ʱ�ȭ
	if (0)
	{
		cout << "���ν���" << endl;

		int a;		// 4B �޸� �Ҵ�
		CTest b;	//10B �޸� �Ҵ� --> b�� ������ ȣ���

		b.PrintData();//10�� ��µ�
		printf("b�� �� : %d, %d\n\n", b.m_nData, b.m_nData2);

		cout << "���γ�" << endl;

		//-->	1) a�� �޸� ����
		//		2) b�� �Ҹ��� ȣ���
		//		3) b�� �޸� ����	
	}

	//���� ��� ����
	if (1)
	{
		CTestStatic a(5);
		CTestStatic b(10);
		CTestStatic c(100);

		cout << a.m_nData << endl;
		cout << b.m_nData << endl;
		cout << c.m_nData << endl;
		cout << endl;

		cout << CTestStatic::m_nCount << endl;
		cout << a.m_nCount << endl;
		cout << b.m_nCount << endl;
		cout << c.m_nCount << endl;
	}
	return 0;
}


#endif
