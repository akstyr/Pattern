
#include "stdafx.h"
#include "fstream"
#include "string"
#include "queue"
#include "iostream"
using namespace std;

struct Thing
{
	string Data = "Thing";
	int ID;
};

struct Box
{
	string Data = "Box";
	Box *left;
	Thing *right;
	int ID;
};

class Treee
{
public:
	Box *parent = nullptr;
	Box *root = nullptr;
	int N = 1;

public:
	Treee() {};
	~Treee()
	{
		queue <Box*> q;
		queue <Thing*> k;
		q.push(root);

		while (!q.empty())
		{
			Box *fq = q.front();
			if (fq != nullptr)
			{
				Box *prost;
				Thing *prost2;
				if (fq->left != nullptr)
				{
					prost = fq->left;
					q.push(prost);
				}
				if (fq->right != nullptr)
				{
					prost2 = fq->right;
					k.push(prost2);
				}
				delete fq;
			}
			q.pop();
		}
		while (!k.empty())
		{
			k.pop();
		}
		parent = nullptr;
		root = nullptr;
		N = 0;
	};

	void Koren()
	{
		if (N == 1)
		{
			Box *b = new Box;
			b->ID = 1;
			b->Data = "Box";
			b->left = nullptr;
			b->right = nullptr;
			root = b;
			parent = b;
		}
	}

	int Push(string D, int id)
	{
		/*if ((D == "Thing") || (N == 0))
		{
			cout << "Thing не может быть корнем" << endl;
			return 3;
		}*/
		N++;

		if (D == "Box")
		{
			Box *b = new Box;
			b->ID = N;
			b->Data = "Box";
			b->left = nullptr;
			b->right = nullptr;

			Parent(id);
			if (parent == nullptr)
			{
				cout << "Ошибка" << endl;
				return 3;
			}
			parent->left = b;
			if (N <= 3)
				root->left = b;
		}
		else
		{
			if (N != 1)
			{
				Parent(id);
				Thing *t = new Thing;
				t->ID = N;
				t->Data = "Thing";
				parent->right = t;
				if (N <= 3)
					root->right = t;
			}
		}
		return 0;
	};

	bool Parent(int id)//ищет родителя
	{
		queue <Box*> myQueue; //очередь, в ней будут храниться адреса ячеек дерева
		if (root != nullptr)
		{
			Box ro = *root;
			myQueue.push(&ro); //первый элемент для сравнения - корень дерева
			while (true)
			{
				if (myQueue.empty() == true) //если очередь пуста => человек не найден
					return 0;
				Box *first = myQueue.front(); //работаем с первым элементом
				if (first->ID == id)//человек найден
				{
					parent = first;
					return 1;
				}
				else //первый элемент - не тот человек, которого мы ищем => удаляем его из очереди
					myQueue.pop();
				if (first->left != nullptr) //если есть левый, узел добавляем в очередь
					myQueue.push(first->left);
			}
		}
	};
	void Print(Box *q, int level, Thing *t)
	{
		if (q)
		{
			Print(q->left,  level + 1, 0);
			for (int i = 0; i < level; i++) cout << "    ";
			cout << q->ID << " " << q->Data << endl;
			Print(0, level + 1, q->right);
		}
		if (t)
		{
			for (int i = 0; i < level; i++) cout << "    ";
			cout << t->ID << " " << t->Data << endl;
			level = level + 1;
		}
	};
};

int main()
{
	setlocale(0, "");
	Treee tr;
	ifstream file("Composite_tree.txt");
	//cout << "Первая запись являеся корнем дерева. Напишите как в примере \n1 Box Box (Положить в первую коробку другую коробку) \n1 Box Thing(Положить в первую коробку вещь)\n Учтите, что в Thing не может ничего лежать\n";
	cout << "Box может содержать не более одной коробки и одной вещи,\n т.у. либо одна коробка, либо одна коробка и одна вещь.\n Thing вообще ничего не может хранить.";
	cout << endl;
	if (!file)
	{
		cout << "Ошибка, файл не найден" << endl;
		system("Pause");
		return 0;
		//system("Composite_tree.txt");
	}
	int iii;
	string tip;
	tr.Koren();
	while (!file.eof())
	{
		file >> iii;
		getline(file, tip);
		if (iii < 10)
			tip = tip.substr(5);
		else if (iii < 100)
			tip = tip.substr(6);
		else
		{
			cout << "Слишком большой номер коробки";
			system("Pause");
			return 0;
		};

		if (iii > tr.N)
		{
			cout << "Нет коробки с таким номером" << endl;
			system("Pause");
			return 0;
		}
		tr.Push(tip, iii);
	};
	file.close();
	tr.Print(tr.root, 0, 0);
	tr.~Treee();
	system("Pause");
	return 0;
};