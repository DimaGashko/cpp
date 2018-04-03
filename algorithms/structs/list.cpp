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
		ListItem<T> *item = new ListItem<T>;
		item->val = n;
		end->next = item;

		end = item;
	}

	//Добавляет элемент после указанного элемента
	void insertAfter(ListItem<T> *prev, T n) {
		ListItem<T> *item = new ListItem<T>;
		item->val = n;
		item->next = prev->next;

		prev->next = item;
	};

	template<typename _Fn>
	void forEach(_Fn func, ListItem<T> *cur = NULL) {
		if (!cur) cur = first();
		
		while (cur) {
			bool answer = func(cur);
			if (!answer) return;

			cur = cur->next;
		}
	}

	//Возвращает ссылку на первый реальный элемент
	ListItem<T>* first() {
		return head->next;
	}

	//Иницилизирует список
	List* init() {
		head = new ListItem<T>;
		head->next = NULL;

		end = head;

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

	int arr[10] = { 25,56,10,11,96,32,18,23,21, 55 };

	/*for (int i = 1; i <= 10; i++) {
		list->push(i * 10);
	}*/

	for (int i = 0; i < 10; i++) {
		list->forEach([&arr, &list, i](auto *item) -> bool {
			if (arr[i] < item->val) {
				list->insertAfter(item, arr[i]);
				return false;
			}

			return true;

		}, list->head);

	}

	//list->insertAfter(list->head, 5);

	list->forEach([](auto *item) -> bool {
		cout << item->val << endl;
		return true;
	});

	system("pause");
	return 0;
}
