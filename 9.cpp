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
    set<string> s100;
    set<string> s10000;
    set<string> s10_6;
    set<string> s10_7;

    unordered_set<string> us100;
    unordered_set<string> us10000;
    unordered_set<string> us10_6;
    unordered_set<string> us10_7;
    string s;
    string fin;

    
    
    for (int i = 0; i < 1e7; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (i == 0) {fin = s;} // проверка на все множества
        if (i < 100) {
            s100.insert(s);
            us100.insert(s);
        }
        if (i < 10000) {
            s10000.insert(s);
            us10000.insert(s);
        }
        if (i < 1e6) {
            s10_6.insert(s);
            us10_6.insert(s);
        }
        if (i < 1e7) {
            s10_7.insert(s);
            us10_7.insert(s);
        }
        //fin = s; // проверка на последние множества
        s.clear();
        //cout << i << endl;
        
    }
    cout << s100.size() << endl;
    cout << us100.size() << endl;
    cout << s10000.size() << endl;
    cout << us10000.size() << endl;
    cout << s10_6.size() << endl;
    cout << us10_6.size() << endl;
    cout << s10_7.size() << endl;
    cout << us10_7.size() << endl;
    
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto res1 = s100.find(fin);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "100 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    auto res2 = us100.find(fin);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    cout << "100 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << endl;

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    auto res3 = s10000.find(fin);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    cout << "10000 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << endl;

    std::chrono::steady_clock::time_point begin3 = std::chrono::steady_clock::now();
    auto res4 = us10000.find(fin);
    std::chrono::steady_clock::time_point end3 = std::chrono::steady_clock::now();
    cout << "10000 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end3 - begin3).count() << endl;

    std::chrono::steady_clock::time_point begin4 = std::chrono::steady_clock::now();
    auto res5 = s10_6.find(fin);
    std::chrono::steady_clock::time_point end4 = std::chrono::steady_clock::now();
    cout << "10_6 set - " << chrono::duration_cast<std::chrono::nanoseconds>(end4 - begin4).count() << endl;

    std::chrono::steady_clock::time_point begin5 = std::chrono::steady_clock::now();
    auto res6 = us10_6.find(fin);
    std::chrono::steady_clock::time_point end5 = std::chrono::steady_clock::now();
    cout << "10_6 unset - " << chrono::duration_cast<std::chrono::nanoseconds>(end5 - begin5).count() << endl;

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