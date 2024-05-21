#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, v;
    string command;
    cin >> n;

    map<int, int> dict;
    vector<int> vect;

    for (int i = 0; i < nl i++)
    {
        cin >> command >> v;
        switch (command)
        {
        case "add":
            vect.push_back(v);
            dict[v]++;
            break;
        
        case "remove":
            auto iterator = find(vect.begin(), vect.end(), v);
            if (iterator != vect.end() && dict[v] > 0)
            {
                vect.erase(v);
                dict[v]--;
            }
            break;
        }
        
        bool flag = false;
        for (auto& pair : dict)
        {
            if (pair.second > 1)
            {   flag = true; break; }
        }
        
        if (flag)
            cout << "2" << endl;
        else
            cout << "1" << endl;
    }
}