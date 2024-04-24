#include <iostream>

#include <set>
#include <unordered_set>
#include <string>

#include <chrono>

using namespace std;

int main()
{
    srand(time(nullptr));
    set<string> s100;

    unordered_set<string> us100;

    string s;
    string fin;
    int size = 100;
    
    
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (size / 2 == i) fin = s;
        s.clear();   
    }
    cout << fin << endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto res1 = s100.find(fin);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "100 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    auto res2 = us100.find(fin);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    cout << "100 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << endl;

    return 0;
}