#include <iostream>
#include <ctime>

void char_bubble_sort(char* begin, char* end) {
	bool is_sorted = false;
	char swapper = '\0';
	while (!is_sorted) {
		is_sorted = true;
		for (char* iter = begin; iter != end - 1; iter++) {
			if (*iter > * (iter + 1)) {
				is_sorted = false;
				swapper = *iter; *iter = *(iter + 1); *(iter + 1) = swapper;
			}
		}
	}
}


void randFill(char* begin, char* end, char max) { //заполняет массив целыми значениями от 0 до max
	for (char* iter = begin; iter != end; iter++) {
		*iter = char((rand() * 1.0 / RAND_MAX) * (max + 1));
	}
}
void randFill(char* begin, char* end, char min,char max) { //заполняет массив целыми значениями от min до max
	max -= min;
	for (char* iter = begin; iter != end; iter++) {
		*iter = char((rand() * 1.0 / RAND_MAX) * (max + 1)) + min;
	}
}

int main()
{
	using namespace std;
	setlocale(0, "");
	char array[10];
	srand(time(0));
	rand(); //почему то первый ранд всегда возвращает одно и то же значение, этим вызовом делаем первое задаваемое значение менее предсказуемым
	randFill(array, array + 9, 65,122);
	char_bubble_sort(array, array + 9);
	for (int i = 0; i != 9; i++) {
		cout << array[i] << ' ';
	}
	return 0;
}