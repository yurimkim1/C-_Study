#include <iostream>

//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

/*
* �Լ� ���ε�
* : �Լ��� ȣ��� ���� � �Լ��� ����� �� �����ϴ� ��
* ----------------------
* 1) ���� ���ε� (�⺻ ���ε�) ������
*	==> early binding
*	==> ������ Ÿ���� ���� ���ε��� ������(������ Ÿ��)
* ----------------------
* 2) ���� ���ε� (virtual ó���ؾ� ��) ����
* 	==> late binding
*	==> ������ ����Ű��(������) �ǰ�ü�� ���� ���ε��� ������(���� Ÿ��)
*/

class Animal
{
public:
	//1. �Ϲ��Լ�(���� ���ε�)
	//void Cry() { cout << "���" << endl; }

	//2. �����Լ�(���� ���ε�-virtual)
	//virtual void Cry() { cout << "���" << endl; }

	//3. ���� �����Լ�(pure virtual)
	virtual void Cry() = 0;//�������̽� ���
};

class Dog : public Animal
{
public:
	void Cry() { cout << "�۸۸�" << endl; }
};

class Cat : public Animal
{
public:
	void Cry() { cout << "�߿˾߿�" << endl; }
};

int main()
{
	//Upcasting & Downcating
	if (0)
	{
		class Animal
		{
		public:
			string name;
			int age;
		};

		class Dog : public Animal
		{
		public:
			int color;
		};

		Dog dog;
		dog.name = "�ܶ�";
		dog.age = 6;
		dog.color = 10;

		Animal ani;
		ani.name = "�Ŀ���";
		/*
		Dog* p;
		p = &dog;	//��� ok
		//p = &ani;	//error

		Animal* p2;
		p2 = &dog;	//ok
		p2 = &ani;	//��� ok
		*/
		////////////////////////
		//1. upcasting( ������ )
		// : ���� �����ʹ� �ٸ� Ÿ���� �ּҸ� ���� �� ����
		// : ������, �θ� �����ʹ� �ڽ��� �ּҸ� ���� �� �ִ�(=upcasting)
		Animal* pAni = &dog;
		pAni->age = 7;

		//2 downcasting ( ������ )
		//Dog* pDog = pAni;//error
		Dog* pDog = (Dog*)pAni;//downcasting�� "����" ����ȯ�ؿ� ��
		pDog->age = 8;
		pDog->color = 20;


	}

	//�Լ� �������̵� + �����Լ�(virtual)
	if (0)
	{
		////////////////
		//������
		Dog d;
		d.Cry();

		Cat c;
		c.Cry();

		////////////////////
		Animal* p;

		p = &d;//upcasting
		p->Cry();

		p = &c;//upcasting
		p->Cry();

		////////////////////
		//Animal a;//error: ���� ����Ŭ������ ��ü�� ���� �� ����
	}

	//���� �Ҹ���
	if (1)
	{
		class Base
		{
		public:
			Base() { cout << "Base()" << endl; }
			//~Base() { cout << "Base()" << endl; }
			virtual ~Base() { cout << "~Base()" << endl; }
		};

		class Derived : public Base
		{
		public:
			Derived() 
			{ 
				cout << "Derived() - �ڿ�ȹ��" << endl;
				pData1 = new int;
				pData2 = new int[20];
			}
			~Derived() 
			{ 
				cout << "~Derived() - �ڿ��ݳ�" << endl;
				delete pData1;
				delete[] pData2;
			}

			int* pData1;
			int* pData2;
		};
		
		/////////////////
		//Derived x;

		Base* p = new Derived;
		//...
		delete p;//�Ҹ��� -> �������ε� ==> �������ε�(virtual)

	}


	return 0;
}

#endif