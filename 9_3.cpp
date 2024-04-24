#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

int main()
{
    srand(time(nullptr));

    set<string> s10_6;

    unordered_set<string> us10_6;

    string s;
    string fin;

    int size = 1e6;
    
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (size / 2 == i) fin = s;
        s.clear();   
    }
    cout << fin << endl;
    std::chrono::steady_clock::time_point begin4 = std::chrono::steady_clock::now();
    auto res5 = s10_6.find(fin);
    std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
    cout << "10_6 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4).count() << endl;

    std::chrono::steady_clock::time_point begin5 = std::chrono::steady_clock::now();
    auto res6 = us10_6.find(fin);
    std::chrono::steady_clock::time_point end5 = std::chrono::steady_clock::now();
    cout << "10_6 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5).count() << endl;


    return 0;
}