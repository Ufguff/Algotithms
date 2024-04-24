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

    set<string> s10000;

    unordered_set<string> us10000;

    string s;
    string fin;

    int size = 10000;
    
    
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (size / 2 == i) fin = s;
        s.clear();   
    }
    cout << fin << endl;
    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    auto res3 = s10000.find(fin);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    cout << "10000 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << endl;

    std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
    auto res4 = us10000.find(fin);
    std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
    cout << "10000 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3).count() << endl;
    return 0;
}