// Singleton.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
/*
class Singleton
{
private:
	bool pr = 0;
	Singleton() 
	{
		pr = 1;
	};
	~Singleton() {};
public:


};*/

class Singleton
{
public:
	int k;
public:
	static Singleton* Instance()
	{
		cout << "Singleton" << endl;
		static Singleton instance;
		return &instance;
	}

private:
	Singleton() 
	{
		cout << "Constructor" << endl;
	};
};

int main() {
	Singleton::Instance();

	Singleton::Instance();
	system("Pause");
	return 0;
}

