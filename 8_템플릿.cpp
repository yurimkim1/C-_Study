//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>


template <typename T>
T mymax(T a, T b)
{
	static int count = 0;
	count++;
	cout << "�Ҹ� Ƚ�� : " << count << endl;

	cout << "max a: " << a << endl;
	cout << "max b: " << b << endl;
	return (a >= b) ? a : b;
}


template <typename T>
T add(T a, T b)
{
	return a + b;
}

/*
int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

string add(string a, string b)
{
	return a + b;
}
*/

template <typename S>
void myswap(S& a, S& b)
{
	S temp;
	temp = a;
	a = b;
	b = temp;
}


//Ŭ���� ���ø� ����
template <typename T>
class CMyData
{
private:
	T data;
public:
	CMyData(T param) { data = param; }
	T GetData() { return data; }
	void SetData(T p) { data = p; }

	/*
	CMyData a;
	CMyData b;
	a + b //������ �����ε�

	1) �Ϲ��Լ�
	2) ����Լ�(�켱����)
		a + b
		a.operator+(b)
	*/
	CMyData operator+(CMyData& param)
	{
		this->data = this->data + param.data;
		return *this;
	}
};


template <typename T> class MyMyStack
{
private:
	int m_top = -1;
	int m_size = 0;
	T* m_buff = NULL;
public:
	MyMyStack(int max)
	{
		m_size = max;
		m_buff = new T[m_size];
	}
	~MyMyStack()
	{
		delete[] m_buff;
	}
	bool Push(T value)
	{
		//check max
		if (m_top == (m_size - 1))//return 0;
		{
			cout << "Overflow : Program Terminated\n";
			exit(EXIT_FAILURE);
		}

		m_top++;
		m_buff[m_top] = value;
		return 1;
	}

	T Pop(void)
	{
		//check empty
		if (m_top == -1) //return 0;
		{
			cout << "Underflow : Program Terminated\n";
			exit(EXIT_FAILURE);
		}

		T temp = m_buff[m_top];
		m_top--;
		return temp;
	}
};

class Human
{
public:
	string name;
	int age;

	Human()
	{
		this->name = "�̸�����";
		this->age = 0;
	}
	Human(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	void PrintData()
	{
		cout << name << ", " << age << endl;
	}
};

int main()
{
	//�Լ� ���ø� 1
	if (1)
	{
		cout << add(10, 20) << endl;//int
		cout << add(10.5, 20.6) << endl;//double

		//cout << add("���ѹα�", "����") << endl;//error : char*
		//		error: char*�� operator+ ������ �Ǿ� ���� ����
		//string x = "���ѹα�" + "����";

		string a = "���ѹα�";
		string b = "����";
		cout << add(a, b) << endl;//string : operator+ ������ �Ǿ� ����

		///////////////////////
		CMyData<double> x(22.1);
		CMyData<double> y(33.3);
		cout << add(x, y).GetData() << endl;
		//		error: CMyData�� operator+ ������ �Ǿ� ���� ����
		//		==> operator+ ����������
	}
	//�Լ� ���ø� 2
	if (0)
	{
		//////////////////////////////////////
		//1. �Ͻ��� �߷�(by �����Ϸ�)
		cout << mymax(10, 20) << endl;//int
		cout << mymax(30, 40) << endl;//int
		cout << mymax(50, 60) << endl;//int
		cout << mymax(10.5, 20.9) << endl;//double
		cout << mymax('c', 'a') << endl;//char

		//////////////////////////////////////
		//2. ����� ����(by �ΰ�)
		//cout << mymax('c', 10) << endl;//char
		//cout << mymax<int>(10, 20.9) << endl;//int
		//cout << mymax<double>(10, 20.9) << endl;//double
	}
	//�Լ� ���ø� 3
	if (0)
	{
		int i = 50;
		int j = 10;
		cout << "Before " << "i = " << i << ", j = " << j << endl;
		myswap(i, j); //������ int�� ó���ϴ� myswap�Լ��� �����ȴ�.
		cout << "After " << "i = " << i << ", j = " << j << endl;

		//////
		char ch1 = 'A';
		char ch2 = 'Z';
		cout << "Before " << "ch1 = " << ch1 << ", ch2 = " << ch2 << endl;
		myswap(ch1, ch2); //������ char�� ó���ϴ� myswap�Լ��� �����ȴ�.
		cout << "After " << "ch1 = " << ch1 << ", ch2 = " << ch2 << endl;
	}

	//Ŭ���� ���ø� 1
	if (0)
	{
		CMyData<int> a(100);
		cout << a.GetData() << endl;
		a.SetData(90);
		cout << a.GetData() << endl;

		CMyData<double> b(100.5);
		cout << b.GetData() << endl;
		b.SetData(90.6);
		cout << b.GetData() << endl;
	}

	//Ŭ���� ���ø�2 - ����
	if (0)
	{
		MyMyStack<int> my(5);

		my.Push(1);
		my.Push(2);
		my.Push(3);
		my.Push(4);

		cout << my.Pop() << endl;
		cout << my.Pop() << endl;
		cout << my.Pop() << endl;
		//cout << my.Pop() << endl;
		//cout << my.Pop() << endl;
		//cout << my.Pop() << endl;
		//cout << my.Pop() << endl;

		//////////////////////////////////
		MyMyStack<string> your(5);

		string a = "ȣ����";	your.Push(a);
		string b = "�缮��";	your.Push(b);
		string c = "�ռ���";	your.Push(c);

		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		cout << your.Pop() << endl;
		//cout << your.Pop() << endl;//run-time error : ���� ���� ����ȵ�

		//////////////////////////////////
		MyMyStack < double > his(5);

		his.Push(1.23);
		his.Push(2.0);
		his.Push(3.14);

		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
		cout << his.Pop() << endl;
	}

	//Ŭ���� ���ø�3 - ����+class
	if (0)
	{
		MyMyStack<Human> myFriend(5);
		Human a("�浿��", 12);		myFriend.Push(a);
		Human b("Tom", 43);			myFriend.Push(b);
		Human c("�⿵��", 14);		myFriend.Push(c);

		Human p = myFriend.Pop();
		p.PrintData();
		myFriend.Pop().PrintData();
		myFriend.Pop().PrintData();
	}
	return 0;
}

#endif