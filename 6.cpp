#include <iostream>

using namespace std;

template <typename Key>
struct node {
  Key x; int y;
  node *left=nullptr, *right=nullptr;
  node(Key x, int y) : x(x), y(y) { }
};

int main()
{
    
    return 0;
}
