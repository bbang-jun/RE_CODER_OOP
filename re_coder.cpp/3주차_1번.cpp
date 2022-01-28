#include <iostream>
#include <cstring>
using namespace std;

class univ
{
private:
	char U_Name[20]; // �б� �̸�
	int year; // �г�
	char U_StuID[20]; // �й�

public:
	void setU_name(char *U_Names){ strcpy(U_Name, U_Names); } // �б� �̸� setter �Լ�
	void setU_StuID(char* U_StuIDs) { strcpy(U_StuID, U_StuIDs); } // �й� setter �Լ�
	void setYear(int Years) { this->year = Years; } // �г� setter �Լ�
		
	char* getU_name() { return U_Name; } // �б� �̸� getter �Լ�(main���� ����ϱ� ����)
	char* getU_StuID() { return U_StuID; } // �й� getter �Լ�(main���� ����ϱ� ����)
	int getYear() { return year; } // �б� �̸� getter �Լ�(main���� ����ϱ� ����)
};

class cie :public univ
{
private:
	char Object_Oriented_Programming; // ���� ����
	char Digital_Logic_Circuit; // ��� ����

public:
	void setOOP(char OOPs) { this->Object_Oriented_Programming = OOPs; } // ���� ���� setter �Լ�
	void setDLC(char DLCs) { this->Digital_Logic_Circuit = DLCs; } // ��� ���� setter �Լ�

	char getOOP() { return Object_Oriented_Programming; } // ���� ���� getter �Լ�
	char getDLC() { return Digital_Logic_Circuit; } // ��� ���� getter �Լ�
};

class stu_infor :public cie
{
private:
	char Name[10]; // �л� �̸�
	int age; // �л� ����

public:
	void setName(char* Names) { strcpy(Name, Names); } // �л� �̸� setter �Լ�
	void setAge(int ages) { this->age = ages; } // �л� ���� setter �Լ�

	char* getName() { return Name; } // �л� �̸� getter �Լ�
	int getAge() { return age; } // �л� ���� getter �Լ�
};

int main(void)
{
	char choice[20]; // INSERT, FIND, EXIT ����
	char univ_name[20]; // �б� �̸�
	int stu_year; // �г�
	char OOP_grade; // ���� ����
	char DLC_grade; // ��� ����
	char stu_name[20]; // �л� �̸�
	char stu_num[20]; // �л� �й�
	int stu_age; // �л� ����
	int count = 0; // �迭 index
	stu_infor infor[100]; // Ŭ���� �迭


	while (1) // ���ѷ���
	{
		cin >> choice; 

		if (!strcmp(choice, "INSERT")) // �л� ���� �Է�
		{
			cout << "�б� : ";
			cin >> univ_name;
			infor[count].setU_name(univ_name);

			cout << "�й� : ";
			cin >> stu_num;
			infor[count].setU_StuID(stu_num);

			cout << "�г� : ";
			cin >> stu_year;
			infor[count].setYear(stu_year);

			cout << "��ü�������α׷��� ���� :";
			cin >> OOP_grade;
			infor[count].setOOP(OOP_grade);

			cout << "�����г�ȸ�� ���� :";
			cin >> DLC_grade;
			infor[count].setDLC(DLC_grade);

			cout << "�̸� :";
			cin >> stu_name;
			infor[count].setName(stu_name);

			cout << "���� :";
			cin >> stu_age;
			infor[count].setAge(stu_age);

			count++;
		}

		else if (!strcmp(choice, "FIND")) // �л� ���� �ҷ�����
		{
			cin >> stu_name >> stu_num;

			for (int j = 0; j < 100; j++)
			{
				if (!strcmp(stu_name, infor[j].getName()) && !strcmp(stu_num, infor[j].getU_StuID()))
				{
					cout << "�б� : " << infor[j].getU_name() << endl;
					cout << "�й� : " << infor[j].getU_StuID() << endl;
					cout << "�г� : " << infor[j].getYear() << endl;
					cout << "��ü�������α׷��� ���� :" << infor[j].getOOP() << endl;
					cout << "�����г�ȸ�� ���� :" << infor[j].getDLC() << endl;
				}
			}
		}
		else // INSERT, FIND ���� ��� ���ڵ��� ���� break(EXIT ����)
			break;
	}

	return 0;
}