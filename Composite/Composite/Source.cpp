
/*#include "stdafx.h"  //если 1 то коробка //если 2 то предмет
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
	struct Entrails //внутренности коробки
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