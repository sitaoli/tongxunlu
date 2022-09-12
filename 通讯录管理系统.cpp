#include<iostream>
using namespace std;

#define MAX 1000
//联系人的结构体
struct Person
{
	string m_name;
	//性别 1，男  2，女
	int m_sex;
	int m_age;
	string m_number;
	string m_adrr;
};

//通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personarray[MAX];
	//通讯录中当前记录联系人个数
	int m_size;
};
//添加联系人
void addperson(Addressbooks * abs)
{
	//判断通讯录是否已满
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[abs->m_size].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1-------男" << endl;
		cout << "2-------女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1,2，可以退出循环
			//如果输入的数其他，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;
		//联系电话
		cout << "请输入联系电话：" << endl;
		string number;
		cin >> number;
		abs->personarray[abs->m_size].m_number = number;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_adrr = address;

		//更新通讯录人数
		abs->m_size++;
			 

		cout << "添加成功！" << endl;

		system("pause");//按任意键继续
		system("cls");//清屏操作
	}
}

//显示所有联系人
void showperson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personarray[i].m_name << "\t";
			cout << "性别：" <<( abs->personarray[i].m_sex == 1 ? "男":"女" )<< "\t";
			cout << "年龄：" << abs->personarray[i].m_age << "\t";
			cout << "电话：" << abs->personarray[i].m_number << "\t";
			cout << "住址：" << abs->personarray[i].m_adrr << endl;
		}
	}

	system("pause");
	system("cls");
}

//检测联系人是否存在
//参数1：通讯录 参数2：对比姓名
int isexist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;//找到了，返回这个下标
		}
	}
	return -1;
}

//删除联系人
void deleteperson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//查到了，要进行删除操作
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

//查找指定联系人
void findperson(Addressbooks* abs)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personarray[ret].m_name << "\t";
		cout << "性别：" << abs->personarray[ret].m_sex << "\t";
		cout << "年龄：" << abs->personarray[ret].m_age << "\t";
		cout << "电话：" << abs->personarray[ret].m_number << "\t";
		cout << "住址：" << abs->personarray[ret].m_adrr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//修改联系人
void modifyperson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarray[ret].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1-------男" << endl;
		cout << "2-------女" << endl;
		int sex = 0;

		while (true)
		{
			//如果输入的是1,2，可以退出循环
			//如果输入的数其他，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].m_age = age;
		//联系电话
		cout << "请输入联系电话：" << endl;
		string number;
		cin >> number;
		abs->personarray[ret].m_number = number;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personarray[ret].m_adrr = address;
		
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//清空
void cleanperson(Addressbooks* abs)
{
	abs->m_size = 0;//将当前记录联系人数量置0，做逻辑上的清空
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}


//菜单界面
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;


	int select = 0;//创建用户选择输入的变量

	while (true)
	{

		showMenu();
		cin >> select;
	
		switch (select)
		{
		case 1://添加联系人
			addperson(&abs);//利用地址传递
			break;
		case 2://显示联系人
			showperson(&abs);
			break;
		case 3://删除联系人
		/*这是一个检验代码
		{
			cout << "请输入删除联系人姓名：" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到这个人了" << endl;
			}
		}*/
			deleteperson(&abs);
			break;
		case 4://查找联系人
			findperson(&abs);
			break;
		case 5://修改联系人
			modifyperson(&abs);
			break;
		case 6://清空联系人 
			cleanperson(&abs);
			break;
		case 0://
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	//第一次修改，只是看一下有什么不同的

	system("pause");
	return 0;
}