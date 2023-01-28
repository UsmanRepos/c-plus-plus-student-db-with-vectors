#include<iostream>
#include<vector>
#include<string>
#define SUB 3

using namespace std;

class Student {
	int regNo;
	string name;
	int    subMarks[SUB];
	double average;
	char   grade;
public:
	void mySetter();
	void myGetter();
	int  getReg();
};
int Student::getReg()
{
	return regNo;
}
void Student::mySetter()
{
	int sum = 0;

	cout << " Enter RegNo: ";
	while (true)
	{
		cin >> regNo;
		if (regNo > 1000 && regNo < 9999)
			break;
		else
			cout << " Invalid Range !!! \n Enter Again: ";
	}

	cin.ignore(10, '\n');
	cout << " Enter Name: ";
	getline(cin, name);

	cout << " Enter Marks: ";
	for (int j = 0; j < SUB; j++)
	{
		while (true)
		{
			cin >> subMarks[j];
			if (subMarks[j] >= 0 && subMarks[j] <= 100)
				break;
			else
				cout << " Invalid Range !!! \n Enter Again: ";
		}
		sum += subMarks[j];
	}
	average = (sum * 1.0) / SUB;

	if (average >= 80)
		grade = 'A';
	else if (average >= 70)
		grade = 'B';
	else if (average >= 60)
		grade = 'C';
	else if (average >= 50)
		grade = 'D';
	else
		grade = 'F';

}
void Student::myGetter()
{
	cout << "\n " << regNo << "  " << name << "  ";
	for (int i = 0; i < SUB; i++)
	{
		cout << subMarks[i] << " ";
	}
	cout << average << "  " << grade << "  ";
	cout << endl;
}

int main()
{
	vector<Student> student; 
	Student stu;
	int n = 0, regNo, index = -1;
	char ch;

	while (true) {
		cout << "\n ------------(MAIN MENU)-----------\n";
		cout << " 1) CREATE DATABASE \n";
		cout << " 2) GETTER \n";
		cout << " 3) APPEND NEW RECORD \n";
		cout << " 4) DELETION \n";
		cout << " 5) UPDATION \n";
		cout << " 6) SORTING \n";
		cout << " 7) EXIT \n\n";

		cout << " Enter Your Choice: ";
		cin >> ch;

		switch (ch) {
		case '1':
			cout << "\n Enter The Total Number Of Student: ";
			while (true)
			{
				cin >> n;
				if (n < 70 && n > 0)
				{
					break;
				}
				else
					cout << " Invalid Range !!! \n Enter Again: ";
			}
			for (int i = 0; i < n; i++)
			{
				cout << " Enter The Data For Student No " << i + 1 << endl;
				stu.mySetter();
				student.push_back(stu);
				cout << endl;
			}
			break;
		case '2':
			if (student.empty())
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Getter Operation.\n";
			else
			{
				for (int i = 0; i < student.size(); i++)
				{
					student[i].myGetter();
				}
			}

			break;
		case '3':
			cout << " Enter The Data For Student You Want To Append ..." << endl;
			stu.mySetter();
			student.push_back(stu);
			cout << "\n Append New Record Successfully ... !!!\n";
			break;
		case '4':
			if (student.empty())
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Delete Operation.\n";
			else
			{
				cout << "n: " << n;
				cout << " Enter The RegNo Of Student You Want To Delete: ";
				cin >> regNo;
				for (int i = 0; i < student.size(); i++)
				{
					if (student[i].getReg() == regNo)
					{
						index = i;
						break;
					}
				}
				if (index >= 0)
				{
					student.erase(student.begin() + index);
					index = -1;
					cout << "\n Delete The Record Successfully ... !!!\n";
				}
				else
					cout << "\n RegNo Not Found ... !!!\n";
			}
			break;
		case '5':
			if (student.empty())
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Update Operation.\n";
			else
			{
				cout << " Enter The RegNo Of Student You Want To Update: ";
				cin >> regNo;
				for (int i = 0; i < student.size(); i++)
				{
					cout << "bahir: " << i << endl;
					if (student[i].getReg() == regNo)
					{
						cout << "ander: " << i << endl;
						index = i;
						break;
					}
				}
				if (index >= 0)
				{
					student[index].mySetter();
					index = -1;
					cout << "\n Update The Record Successfully ... !!!\n";
				}
				else
					cout << "\n RegNo Not Found ... !!!\n";
			}
			break;
		case '6':
			if (student.empty())
				cout << " Data Base is Empty ...!!! \n First Create Database Then Perform Sorting.\n";
			else
			{
				for (int i = 0; i < n - 1; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (student[i].getReg() > student[j].getReg())
						{
							swap(student[i], student[j]);
						}
					}
				}
				cout << "\n Sort The Data Successfully ... !!!\n";
			}
			break;
		case '7':
			exit(-1);
		default:
			cout << "\n Invalid Input ... !!!\n";
		}

	}
}
















