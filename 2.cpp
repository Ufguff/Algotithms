#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    queue<int> out;
    for (int i = 2; i <= n; i++)
    {
        q.push(i);
    }
    int temp, qNum;
    int cou = 0;

    while (q.size())
    {
        qNum = q.front();
        q.pop();
        cout << qNum << " ";
        
        int count = q.size();

        for (int i = 0; i < count; i++){
            int temp = q.front();
            q.pop();
            if (temp % qNum != 0){
                out.push(temp);
            }
        }
        q.swap(out);
    }
    return 0;
}