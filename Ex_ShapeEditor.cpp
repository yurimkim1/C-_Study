#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

/*
* ���� ������ ����
* -------------------------------
* 1.  �� ������ Ÿ������ ����� ���ϴ�(ĸ��ȭ)
*	ex) �簢���� int 4���� �����ϱ� ���ٴ� ĸ���� ����� ��
* 2. ��� ������ ������ Ư¡�� ��� Ŭ����(Shape)���� �����Ѵ�
* 3. ���� ������ �����ϱ� ���� vector�� ����Ѵ�
	ex) vector<Rect*> v1;//Rect�� �����Ѵ�
	ex) vector<Circle*> v2;//Circle�� �����Ѵ�
* 4. ��� ������ ������ Ư¡(Draw)�� �ݵ�� ��� Ŭ����(Shape)���� �־�� �Ѵ�
* 5. ��� Ŭ������ �Լ� �� �Ļ� Ŭ������ ������ �ϰ� �Ǵ� ��� �Լ��� "���� �Լ�"�� �Ǿ�� �Ѵ�.(������)


*/

class Shape
{
public:
	int x, y;
	int color;
	virtual void Draw() { cout << "Shape Draw" << endl; }
};

class Rect : public Shape
{
public:
	int w, h;
	virtual void Draw() override
	{ 
		cout << "Rect Draw" << endl; 
	}
};

class Circle : public Shape
{
public:
	int r;
	virtual void Draw() override 
	{ 
		cout << "Circle Draw" << endl; 
	}
};

class Triangle : public Shape
{
public:
	int a, b;
	virtual void Draw() override
	{
		cout << "Triangle Draw" << endl;
	}
};

#include <vector>//���ӵ� �޸�
#include <list>	//�񿬼ӵ� �޸�
int main()
{

	cout << "-------------------------------------------" << endl;
	cout << "	����������" << endl;
	cout << "-------------------------------------------" << endl;
	//cout << "1.  Rect �׸���\t2. Circle �׸���\t9.All Draw" << endl;
	cout << "1.  Rect �׸���\t2. Circle �׸���\t3. Triangle �׸���\t9.All Draw" << endl;
	cout << "-------------------------------------------" << endl;

	//vector < Rect > v1;		//Rect�� ����
	//vector < Circle > v2;	//Circle�� �����Ѵ�

	//Rect v1[30];
	//Circle v2[30];

	vector< Shape*> v;//�θ��� �����ͷδ� �ڽ��� ����ų �� �ִ�(no error)
					  //�ڽ��� �����ͷδ� �θ� ����ų �� �ִ�(error)

	while (1)
	{
		int menu;
		cin >> menu;

		switch (menu)
		{
		case 1://Rect �׸���
			v.push_back(new Rect);
			break;

		case 2://Circle �׸���
			v.push_back(new Circle);
			break;

		case 3://Triangle �׸���
			v.push_back(new Triangle);
			break;

		case 9://All Draw
			for (auto& p : v)
			{
				p->Draw();//���� ���ε�(�⺻) --> ���� ���ε�(virtual)
				// : OCP(Open Close Principle)
				/*
				* ������ (Polymorphism)
				* :  ������ �ڵ� ǥ��(�Լ� ȣ��)�� ��Ȳ�� ���� �ٸ��� �����ϴ� ��
				*
				* OCP(Open Close Principle)
				* : ��� Ȯ�忡�� ���� �ְ� (Open)
				* : �ڵ� �������� ���� �־�� (Close)
				* : �Ѵٴ� �̷� (Principle)
				* : ==> �������� OCP�� ������ �� �ִ� ���� �ڵ��̴�
				*/

			}
			break;
		}
	}
	return 0;
}

#endif