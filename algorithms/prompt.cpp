/**
 * Запрашивает от пользователя значение нужного типа
 * @param{char[]} label - текст, предложенный пользователю
 * 
 * Привет работы:
 * prompt<int>("Введите целое число: ");
 * prompt<char>("Введите символ: ");
 * prompt<string>("Введите строку: ");
*/
template <typename T>
T prompt(const char label[]) { 
	cout << label;

	while (true) {
		T val;
		cin >> val;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Произошла ошибка. Введите еще раз: ";
		}
		else {
			cin.ignore(32767, '\n');
			return val;
		}

	}

}