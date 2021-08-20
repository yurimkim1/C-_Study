//���Ǻ�
#include <iostream>
using namespace std;

#include "Ex_String.h"

int MyString::m_nCount = 0;//��������� "����"�� ����� ��

//�⺻ ������
MyString::MyString()
	:m_nLength(0), m_pszData(NULL)
{
	m_nCount++;
	//m_nLength = 0;
	//m_pszData = NULL;
	cout << "MyString�� �⺻������" << endl;

}
//��ȯ ������
MyString::MyString(const char* pszParam)
	:m_nLength(0), m_pszData(NULL)
{
	m_nCount++;
	//m_nLength = 0;
	//m_pszData = NULL;
	cout << "MyString�� ��ȯ������" << endl;
	SetString(pszParam);
}
//���� ������
MyString::MyString(const MyString& pszParam)
	:m_nLength(0), m_pszData(NULL)
{
	m_nCount++;
	//m_nLength = 0;
	//m_pszData = NULL;
	cout << "MyString�� ���������" << endl;
	SetString(pszParam.GetString());
}

MyString::~MyString()
{
	m_nCount--;
	this->Release();
}

MyString& MyString::operator=(const MyString& right)
{
	// �ڱ� �ڽſ� ���� �����̸� �ƹ��͵� ���� �ʴ´�.
	if (this != &right)
		this->SetString(right.GetString());

	return *this;
}

int MyString::SetString(const char* pszParam)
{
	Release(); //���� ������ ����

	if (pszParam == NULL)
		return 0;
	int nLength = strlen(pszParam);
	if (nLength == 0)
		return 0;

	m_pszData = new char [nLength + 1];
	strcpy_s(m_pszData, sizeof(char)*(nLength+1),pszParam);

	m_nLength = nLength;

	return 0;
}

const char* MyString::GetString() const
{
	return m_pszData;
}

void MyString::Release()//���� �޸� �����Լ�
{
	if(m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}
