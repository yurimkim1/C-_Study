//#define ON_MAIN
#ifdef ON_MAIN
using namespace std;

#include <iostream>
#include <fstream>

/////////////////////////////////////////////////////////////////////////
// �ּҷ��� ����� ������ ����
#define DATA_FILE_NAME "c:\\temp\\AddrBook.dat"

/////////////////////////////////////////////////////////////////////////
void ReleaseList();

/////////////////////////////////////////////////////////////////////////
class UserData
{
public:
	string strName = "";		// �̸�
	int nAge = 0;				// ����
	int nGender = 0;			// ����

	//for ��ũ�� ����Ʈ
	UserData* pNext = NULL;	//���� ��Ҹ� ����Ű�� ��ũ
	UserData* pPrev = NULL;	//���� ��Ҹ� ����Ű�� ��ũ

	void PrintData()
	{
		cout << strName << ", ";
		cout << nAge << "��, ";
		cout << (nGender ? "����" : "����");
		cout << endl;
	}
};

//�迭�� ó��
#define		MAX_BOOKCOUNT	50
int			g_nCount = 0;
UserData	g_AddrBook[  MAX_BOOKCOUNT  ];//�����޸�

//��ũ�� ����Ʈ�� ó��
UserData*   g_HeapAddrBook;//�����޸�


///////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �迭�� �߰��ϴ� �Լ�
void Add()
{
	if (g_nCount + 1 > MAX_BOOKCOUNT)
	{
		cout << "�ԷºҰ� : �뷮�ʰ�" << endl;
		return;
	}

	cout << "�̸��� �Է��ϼ��� : ";
	cin >> g_AddrBook[g_nCount].strName;
	
	cout << "���̸� �Է��ϼ��� : ";
	cin >> g_AddrBook[g_nCount].nAge;

	cout << "������ �Է��ϼ���(����:0, ����:1) : ";
	cin >> g_AddrBook[g_nCount].nGender;

	g_nCount++;//�����Է¿�
}

/////////////////////////////////////////////////////////////////////////
// Ư�� ��带 �˻��ϴ� �Լ�
void Search()
{
	string strName;

	cout << "�˻��� �̸��� �Է��ϼ��� : ";
	cin >> strName;

	int nHit = 0;
	for (int i = 0; i < g_nCount; i++)
	{
		if (g_AddrBook[i].strName == strName)
		{
			g_AddrBook[i].PrintData();
			nHit++;
		}
	}		
	if (nHit == 0)
	{
		cout << "�����͸� ã�� �� �����ϴ�" << endl;
	}
}

/////////////////////////////////////////////////////////////////////////
// �迭�� ����ִ� ��� �����͸� ȭ�鿡 ����ϴ� �Լ�
void PrintAll()
{
	if (g_nCount == 0)
	{
		cout << "����� �����Ͱ� �����ϴ�" << endl;
		return;
	}

	for (int i = 0; i < g_nCount; i++)
	{
		g_AddrBook[i].PrintData();
	}
}

/////////////////////////////////////////////////////////////////////////
// �̸��� �Է¹޾� �ڷḦ �˻��ϰ� �����ϴ� �Լ�
void Remove()
{
	string strName;

	cout << "������ �̸��� �Է��ϼ��� : ";
	cin >> strName;

	int nHit = 0;
	for (int i = 0; i < g_nCount; i++)
	{
		if (g_AddrBook[i].strName == strName)
		{
			//����!!!
			//���� �����͸� �ϳ��� ���� �ø���
			for (int j=i; j< g_nCount; j++)
			{
				g_AddrBook[j].strName	= g_AddrBook[j + 1].strName;
				g_AddrBook[j].nAge		= g_AddrBook[j + 1].nAge;
				g_AddrBook[j].nGender	= g_AddrBook[j + 1].nGender;
			}
			nHit++;		
			g_nCount--;
		}
	}
	if (nHit == 0)
	{
		cout << "������ �����͸� ã�� �� �����ϴ�" << endl;
	}
}

/////////////////////////////////////////////////////////////////////////
// �޴��� ����ϴ� UI �Լ�
int PrintUI()
{
	int nInput = 0;

	cout << "===================================================\n";
	cout << "��ȭ��ȣ��(Array)\n";
	cout << "---------------------------------------------------\n";
	cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [4] ����\t [0] ����\n";
	//cout << "[1] �߰�\t [2] �˻�\t [3] ��ü����\t [0] ����\n";
	cout << "===================================================\n";

	// ����ڰ� ������ �޴��� ���� ��ȯ�Ѵ�.
	cin >> nInput;
	return nInput;
}

/////////////////////////////////////////////////////////////////////////
// ������ ���Ͽ��� ������ �о�� �迭�� �ϼ��ϴ� �Լ�
int LoadList(string strFileName)
{
	ifstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����(ũ��)
		f >> g_nCount;
		//������ ����
		for (int i = 0; i < g_nCount; i++)
		{
			f.read((char*)(g_AddrBook + i), sizeof(UserData));
		}
		f.close();
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////
// �迭 ���·� �����ϴ� ������ ���Ͽ� �����ϴ� �Լ�
int SaveList(string strFileName)
{
	ofstream f;
	f.open(strFileName, std::ios::binary);

	if (f.is_open())
	{
		//��� ����(ũ��)
		f << g_nCount;
		//������ ����
		for (int i=0; i<g_nCount; i++)
		{
			f.write((const char*)(g_AddrBook+i), sizeof(UserData));
		}
		f.close();
	}	
	return 0;
}

/////////////////////////////////////////////////////////////////////////
int main()
{
	int nMenu = 0;
	LoadList(DATA_FILE_NAME);

	// ���� �̺�Ʈ �ݺ���
	while ((nMenu = PrintUI()) != 0) {
		switch (nMenu) {
		case 1:		  // Add
			Add();
			break;

		case 2:		  // Search
			Search();
			break;

		case 3:		 // Print all
			PrintAll();
			break;

		case 4:		  // Remove
			Remove();
			break;

		default:
			cout << "�������� �ʴ� �޴��Դϴ�\n\n";
		}
	}

	// ���� ���� ���Ϸ� �����ϰ� �޸𸮸� �����Ѵ�.
	SaveList(DATA_FILE_NAME);
	return 0;
}
#endif