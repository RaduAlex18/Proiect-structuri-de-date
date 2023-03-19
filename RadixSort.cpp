#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

void CountSort(int* array, int loc, int n)
{
	int count[10];
	int* array_temp = new int[n];
	int j;

	for (j = 0; j < 10; j++)
		count[j] = 0;

	for (int i = 0; i < n; i++)
		count[(array[i] / loc) % 10]++;

	for (j = 1; j < 10; j++)
		count[j] += count[j - 1];

	for (int i = n - 1; i >= 0; i--)
	{
		array_temp[count[(array[i] / loc) % 10] - 1] = array[i];
		count[(array[i] / loc) % 10]--;
	}

	for (int i = 0; i < n; i++)
		array[i] = array_temp[i];
}

void RadixSort(int* array, int maxim, int n)
{
	for (int loc = 1; maxim / loc > 0; loc = loc * 10)
		CountSort(array, loc, n);
}

int main()
{
	int i, maxim = -1;
	int n;
	cin >> n;
	srand(time(0));
	int* array = new int[n];
	for (i = 0; i < n; i++)
		array[i] = rand() % 100000000 + 1000000;

	for (i = 0; i < n; i++)
		if (maxim < array[i])
			maxim = array[i];
	auto begin = chrono::high_resolution_clock::now();
	RadixSort(array, maxim, n);
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	for (i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Milisecunde: " << ms << endl;
}