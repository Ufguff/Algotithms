#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
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

    vector<int> indexes(10);
    vector<string> teststrings;
    teststrings.resize(20);

    int cnt = 0, add = size / 10;
    while(cnt < size) {
        indexes.push_back(cnt);
        cnt += add;
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        s100.insert(s);
        us100.insert(s);

        if (find(indexes.begin(), indexes.end(), i) != indexes.end())
            teststrings.push_back(s);
        
        s.clear();   
    }

    for(int i = 10; i < 20; i++)
    {
        for (int i = 0; i < 16; i++)  {s.push_back(char('a' + rand() % ('z' - 'a')));}
        if (find(teststrings.begin(), teststrings.end(), s) != teststrings.end())
            teststrings[i] = (s);
        s.clear();
    }

int sum = 0, sumUn = 0;

for (int i = 0; i < 20; i++){
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto res1 = s100.find(teststrings[i]);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    sum += chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    auto res2 = us100.find(teststrings[i]);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();
    sumUn += chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count();
}

cout << "100 set - " << sum / 20 << endl;
cout << "100 unset - " << sumUn / 20 << endl;

    return 0;
}