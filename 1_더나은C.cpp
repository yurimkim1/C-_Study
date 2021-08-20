//#define ON_MAIN
#ifdef ON_MAIN

#include <stdio.h>//C header
#include <iostream>//C++ header

using namespace std;

int g_nData = 10;
void Gugudan(void)
{
	cout << "Global::Gugudan()" << endl;
}

namespace TEST 
{
	int g_nData = 100;
	void Gugudan(void)
	{
		cout << "TEST::Gugudan()" << endl;
	}
}

void Swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "Swap :" << "a=" << a << "b=" << b << endl;
}

void Swap2(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

	cout << "Swap2 :" << "a=" << *a << "b=" << *b << endl;
}

void Swap3(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;

	cout << "Swap3 :" << "a=" << a << "b=" << b << endl;
}

int Sum(int a, int b)
{
	cout << "Sum(int a, int b)" << endl;
	return a + b;
}

int Sum(int a, int b, int c)
{
	cout << "Sum(int a, int b, int c)" << endl;
	return a + b + c;
}

double Sum(double a, double b)
{
	cout << "Sum(double a, double b)" << endl;
	return a + b;
}

int TestFunc(int a = 10)
{
	return a;
}

int TestFunc2(int a, int b=20, int c=30)
{
	return a+b+c;
}

#define ADD(a, b) (a + b) //��ũ��(C ����)


int Add(int a, int b)// �Լ�(C ����)
{
	return a + b;
}

inline int AddNew(int a, int b)// �ζ����Լ�(C++ ����)
{
	return a + b;
}

int main()
{
	//cout ��ü
	if (0)
	{
		printf("Hello World, ����\n");
		std::cout << "Hello World, ����\n";

		int a = 10;
		int b = 20;

		printf("a = %d b = %d\n", a, b);
		std::cout << "a= " << a << " b= " << b << "\n";

		std::cout << a << std::endl;//"\n"
		std::cout << &a << std::endl;//"\n"
		std::cout << sizeof(a) << std::endl;//"\n"
		std::cout << printf << std::endl;//"\n"
		std::cout << main << std::endl;//"\n"


		cout << "Bye" << "\n"; // namespace ����� ��������
	}
	//cin ��ü
	if (0)
	{
		int nAge;
		cout << "���̸� �Է��ϼ��� : " << endl;
		cin >> nAge;
		//scanf("%d", &nAge);

		std::string strName;
		cout << "�̸��� �Է��ϼ��� : " << endl;
		cin >> strName;

		char strJob[30];
		cout << "������ �Է��ϼ��� : " << endl;
		cin >> strJob;

		cout << "�̸� :" << strName << endl;
		cout << "���� :" << nAge << endl;
		cout << "���� :" << strJob << endl;
	}
	//auto
	if (0)
	{
		int a = 10;
		int b(a);
		auto c(a);

		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}

	//���ӽ����̽�
	if (0)
	{
		::Gugudan();
		TEST::Gugudan();

		using namespace TEST;
		//Gugudan();//ERROR
		::Gugudan();//OK
	}

	//Pointer(C) VS Reference(CPP)
	if (0)
	{
		//Pointer(C)------------------------
		int a = 10;
		int* p1 = &a;

		cout << sizeof(a) << endl;
		cout << sizeof(p1) << endl;

		char b = 'a';
		char* p2 = &b;

		cout << sizeof(b) << endl;//1B
		cout << sizeof(p2) << endl;//4B
		// ��� �ּҴ� 4Byte

		//Reference(CPP)-------------------------
		int nData = 10;
		int& ref = nData;//���۷���(����) // ndata�� ref��� �Ҹ�, ���״�� ndata�� �����̵�
		//int& ref2;

		nData++;//11
		cout << nData << endl;
		cout << ref << endl;

		ref++;//11
		cout << nData << endl;
		cout << ref << endl;
	}
	//�Լ�ȣ�� ���
	if (0) 
	{
		int a = 10;
		int b = 20;
		cout << "a=" << a << "b=" << b << endl;

		//C���
		//1) Call by Value(���� ����)-----> ��뽱��. ������ ���� ����
		Swap(a, b);
		cout << "a=" << a << "b=" << b << endl;

		//2) Call by Address(�ּ��� ����)--> ����ƴ�. ������ ����
		a = 10; b = 20;
		Swap2(&a, &b);
		cout << "a=" << a << "b=" << b << endl;

		//C++���
		//3) Call by Reference -----> ��뽱��. ������ ����
		a = 10; b = 20;
		Swap3(a, b);
		cout << "a=" << a << "b=" << b << endl;
	}

	//�Լ� �����ε�(��������) by ���Ӹͱ۸�
	if (0)
	{
		cout << Sum(10, 20) << endl;
		cout  << Sum(10, 20, 30) << endl;
		cout << Sum(10.5, 20.9) << endl;
	}

	//����Ʈ �Ű�����
	if (0)
	{
		cout << TestFunc(100) << endl;//100
		cout << TestFunc() << endl;//10

		//cout << TestFunc2() << endl;//error
		cout << TestFunc2(1) << endl;//1+20+20
		cout << TestFunc2(1,2) << endl;//1+2+30
		cout << TestFunc2(1,2,3) << endl;//1+2+3
	}

	//�����޸�(C: malloc/free, C++: new/delete)
	if (0)
	{

		//C: malloc/free
		int* p = (int*) malloc(sizeof(int) * 4); //==int [4]
		p[0] = 10;
		//*(p + 0) = 10;
		//*p = 10;

		p[1] = 20;
		//*(p + 1) = 20;

		p[2] = 30;
		p[3] = 40;
		free(p);
		///////////////////

		//C++: new / delete
		int* p2 = new int;
		*p2 = 100;

		int* p3 = new int(10); //�ʱⰪ10 �Ҵ���

		cout << *p2 << endl;
		cout << *p3 << endl;

		delete p2;
		delete p3;

		////////////////////
		//�迭
		int* p4 = new int[5];
		for (int i = 0; i < 5; i++)
		{
			p4[i] = i * 10;
			cout << p4[i] << endl;
		}
		delete[] p4;
	}

	//������� for��
	if (0)
	{
		//int aList[5] = { 10,20,30,40,50 };
		int aList[5] = { 0, }; // ��ü 0���� �����

		//���� for��
		for (int i = 0; i < 5; i++)
		{
			cout << aList[i] << endl;
		}
		//������� for��
		for (auto x : aList)//���� ����
		{
			cout << x << endl;
		}
		cout << endl;
		for (auto& x : aList)//����(=����)(����X) // ������ �� ����
		{
			cout << x << endl;
		}
	}

	//�ζ��� �Լ�
	if (1)
	{
		int a = 10;
		int b = 20;

		cout << ADD(a, b) << endl;//��ũ��(C ����)
		cout << Add(a, b) << endl;//�Լ� ȣ��(C ����)
		cout << AddNew(a, b) << endl;//�ζ����Լ� ȣ��(C++ ����)
	}

	return 0; //��������
}

#endif