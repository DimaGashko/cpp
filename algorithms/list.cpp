#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct ListItem {
	int val = NULL;
	ListItem *next = NULL;
};

struct List {
	ListItem *head, *end;

	void add(int n) {
		end->val = n;
		end = end->next = new ListItem;		
	}

	void init() {
		(head = new ListItem)->next = (end = new ListItem);
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	 
	List *list = new List;
	list->init();

	for (int i = 1; i <= 10; i++) {
		list->add(i * 10);
	}

	ListItem *cur = list->head->next; 
	while (cur->next) {
		cout << cur->val << endl;
		cur = cur->next; 
	}
	 
	system("pause");
	return 0;
}