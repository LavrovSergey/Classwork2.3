#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include "windows.h"
using namespace std;

int menu_start();

struct Data {
	char nomer[9];
	char name[25];
	int num;
};

struct Node {
	Data bus;
	Node* next;
	Node* prev;
};


struct List {
	Node* head=NULL;
	Node* tail=NULL;
	void creat(){
		int n;
		cout << "Numder of buses" << endl;
		cin >> n;
		Node* cur = new Node;
		cout << "Number of bus: ";
		cin>>cur->bus.nomer;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Drivers name: ";
		cin>>cur->bus.name;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Number of route: ";
        cin >> cur->bus.num;
		cur->prev = NULL;
		cur->next = NULL;
		head = cur;
		tail = cur;
		for (int i = 1; i < n; i++)
		{
			Node* cur = new Node;
			cout << "Number of bus: ";
			cin >> cur->bus.nomer;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Drivers name: ";
			cin >> cur->bus.name;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Number of route: ";
			cin >> cur->bus.num;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cur->prev = tail;
			tail->next = cur;
			tail = cur;
			tail->next = NULL;
		}
	};
	Node* find(char nomer[8]) {
		int a = 0;
		Node* cur = head;
		while (cur && strcmp(cur->bus.nomer, nomer))
		{
			if (strcmp(cur->bus.nomer, nomer)) {
				cur = cur->next;
			}
		}
		 return cur;
	}
	void last(Node* p)
	{
		Node* cur = new Node;
		cout << "Number of bus: ";
		strcpy(cur->bus.nomer, p->bus.nomer);
		cout << cur->bus.nomer<<endl;
		cout << "Drivers name: ";
		strcpy(cur->bus.name, p->bus.name);
		cout<< cur->bus.name;
		cout << "Number of route: ";
		cur->bus.num=p->bus.num;
		cout << cur->bus.num;
		cur->next = NULL;
		if (head == NULL) {                          
			cur->prev = NULL;
			head = cur;
			tail = cur;
		}
		else{
			cur->prev = tail;
			tail->next = cur;
			tail = cur;
		}
		cout << "Now on route"<<endl;
		system("pause");
	}
	int show() {
		Node* cur = head;
		int a = 1;
		if (head == NULL) { cout << "Empty" << endl; system("pause"); }
		else {
			do {
				cout << "Number of bus: ";
				cout << cur->bus.nomer << endl;
				cout << "Drivers name: ";
				cout << cur->bus.name << endl;
				cout << "Number of route: ";
				cout << cur->bus.num << endl;
				cur = cur->next;
			} while (cur != NULL);
			a = 2;
		}
		 int code;
		 cout << "Press ENTER to continue"<<endl;
		do {
			code = _getch();
		 }
	    while (code != 13);
		 return a;
	}
	void del(Node* p, char nomer[8]) {
		if (head == p) {
			head = p->next;
			if (head) { head->prev = NULL; }
			else (tail = NULL);
		}
		else {
			p->prev->next = p->next;
			if (p->next) { p->next->prev = p->prev; }
			else (tail = NULL);
		}
		delete p;
	}
};

int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Заполнить список" << endl;
		else  cout << "   Заполнить список" << endl;
		if (key == 1) cout << "-> Отправился в дорогу" << endl;
		else  cout << "   Отправился в дорогу" << endl;
		if (key == 2) cout << "-> Вернулся" << endl;
		else  cout << "   Вернулся" << endl;
		if (key == 3) cout << "-> Кто в парке" << endl;
		else  cout << "   Кто в парке" << endl;
		if (key == 4) cout << "-> Кто на маршруте" << endl;
		else  cout << "   Кто на маршруте" << endl;
		if (key == 5) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int main(bool isRunning)
{
	List park, route;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	isRunning = true;
	Node* p;
	char nomer[8];
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0:park.creat(); break;
		case 1: {
			if (park.show() == 1)
			{
				cout << "empty" << endl; system("pause"); break;
			}
			else
			{
				cout << "Enter number of bus"<<endl; cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
				cin >> nomer; p = park.find(nomer);
				if (p == 0)
				{
					cout << "Такого нет"<<endl; system("pause"); break;
				}
				else {
					route.last(p);
					park.del(p, nomer);
				}
				break;
			}
		}
		case 2: {
			if (route.show() == 1) 
			{
				cout << "empty" << endl; system("pause"); break;
			}
			else {
				cout << "Enter number of bus"; cin.clear(); cin.ignore(cin.rdbuf()->in_avail());
				cin >> nomer;
				p = route.find(nomer);
				if (p == 0) { cout << "Такого нет"; system("pause"); break; }
				else {
					park.last(p);
					route.del(p, nomer);
				}
				break;
			}
		}
		case 3:park.show(); break;
		case 4:route.show(); break;
		case 5: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}