#include <iostream>

using namespace std;

//Эллемент однонаправленного списка
template <typename T>
struct ListItem {
	T val = NULL;
	ListItem *next = NULL;
};

//Однонаправленный список
template<typename T>
struct List {
	ListItem<T> *head, *end;

	//Добавляет элемента в конец списка
	void push(T n) {
		end = end->next = new ListItem<T>;
		end->val = n;
	}

	//Добавляет элемент после указанного элемента
	void insertAfter(ListItem<T> *item, T n) {
		ListItem<T> *added = new ListItem<T>;
		added->val = n;

		added->next = item->next;
		item->next = added;
	};

	//Возвращает ссылку на первый реальный элемент
	ListItem<T>* first() {
		return head->next;
	}

	//Иницилизирует список
	List* init() {
		end = (head = new ListItem<T>);
		head->next = end;

		return this;
	}
};

//Возвращает однонаправленный список
//Пример исопльзования:
//List<int> *list = getList<int>();
template<typename T>
List<T>* getList() {
	return (new List<T>)->init();
}

int main() {
	List<int> *list = getList<int>();
	  
	for (int i = 1; i <= 10; i++) {
		list->push(i * 10);
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
