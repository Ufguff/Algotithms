#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;

// result
/*
sort - 548164300
sort - 23782400
*/

void timSort(vector<int> arr, int n) 
{ 
    // Find the smallest element and place it at the beginning of the array 
    int minimum = arr[0]; 
    int index = 0; 
    for(int i=0; i<n; i++) 
    { 
        if(arr[i] < minimum) 
        { 
            minimum = arr[i]; 
            index = i; 
        } 
    } 
    arr[index] = arr[0]; 
    arr[0] = minimum; 
  
    // Merge the sorted and unsorted parts 
    int mid = 1; 
    for(int i=1; i<n; i++) 
    { 
        int j = i; 
  
        // Move elements of sorted part one step ahead 
        while(j >= mid && arr[j] < arr[j-mid]) 
        { 
            int temp = arr[j]; 
            arr[j] = arr[j-mid]; 
            arr[j-mid] = temp; 
            j--; 
        } 
  
        // Update the size of sorted part 
        if(i == 2*mid-1) 
            mid = 2*mid; 
    } 
} 


//20. Сравните время сортировки с помощью sort и timsort для последовательности из 10^6 случайных чисел. Результаты оформить в виде таблицы.

int main()
{
    int n = 1e6;
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1, n);
    
    vector<int> array1;
    

    for (int i = 0; i < n; i++)
    {
        int t = distribution(generator);
        //cout << t << endl;
        array1.push_back(t);
    }
    
    vector<int> array2 = array1;

    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    sort(array1.begin(), array1.end());
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    cout << "sort - " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << endl;

    chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();
    timSort(array2, n);
    chrono::steady_clock::time_point end1 = chrono::steady_clock::now();
    cout << "sort - " << chrono::duration_cast<chrono::nanoseconds>(end1 - begin1).count() << endl;
}