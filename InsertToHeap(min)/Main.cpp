#include <iostream>
using namespace std;

/// <summary>
/// Чтобы скопировать поддерево с корневым узлом i, индекс в arr []
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="n">Размерность массива</param>
/// <param name="i"></param>
void heapify(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1; // left = 2 * i + 1
	int r = 2 * i + 2; // right = 2 * i + 2
	// Если левый дочерний объект меньше корневого
	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	// Если правильный ребенок меньше самого маленького
	if (r < n && arr[r] < arr[smallest])
		smallest = r;
	// Если наименьшее не является корнем
	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		// Рекурсивно накапливаем поврежденное поддерево
		heapify(arr, n, smallest);
	}
}

/// <summary>
/// Алгоритм сортировки кучи
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="n">Размерность массива</param>
void heapSort(int arr[], int n)
{
	// Строим кучу (переставляем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	// один за другим извлекаем элемент из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Переместить текущий корень в конец
		swap(arr[0], arr[i]);
		// вызвать max heapify для уменьшенной кучи
		heapify(arr, i, 0);
	}
}

/// <summary>
/// Печатаем массив на консоль
/// </summary>
/// <param name="arr">Массив который необходимо вывести</param>
/// <param name="n">Размерность массива</param>
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

/// <summary>
/// Ввод массива
/// </summary>
/// <param name="arr">Массив</param>
/// <param name="n">Размерность массива</param>
void inputArray(int arr[], int n) {

	for (int i = 0;i < n;i++) {
		cout << "arr[" << i << "]:=";
		cin >> arr[i];
	}
}

/// <summary>
/// Запрашиваем размерность массива дял сортировки
/// </summary>
/// <returns>Возвращает размерность массива</returns>
int inputSize() {
	int _n;
	cout << "Введите размерность массива: ";
	cin >> _n;
	return _n;
}

/// <summary>
/// Точка входа в программу
/// </summary>
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = inputSize();
	int* arr = new int[];
	inputArray(arr, n);
	heapSort(arr, n);
	cout << "Отсортированный массив \n";
	printArray(arr, n);
}