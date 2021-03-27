/*
	Временная сложность: Временная сложность min_heap — O(Logn). 
	Временная сложность build_minheap() равна O(n), а 
	Общее время работы пирамидальной сортировки — O(nLogn)
	Пирамидальная сортировка алгоритм сортировки, работающий в худшем, в среднем и в 
	лучшем случае за O(n log n) операций при сортировке n элементов.
	Количество применяемой служебной памяти не зависит от размера массива(то есть, O(1)).
*/

#include <iostream>
#include <conio.h>
using namespace std;

/// <summary>
/// Печатаем массив на консоль
/// </summary>
/// <param name="_arr">Ссылка на массив для вывода</param>
/// <param name="_size">Размерность массива</param>
void printArray(int* _arr, int _size)
{
	for (int i = 1; i <= _size; i++)
		cout << _arr[i] << " ";
	cout << "\n";
}

/// <summary>
/// Ввод массива
/// </summary>
/// <param name="_arr">Ссылка на массив</param>
/// <param name="_size">Размерность массива</param>
void inputArray(int* _arr, int _size) {
	for (int i = 1;i <= _size;i++) {
		cout << "arr[" << i << "]:=";
		cin >> _arr[i];
	}
}

/// <summary>
/// Запрашиваем размерность массива дял сортировки
/// </summary>
/// <returns>Возвращает размерность массива</returns>
int inputSize() {
	int _size;
	cout << "Введите размерность массива: ";
	cin >> _size;
	return _size;
}

/// <summary>
/// Основная функция, выполняющая пирамидальную сортировку
/// </summary>
/// <param name="_arr">Ссылка на массив</param>
/// <param name="m>Наименьший элемент</param>
/// <param name="_size>Размерность массива</param>
void min_heap(int* _arr, int m, int n) {
	int j, t;
	t = _arr[m];
	j = 2 * m;
	while (j <= n) {
		if (j < n && _arr[j + 1] < _arr[j])
			j = j + 1;
		if (t < _arr[j])
			break;
		else if (t >= _arr[j]) {
			_arr[j / 2] = _arr[j];
			j = 2 * j;
		}
	}
	_arr[j / 2] = t;
	return;
}

/// <summary>
/// Построение кучи
/// </summary>
/// <param name="_arr">Ссылка на массив</param>
/// <param name="_size>Размерность массива</param>
void build_minheap(int* _arr, int _size) {
	int k;
	for (k = _size / 2; k >= 1; k--) {
		min_heap(_arr, k, _size);
	}
}

/// <summary>
/// Точка входа в программу
/// </summary>
int main() {
	setlocale(LC_ALL, "Russian");
	int size = inputSize();
	int* arr = new int[size + 1];
	inputArray(arr, size);
	cout << "Исходный массив \n";
	printArray(arr, size);
	build_minheap(arr, size);
	cout << "Отсортированный массив \n";
	printArray(arr, size);
	cout << "Добавить новый элемент в массив: ";
	cin >> arr[size + 1];
	cout << "Новый исходный массив \n";
	printArray(arr, size + 1);
	build_minheap(arr, size + 1);
	cout << "Отсортированный массив \n";
	printArray(arr, size + 1);
}
