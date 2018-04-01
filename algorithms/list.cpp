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
		cout << list->end->val << endl;
	}
	 
	ListItem<int> *cur = list->first();
	while (cur) {
		cout << cur->val << endl;
		cur = cur->next;
	}

	system("pause");
	return 0;
}
