#include <iostream>
#include <ctime>
#include <vector>
#include <iterator>
#define ARRAY_SIZE 15


void char_bubble_sort(char* begin, char* end) {							//пузырь
	bool is_sorted = false;
	end=end-1;
	char swapper = '\0';
	while (!is_sorted) {
		is_sorted = true;
		for (char* iter = begin; iter != end; iter++) {
			if (*iter > * (iter + 1)) {
				is_sorted = false;
				swapper = *iter; *iter = *(iter + 1); *(iter + 1) = swapper;
			}
		}
	}
}

void slow_sort(char * begin, char * end) {
	int sizeOfArray = end - begin;
	if (sizeOfArray>1) {
		bool is_sorted = false;
		char swapper;
		char* core=begin+sizeOfArray/2;
		while (!is_sorted) {
			is_sorted = true;
			for (auto iter = begin; iter != core; iter++) {				//то, что меньше, налево
				if (*iter > *core) {
					is_sorted = false;
					swapper = *iter; *iter = *core; *core = swapper;
				}
			} 
			for (auto iter = core+1; iter != end; iter++) {				//то, что больше, направо
				if (*iter < *core) {
					is_sorted = false;
					swapper = *iter; *iter = *core; *core = swapper;
				}
			}

		}

		slow_sort(begin, core);
		slow_sort(core+1, end);

	}
}

void randFill(char* begin, char* end, char max) {						 //заполняет массив целыми значениями от 0 до max
	
	for (char* iter = begin; iter != end; iter++) {
		*iter = char((rand() * 1.0 / RAND_MAX) * (max + 1));
	}
}
void randFill(char* begin, char* end, char min,char max) {				 //заполняет массив целыми значениями от min до max
	max -= min;
	for (char* iter = begin; iter != end; iter++) {
		*iter = char((rand() * 1.0 / RAND_MAX) * (max + 1)) + min;
	}
}

void show(char* begin, char* end) {
	for (auto iter = begin; iter != end; iter++) {
		std::cout << *iter << ' ';
	}
}

int main()
{
	using namespace std;
	setlocale(0, "");
	char carray[ARRAY_SIZE + 1]; carray[ARRAY_SIZE] = '\0';
	srand(time(0));
	rand();																//почему то первый ранд всегда возвращает одно и то же значение, этим вызовом делаем первое задаваемое значение менее предсказуемым
	randFill(carray, carray + ARRAY_SIZE, 65,122);
	cout << "Массив (строка) случайных значений: ";
	cout << carray <<endl;
	char_bubble_sort(carray, carray + ARRAY_SIZE);
	cout << "Массив, отсортированный пузырьком: ";
	cout << carray << endl;
	cout << "Введите размер массива для сортировки: " ;
	int not_size = 0;
	cin >> not_size;
	while (not_size < 1) {
		cin.clear();
		cin.ignore(12345, '\n');
		cout << endl << "Ошибка ввода, введите размер заново: ";
		cin >> not_size;
	}
	char* not_array = new char[not_size+1];
	not_array[not_size] = 0;
	

	bool is_ready = false;
	cout << "\nВведите массив: " << endl;
	
	for (int i = 0; i < not_size; i++) {
		cin >> not_array[i];
	}


	slow_sort(not_array, not_array + not_size);
	cout << "Отсортированный массив: " << endl << not_array << endl;
	system("pause");
	return 0;
}