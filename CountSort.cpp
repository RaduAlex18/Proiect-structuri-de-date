#include <iostream>
#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

int main()
{
	int i, j, n, max, h;
	cin >> n;
	srand(time(0));
	int* array = new int[n];
	for (i = 0; i < n; i++)
		array[i] = rand() % 100000000 + 1000000;
	max = -1;
	auto begin = chrono::high_resolution_clock::now();
	for (i = 0; i < n; i++)
		if (array[i] > max)
			max = array[i];
	int* array_2 = new int[max + 1];
	for (j = 0; j <= max; j++)
		array_2[j] = 0;
	for (i = 0; i < n; i++)
		array_2[array[i]]++;
	auto end = chrono::high_resolution_clock::now();
	auto dur = end - begin;
	auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
	for (j = 0; j <= max; j++)
		for (h = 0; h < array_2[j]; h++)
			cout << j << " ";
	cout << endl;
	cout << "Milisecunde: " << ms << endl;
	return 0;
}