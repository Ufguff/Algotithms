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

    set<string> s10_7;

    unordered_set<string> us10_7;
    string s;
    string fin;

    int size = 1e7;
    
     for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (size / 2 == i) fin = s;
        s.clear();   
    }
    cout << fin << endl;
    std::chrono::steady_clock::time_point begin6 = std::chrono::steady_clock::now();
    auto res7 = s10_7.find(fin);
    std::chrono::steady_clock::time_point end6 = std::chrono::steady_clock::now();
    cout << "10_7 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end6 - begin6).count()<< endl;

    std::chrono::steady_clock::time_point begin7 = std::chrono::steady_clock::now();
    auto res8 = us10_7.find(fin);
    std::chrono::steady_clock::time_point end7 = std::chrono::steady_clock::now();
    cout << "10_7 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end7 - begin7).count() << endl;

    return 0;
}