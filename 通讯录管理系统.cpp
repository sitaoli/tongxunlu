#include<iostream>
using namespace std;

#define MAX 1000
//��ϵ�˵Ľṹ��
struct Person
{
	string m_name;
	//�Ա� 1����  2��Ů
	int m_sex;
	int m_age;
	string m_number;
	string m_adrr;
};

//ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personarray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};
//�����ϵ��
void addperson(Addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1-------��" << endl;
		cout << "2-------Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1,2�������˳�ѭ��
			//������������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string number;
		cin >> number;
		abs->personarray[abs->m_size].m_number = number;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_adrr = address;

		//����ͨѶ¼����
		abs->m_size++;
			 

		cout << "��ӳɹ���" << endl;

		system("pause");//�����������
		system("cls");//��������
	}
}

//��ʾ������ϵ��
void showperson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personarray[i].m_name << "\t";
			cout << "�Ա�" <<( abs->personarray[i].m_sex == 1 ? "��":"Ů" )<< "\t";
			cout << "���䣺" << abs->personarray[i].m_age << "\t";
			cout << "�绰��" << abs->personarray[i].m_number << "\t";
			cout << "סַ��" << abs->personarray[i].m_adrr << endl;
		}
	}

	system("pause");
	system("cls");
}

//�����ϵ���Ƿ����
//����1��ͨѶ¼ ����2���Ա�����
int isexist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//�ҵ��ˣ���������±�
		}
	}
	return -1;
}

//ɾ����ϵ��
void deleteperson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//�鵽�ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ��
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//����ָ����ϵ��
void findperson(Addressbooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personarray[ret].m_name << "\t";
		cout << "�Ա�" << abs->personarray[ret].m_sex << "\t";
		cout << "���䣺" << abs->personarray[ret].m_age << "\t";
		cout << "�绰��" << abs->personarray[ret].m_number << "\t";
		cout << "סַ��" << abs->personarray[ret].m_adrr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifyperson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1-------��" << endl;
		cout << "2-------Ů" << endl;
		int sex = 0;

		while (true)
		{
			//����������1,2�������˳�ѭ��
			//������������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string number;
		cin >> number;
		abs->personarray[ret].m_number = number;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_adrr = address;
		
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}

//���
void cleanperson(Addressbooks* abs)
{
	abs->m_size = 0;//����ǰ��¼��ϵ��������0�����߼��ϵ����
	cout << "ͨѶ¼�Ѿ����" << endl;
	system("pause");
	system("cls");
}


//�˵�����
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_size = 0;


	int select = 0;//�����û�ѡ������ı���

	while (true)
	{

		showMenu();
		cin >> select;
	
		switch (select)
		{
		case 1://�����ϵ��
			addperson(&abs);//���õ�ַ����
			break;
		case 2://��ʾ��ϵ��
			showperson(&abs);
			break;
		case 3://ɾ����ϵ��
		/*����һ���������
		{
			cout << "������ɾ����ϵ��������" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ��������" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4://������ϵ��
			findperson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyperson(&abs);
			break;
		case 6://�����ϵ�� 
			cleanperson(&abs);
			break;
		case 0://
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	//��һ���޸ģ�ֻ�ǿ�һ����ʲô��ͬ��

	system("pause");
	return 0;
}