#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> tree;
int n;

//откладка
void print()    
{
    for (int i = 0; i < tree.size(); i++)
        cout << tree[i] << " ";
    cout << endl;
}

void treeBuild(int i, int l, int r)
{
    if (r - l == 1)
        tree[i] = tree[l];
    else
    {
        int mid = (l + r) / 2;
        treeBuild(2 * i + 1, l, r);
        treeBuild(2 * i + 2, l, r);
        tree[i] = tree[2 * i + 1] * tree[2 * i + 2];
    }


}

int main()
{
    int t;
    cin >> n;
    if (n % 2 == 0)
        tree.resize(2 * n);
    else
        tree.resize((n + 1) * 2);

    for (int i = 0; i < n; i++)
    {
        cin >> t; 
        tree[tree.size() / 2 + i] = t; 
    }
    int mid = tree.size() / 2;

    treeBuild(0, mid, mid + n - 1);

    print();

    int req_n, l, r, d, p;  cin >> req_n;
    char c;
    for (int i = 0; i < req_n; i++)
    {
        cin >> c;
        switch (c)
        {
        case '+':
            cin >> l >> r >> d;       

            break;
        case '*':
            cin >> l >> r >> d;
            break;
        case '?':
            cin >> p;
            break;
        
        }
    }


}