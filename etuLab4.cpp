

#include <iostream>
#include <ctime>
void char_bubble_sort(char* begin, char* end) {
	bool is_sorted = false;
	char swapper = '\0';
	while (!is_sorted) {
		is_sorted = true;
		for (char* iter = begin; iter != end-1; iter++) {
			if (*iter > * (iter + 1)) {
				is_sorted = false;
				swapper = *iter; *iter = *(iter + 1); *(iter + 1) = swapper;
			}
		}
	}
} 

void rand_intFill(int *begin, int *end, int max) { //заполняет массив целыми значениями от 0 до max
	for (int* iter = begin; iter != end; iter++) {
		*iter = int((rand() * 1.0 / RAND_MAX) * (max + 1));
	}
}


int main()
{
	using namespace std;
	setlocale(0, "");
	int array[10];
	srand(time(0));
	rand(); //почему то первый ранд всегда возвращает одно и то же значение, этим вызовом делаем первое задаваемое значение менее предсказуемым
	rand_intFill(array, array + 9,10);
	for (int i = 0; i != 9; i++) {
		cout << array[i] << ' ';
	}
	return 0;
}