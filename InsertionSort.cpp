#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

int main()
{
	int i, j, n, key;
	cin >> n;
	if (n <= 100000) {
		srand(time(0));
		int* array = new int[n];
		for (i = 0; i < n; i++)
			array[i] = rand() % 100000000 + 1000000;
		auto begin = chrono::high_resolution_clock::now();
		for (i = 0; i < n; i++)
		{
			key = array[i];
			for (j = i - 1; j >= 0; j--)
				if (key < array[j])
				{
					array[j + 1] = array[j];
				}
				else break;
			array[j + 1] = key;
		}
		auto end = chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		for (i = 0; i < n; i++)
			cout << array[i] << " ";
		cout << endl;
		cout << "Milisecunde: " << ms << endl;
		return 0;
	}
	else {
		cout << "Sortarea se va misca foarte greu sau nu va rula.";
	}
}