#pragma once

#ifndef LIST_H
#define LIST_H 

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
		auto *item = new ListItem<T>;
		item->val = n;
		end->next = item;

		end = item;
	}

	//Добавляет элемент после указанного элемента
	void insertAfter(ListItem<T> *prev, T n) {
		auto *item = new ListItem<T>;
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
auto getList() {
	return (new List<T>)->init();
}

#endif //LIST_H