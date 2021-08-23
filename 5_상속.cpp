#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

int main()
{
	//����� �⺻����(����) - ��ǥ:SW����
	if (0)
	{
		/*
		class Student
		{
			string name;
			int age;
			int kor, math, eng;
		};

		class Professor
		{
			string name;
			int age;
			string major;
		};
		*/
		//----->(Generalise / Specialize)
		//Base class, Super class, Parent class
		class People
		{
		public: //public�� ó���� ���� ���ƺ� ��
			string name;
			int age;
		};

		//Derived class, Sub class, Child class
		class Student : public People
		{
		public: //public�� ó���� ���� ���ƺ� ��
			int kor, math, eng;
		};

		class Professor : public People
		{
		public: //public�� ó���� ���� ���ƺ� ��
			string major;
		};

		Student a;
		a.name = "ȫ�浿";
		a.kor = 90;

		Professor b;
		b.name = "��ȣ��";
		b.major = "������";
	}

	//��Ӱ� ����������
	if (0)
	{
		class Base
		{
		private : 
			int data1;//�ڽ��� Ŭ���������� ���ٰ���
		protected:
			int data2;//�ڽŰ� �Ļ� Ŭ�������� ���ٰ���
		public:
			int data3;//��� ��(�ܺα�����)�� ���� ����
		};

		class Derived : public Base
		{
		public : 
			void func()
			{
				//data1 = 10;//error : private
				data2 = 20;
				data3 = 30;
			}
		};

		Derived x;
		//x.data1 = 10;//error : private
		//x.data2 = 20;//error : protected
		x.data3 = 30;
	}

	//��Ӱ� ������/�Ҹ���
	if (0)
	{
		class AAA
		{
		public : 
			AAA() { cout << "AAA()" << endl; }
			AAA(int a) { cout << "AAA(int)" << endl; }
			~AAA() { cout << "~AAA()" << endl; }
		};

		class BBB : public AAA
		{
		public:
			BBB() { cout << "BBB()" << endl; }
			BBB(int a) { cout << "BBB(int)" << endl; }
			~BBB() { cout << "~BBB()" << endl; }
		};

		class CCC : public BBB
		{
		public:
			CCC() { cout << "CCC()" << endl; }
			CCC(int a) : BBB(a) 
			{ 
				cout << "CCC(int)" << endl; 
			}
			~CCC() { cout << "~CCC()" << endl; }
		};

		//CCC x;
		CCC y(10);
	}

	//��Ӱ� ������/�Ҹ��� - �ʱ�ȭ/������ ����
	if (0)
	{
		class AAA
		{
		protected:
			char* m_pData;

		public:
			AAA() 
			{ 
				cout << "AAA()" << endl; 
				m_pData = new char[32];
			}
			AAA(int a) { cout << "AAA(int)" << endl; }
			~AAA() 
			{ 
				cout << "~AAA()" << endl; 
				delete[] m_pData;
			}
		};

		class BBB : public AAA
		{
		public:
			BBB() { cout << "BBB()" << endl; }
			BBB(int a) { cout << "BBB(int)" << endl; }
			~BBB() { cout << "~BBB()" << endl; }
		};

		class CCC : public BBB
		{
		public:
			CCC() { cout << "CCC()" << endl; }
			CCC(int a) : BBB(a)
			{
				cout << "CCC(int)" << endl;
			}
			~CCC() 
			{ 
				cout << "~CCC()" << endl; 
				//delete[] m_pData;//error �߻�
			}
		};

		CCC x;
	}

	//����� �̿��� ����߰�(��ɺ���)
	if (0)
	{
		//////////////////////////////////
		class CGrade
		{
		private:	  // ������ ���� �Ұ���
			int m_nGrade = 0;//������ ��ȿ���� : 0~100��

		public:		  // ������ ���� ����
			int GetGrade() { return m_nGrade; }
			void SetGrade(int nParam) { m_nGrade = nParam; }

		protected:	  // �Ļ� Ŭ������ ���� ����
			void PrintGrade()
			{
				cout << "���� : " << m_nGrade << endl;
			}
		};

		class CGradeEx : public CGrade
		{
		public:		  // ������ ���� ����
			void TestFunc()
			{
				SetGrade(5);//public
				PrintGrade();//protected
			}

			//������(�������̵�)
			void SetGrade(int nParam)
			{
				// �Է� �������� ���� �����ϴ� ���ο� ����� �߰��Ѵ�.
				if (nParam < 0)
					CGrade::SetGrade(0);
				else if (nParam > 100)
					CGrade::SetGrade(100);
				else
					CGrade::SetGrade(nParam);
			}
		};
		//���� Ŭ���� - �� üũ ����� ����
		CGrade a;
		a.SetGrade(120);
		cout << "CGrade->120 : " << a.GetGrade() << endl;

		//���� Ŭ���� - �� üũ ����� ����
		CGradeEx b;
		b.SetGrade(120);
		cout << "CGradeEx->120 : " << b.GetGrade() << endl;

		b.SetGrade(90);
		cout << "CGradeEx->90 : " << b.GetGrade() << endl;

		b.SetGrade(-10);
		cout << "CGradeEx->-10 : " << b.GetGrade() << endl;

		//���� Ŭ������ ������ ����
		CGrade& ref = b;
		ref.SetGrade(120);//����üũ ????
		cout << "������ ���� ->120 :" << ref.GetGrade() << endl;

		//���� Ŭ������ ������ ����
		CGradeEx& ref2 = b;
		ref2.SetGrade(120);//����üũ ????
		cout << "������ ���� ->120 :" << ref2.GetGrade() << endl;
	}
	return 0;
}

#endif