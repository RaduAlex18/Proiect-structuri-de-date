#include <iostream>
#include <ctime>
#include<cstdlib>
#include<chrono>
using namespace std;

void shellSort(int* array, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main()
{
    int n, i;
    cin >> n;
    srand(time(0));
    int* array = new int[n];
    for (i = 0; i < n; i++)
        array[i] = rand() % 100000000 + 1000000;
    auto begin = chrono::high_resolution_clock::now();
    shellSort(array, n);
    auto end = chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "Milisecunde: " << ms << endl;
}
