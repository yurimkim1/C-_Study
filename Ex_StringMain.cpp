//#define ON_MAIN 
#ifdef ON_MAIN

#include <stdio.h> 
#include <iostream> 

using namespace std;


#include "Ex_String.h"

int main()
{
	//C�� ���ڿ� ó��				- char[]
	if (0)
	{
		//char a = 'a';//1����			--> ����
		//char b = "a";//2����(a\n)		--> ���ڿ�(������ �迭)

		//�迭 : ������ �ڷḦ �� �����̸����� ��Ƽ� ����
		//int kor[10];
		//int math[] = { 100, 90, 80, 88, };
		//int eng[];//error

		//���ڿ� �迭
		char name[30] = "�ռ���";

		//���ڿ� �Լ�(C Lib)
		//name = "���缮";//�� �� �Ҵ�
		strcpy_s(name, 30, "���缮");

		//if (name == "���缮")//��
		//if (strcmp(name, "���缮") == 0);
	}

	//C++�� ���ڿ� ó��				- string
	if (0)
	{
		string a;//�ʱⰪ ����
		cout << a << endl;

		a = "���缮";//�� �� �Ҵ�
		cout << a << endl;

		string b(a);//�ʱⰪ ����
		cout << b << endl;

		string c("����ѹ�");//�ʱⰪ ����
		cout << c << endl;
	}

	//���� ���� MyString ��ü ���	- MyString
	if (0)
	{ 
		string x;//------------------------�⺻ ������
		x.assign("ȫ�浿");
		x.append("�ٺ�");
		//x.clear();
		cout << x << endl;

		string y("���缮");//---------------��ȯ ������
		cout << y << endl;

		string z(y);//----------------------���� ������
		cout << z << endl;

		z = x;//���Կ����� �����ε� �Ϸ�
		cout << z << endl;

		z = x + y;//================���������+ �����ε� �Ϸ�
		cout << z << endl;

		////////////////////////////////////////////////

		MyString a;//------------------------�⺻ ������
		a.SetString("�ռ���");
		//cout << a << endl;//error
		cout << a.GetString() << endl;

		MyString b("�ڸ��");//---------------��ȯ ������
		b.SetString("����");
		cout << b.GetString() << endl;

		MyString c(b);//----------------------���� ������
		cout << c.GetString() << endl;

		c = a;//============================= ���Կ����� �����ε�
		cout << c.GetString() << endl;	
		
		//c = a+b;//���������+ �����ε�
		//cout << c.GetString() << endl;
	}

	//�������(����, �Լ�)
	if (0)
	{
		cout << MyString::m_nCount << endl;

		MyString a;
		MyString b;
		cout << a.m_nCount << endl;
		{
			MyString c;
			cout << "��" << c.m_nCount << endl;
		}
		cout << b.m_nCount << endl;
		
	}

	//�߰�Ȯ��
	if (1)
	{
		//MyString a;
		//MyString b("ȫ�浿"); // �θ�(�⺻)�Ҹ��� �ڽ�(��ȯ)
		//MyString c(b); // �θ�(�⺻)�Ҹ��� �ڽ�(����)

		FunnyString x;
		x.SetString("�ٺ�");
		cout << x.GetString() << endl;
	}
	return 0;
}

#endif