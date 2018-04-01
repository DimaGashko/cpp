#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

template <typename T>
struct ListItem {
	T val = NULL;
	ListItem *next = NULL;
};

template<typename T>
struct List {
	ListItem<T> *head, *end;

	void add(T n) {
		end = end->next = new ListItem<T>;
		end->val = n;
	}

	void insertAfter(ListItem<T> *item, T n) {
		ListItem<T> *added = new ListItem<T>;
		added->val = n;

		added->next = item->next;
		item->next = added;
	};

	ListItem<T>* first() {
		return head->next;
	}

	List* init() {
		end = (head = new ListItem<T>);
		head->next = end;

		return this;
	}
};

template<typename T>
List<T>* getList() {
	return (new List<T>)->init();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	List<int> *list = getList<int>();
	  
	for (int i = 1; i <= 10; i++) {
		list->add(i * 10);
		cout << list->end->val << " ";
	}
	cout << endl;

	list->insertAfter(list->first()->next->next->next->next, 55);

	ListItem<int> *cur = list->first();
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

	system("pause");
	return 0;
}
