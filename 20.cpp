#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

const int RUN = 32;
const unsigned long long n = 1e6;


void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

void timSort(int arr[], int n)
{
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, std::min((i + RUN - 1), (n - 1)));

    for (int size = RUN; size < n; size = 2 * size)
    {
        for (int left = 0; left < n; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}


//20. Сравните время сортировки с помощью sort и timsort для последовательности из 10^6 случайных чисел. Результаты оформить в виде таблицы.

int main()
{

    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, 1e6);
    
    vector <int> array1(n);
    //vector <int> array2(n);

    int array2[n];

    for (int i = 0; i < n; i++)
    {
        int t = distribution(generator);
        array1[i] = t;
        array2[i] = t;
        
    }
    

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    sort(std::begin(array1), std::end(array1));
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "sort - " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << endl;

    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();
    timSort(array2, n);
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << "timsort - " << chrono::duration_cast<chrono::nanoseconds>(end1 - begin1).count() << endl;


}

/* 10
sort - 87085400
timsort - 132865400

sort - 86106400
timsort - 130018000

sort - 85026200
timsort - 132221900

sort - 89680000
timsort - 125788700

sort - 87824900
timsort - 129843400

sort - 83753800
timsort - 126372500

sort - 85770100
timsort - 128353600

sort - 85902500
timsort - 125700200

sort - 87151200
timsort - 124093000

sort - 86680100
timsort - 126613300
*/