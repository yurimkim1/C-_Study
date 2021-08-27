//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <stack>

#include <algorithm>

int myCompare(int a, int b)
{
	return a > b;//<
}

int main()
{
	//�����̳�(container)
	if (0)
	{
		//1.�迭 : ���ӵ� �޸� - ũ�⸦ ������ �� ����
		int x[10] = { 1, 2, 3, };

		//2. STL �迭 - ���ӵ� �޸�
		std::array<int, 10> a = { 1, 2, 3 };	//ũ�⸦ ������ �� ����		
		std::vector<int>    v = { 1, 2, 3 };	//ũ�⸦ ������ �� �ִ�
		v.resize(5);

		//3. STL ����Ʈ - ���ӵ��� ���� �޸�
		std::list<int> s = { 1, 2, 3 };

		////////////////////////////////////////////
		// *********** �����̳� *********** 
		////////////////////////////////////////////
		//1. ���ø����� ������� �ִ�
		//
		//2. ����Լ��� �̸��� ��� �����ϴ�
		//	1) ���� : push_front(), push_back(), insert() 
		//			(stack::push()�� ����)
		//			(vector�� �տ� ���ԺҰ� --> push_front()����-�����̽�)
		//	2) ���� : pop_front(), pop_back(), erase() 
		//			(stack::pop()�� ����)
		//	3) ���� : front(), back(), at()  
		//			(stack::top()�� ����)
		//  ** ���ſ� ������ ���ÿ� �̷����� ����

		vector<int> score;
		for (int i = 0; i < 10; i++)
		{
			score.push_back(i * 10);
		}
		for (auto& n : score)//������� for(C++11)
		{
			cout << n << endl;
		}

		////////////////////////////////
		stack<int> my;
		my.push(10);
		my.push(20);

		//int temp = s.pop();//error : pop�� ������, ������ ���� ����
		int temp;
		temp = my.top();//20 ������, ���Ŵ� ����
		cout << temp << endl;
		temp = my.top();//10 ������????-> ������ 20 ������
		cout << temp << endl;

		my.pop();//����
		temp = my.top();//����
		cout << temp << endl;

		///////////////////////////////////
		std::vector<int> your = { 1, 2, 3 };
		auto& n = your.front();//�Ǿ� ��ҷ� ����
		cout << n << endl;//1

		your.pop_back();//����

		n = your.back();//�ǵ� ��ҷ� ����
		cout << n << endl;//2

	}

	//�ݺ���(iterator)
	if (0)
	{
		int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//�迭
		int* p1 = x;
		p1++;//2
		cout << p1 << endl;//�ּ�
		cout << *p1 << endl;//�� : 2

		auto p4 = begin(x);//�Ϲ��Լ�(C++11)

		//////////////////////////////////////////
		//�ݺ���
		//: �����̳��� ��Ҹ� ����Ű�� �����Ϳ� ������ ��ü
		//: ++, * �����ڸ� ������ �ؼ� �����Ϳ� �����ϰ� �����ϵ��� �����
		//: ����Լ� begin()�� ���ؼ� ���� �� �ִ�
		//: �Ϲ��Լ� begin()�� �����ȴ�(C++11����)
		//: std::vector<int>::iterator�� ��Ȯ�� Ÿ�� (auto�� ���ϰ� ���)
		std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//�����迭

		//std::vector<int>::iterator	p2 = v.begin();//���Ĺ��
		auto p2 = v.begin();//������
		p2++;
		//cout << p2 << endl;//�ּ�
		cout << *p2 << endl;//�� : 2

		///////////////////////////////
		auto p3 = begin(v);//�Ϲ��Լ�(C++11)
		p3++;
		p3++;
		cout << *p3 << endl;//�� : 3
	}

	//�ݺ��ڿ��� ������(begin()/end())
	if (0)
	{
		std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//std::list<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//int v[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		//std::vector<int>::iterator p1 = v.begin();//ù��Ҹ� ����Ŵ
		//std::vector<int>::iterator p2 = v.end();//�������� ������Ҹ� ����Ŵ

		//����Լ����ٴ� "�Ϲ��Լ�"�� ����ϸ�,
		//STL�� �迭�� �����ϸ鼭 ����ϱ� ������
		//auto p1 = v.begin();//ù��Ҹ� ����Ŵ
		//auto p2 = v.end();//�������� ������Ҹ� ����Ŵ
		auto p1 = begin(v);//ù��Ҹ� ����Ŵ
		auto p2 = end(v);//�������� ������Ҹ� ����Ŵ

		*p1 = 100;
		//*p2 = 100;//runtime error

		while (p1 != p2)
		{
			cout << *p1 << endl;
			p1++;
		}
	}

	//�����̳��� ��Ҹ� �����ϴ� 3���� ���
	if (0)
	{
		list<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//STL vector

		//1. �迭������ [] ��� (��, list�� ���Ұ�)
		//for (int i = 0; i < v.size(); i++)
		//	;//cout << v[i] << endl;
		//cout << "----------------------" << endl;

		//2. range-for�� ���
		for (auto& item : v)
			cout << item << endl;
		cout << "----------------------" << endl;

		//3. �ݺ��� ���
		auto p = begin(v);
		while (p != end(v))
		{
			cout << *p << endl;
			p++;
		}
	}

	//�˰���(Algorithm)
	if (0)
	{
		//	: #include <algorithm> �ʿ�
		//	: �˰����� ����Լ��� �ƴϴ�
		//	: �Ϲ��Լ��� �����ؼ� �ϳ��� �Լ��� �پ��� �����̳ʸ� ������
		//	: �ڷᱸ���� �������̴�
		// www.cppreference.com���� �پ��� �˰��� ���� (��������)

		//vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		//list<int> data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		int data[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		//1. reverse()
		//reverse(data.begin(), data.end());//����Լ� - �����̳�
		reverse(begin(data), end(data));//�Ϲ��Լ�(C++11) - �����̳�, C�� �迭
		for (auto& n : data)
			cout << n << ", ";
		cout << endl << endl;

		//2. sort()
		sort(begin(data), end(data));
		//auto p = begin(data);
		//sort(p, p+5);
		for (auto& n : data)
			cout << n << ", ";
		cout << endl << endl;

		//3. find()
		// : [first, last) ������ �����˻��� �����Ѵ�.
		// : last�� �˻��� ����� �ƴϴ�
		// : �˻� ���н�, 0�� �ƴ� last�� ��ȯ�Ѵ�
		auto hit = find(begin(data), end(data), 17);
		if (hit == end(data))
			cout << "�˻� ����" << endl;
		else
			cout << "�˻� ���� : " << *hit << endl;
	}

	//��å����(Policy) - �˰����� ��å����
	if (1)
	{

		std::vector<int> v = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

		for (auto& n : v) std::cout << n << endl;
		//std::sort(begin(v), end(v));//�������� ����
		//for (auto& n : v) std::cout << n << endl;

		//1. �Ϲ��Լ� ���
		//std::sort(begin(v), end(v), myCompare);//�������� ����
		//for (auto& n : v) std::cout << n << endl;

		//2. �Լ���ü ���(<functional>)
		std::greater<int> ggg;// >
		//std::sort(begin(v), end(v), ggg);
		//for (auto& n : v) std::cout << n << endl;

		//3. ���� ǥ���� ���(C++11) - "�̸��� ���� �Լ�"
		std::sort(begin(v), end(v),
			[](int a, int b) {return a > b; });
		for (auto& n : v) std::cout << n << endl;
	}

	return 0;
}

#endif