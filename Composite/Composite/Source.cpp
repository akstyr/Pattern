
/*#include "stdafx.h"  //���� 1 �� ������� //���� 2 �� �������
#include <iostream>
#include <vector>
using namespace std;

int i;

class Thing
{
public:
	string str = "Thing";
};

class Box
{
public:
	struct Entrails //������������ �������
	{
		string str = 0;
		vector <string&> vec;
		int id;
	};

	void Push_Box(string& ptr)
	{
		i++;
		Entrails->vec.push_back(ptr);
		Entrails->id = i;
	}

};

int main()
{


	system("Pause");
	return 0;
}*/